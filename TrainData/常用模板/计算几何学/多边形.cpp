#include <stdlib.h>
#define offset 10000
#define eps 1e-10
#define zero(x) (((x)>0?(x):-(x))<eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
struct point{double x,y;};

//����cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

//�ж�͹�����,���㰴˳ʱ�����ʱ�����,�������ڱ߹���
int is_convex(int n,point* p)
{
	int i,s[3]={1,1,1};
	for (i=0;i<n&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%n],p[(i+2)%n],p[i]))]=0;
	return s[1]|s[2];
}

//�ж�͹�����,���㰴˳ʱ�����ʱ�����,���������ڱ߹���
int is_convex_v2(int n,point* p)
{
	int i,s[3]={1,1,1};
	for (i=0;i<n&&s[0]&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%n],p[(i+2)%n],p[i]))]=0;
	return s[0]&&s[1]|s[2];
}

//�е���͹������ڻ����α���,���㰴˳ʱ�����ʱ�����
int inside_convex(point q,int n,point* p)
{
	int i,s[3]={1,1,1};
	for (i=0;i<n&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
	return s[1]|s[2];
}

//�е���͹�������,���㰴˳ʱ�����ʱ�����,�ڶ���α��Ϸ���0
int inside_convex_v2(point q,int n,point* p)
{
	int i,s[3]={1,1,1};
	for (i=0;i<n&&s[0]&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
	return s[0]&&s[1]|s[2];
}

//�е�������������,���㰴˳ʱ�����ʱ�����
//on_edge��ʾ���ڶ���α���ʱ�ķ���ֵ,offsetΪ�������������
int inside_polygon(point q,int n,point* p,int on_edge=1)
{
	point q2;
	int i=0,count;
	while (i<n)
		for (count=i=0,q2.x=rand()+offset,q2.y=rand()+offset;i<n;i++)
			if (zero(xmult(q,p[i],p[(i+1)%n]))&&(p[i].x-q.x)*(p[(i+1)%n].x-q.x)<eps
				&&(p[i].y-q.y)*(p[(i+1)%n].y-q.y)<eps)
				return on_edge;
			else if (zero(xmult(q,q2,p[i])))
				break;
			else if (xmult(q,p[i],q2)*xmult(q,p[(i+1)%n],q2)<-eps
				&&xmult(p[i],q,p[(i+1)%n])*xmult(p[i],q2,p[(i+1)%n])<-eps)
				count++;
	return count&1;
}