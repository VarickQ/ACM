#include <stdlib.h>
#define eps 1e-10
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{
	double x, y;
};

//����cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//graham�㷨˳ʱ�빹��������й��ߵ��͹��,O(nlogn)
point p1,p2;
int graham_cp(const void* a,const void* b)
{
	double ret=xmult(*((point*)a),*((point*)b),p1);
	return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch){
	int i,k=0;
	for (p1=p2=p[0],i=1;i<n;i++)
		if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
			p1=p[k=i];
		else if (p[i].y-p2.y>eps||(zero(p[i].y-p2.y)&&p[i].x>p2.x))
			p2=p[i];
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
		for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])*xmult(ch[s-2],ch[s-3],ch[s-1])<-eps;s--);
}

//����͹���ӿں���,����ԭʼ�㼯��Сn,�㼯p(pԭ��˳�򱻴���!)
//����͹����С,͹���ĵ���convex��
//����maxsizeΪ1�������ߵ�,Ϊ0���������ߵ�,ȱʡΪ1
//����clockwiseΪ1˳ʱ�빹��,Ϊ0��ʱ�빹��,ȱʡΪ1
//������������ɹ��ߵ�ʱ�㷨���ȶ�,�����д�����������д���!
int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
	point* temp=new point[n];
	int s,i;
	_graham(n,p,s,temp);
	convex[0]=temp[0];
	for (n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
		if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
			convex[n++]=temp[i];
	delete []temp;
	return n;
}