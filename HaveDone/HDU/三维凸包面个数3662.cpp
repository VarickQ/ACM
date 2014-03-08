#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define PI acos(-1.0)
typedef long long LL;
const double EPS = 1e-8;
const int N = 305;
struct Point
{
	double x,y,z;
	Point(){}
	Point(double xx,double yy,double zz):x(xx),y(yy),z(zz){}
	Point operator -(const Point p1){//������֮��
		return Point(x-p1.x,y-p1.y,z-p1.z);
	}
	Point operator *(Point p){//���
		return Point(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
	}
	double operator ^(Point p){//���  
		return (x*p.x+y*p.y+z*p.z);
	}
};
struct CH3D{
	struct face{
		int a,b,c;//��ʾ͹��һ������������ı��
		bool ok;//��ʾ�����Ƿ���������͹���е���
	};
	int n;//��ʼ������ 
	Point P[N];     //��ʼ����
	int num;     //͹���������������
	face F[8*N];  
	int g[N][N]; //͹�������������
	double vlen(Point a){     //��������
		return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
	}

	Point cross(const Point &a, const Point &b, const Point &c){ //��� 
		return Point((b.y-a.y)*(c.z-a.z)-(b.z-a.z)*(c.y-a.y),-((b.x-a.x)*(c.z-a.z)
			-(b.z-a.z)*(c.x-a.x)),(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));
	}
	double area(Point a,Point b,Point c){     //���������*2
		return vlen((b-a)*(c-a));
	}
	double volume(Point a,Point b,Point c,Point d){//�������������*6
		return (b-a)*(c-a)^(d-a);
	}

	double dblcmp(Point &p,face &f)   //��:������ͬ��
	{
		Point m=P[f.b]-P[f.a];
		Point n=P[f.c]-P[f.a];
		Point t=p-P[f.a];
		return (m*n)^t;
	}
	void deal(int p,int a,int b){
		int f=g[a][b];
		face add;
		if(F[f].ok){
			if(dblcmp(P[p],F[f])>EPS)
				dfs(p,f);
			else {
				add.a=b;    
				add.b=a;
				add.c=p;
				add.ok=1;
				g[p][b]=g[a][p]=g[b][a]=num;
				F[num++]=add;
			}
		}
	}

	void dfs(int p,int now){
		F[now].ok=0;
		deal(p,F[now].b,F[now].a);
		deal(p,F[now].c,F[now].b);
		deal(p,F[now].a,F[now].c);
	}

	bool same(int s,int t){
		Point &a=P[F[s].a];
		Point &b=P[F[s].b];
		Point &c=P[F[s].c];
		return fabs(volume(a,b,c,P[F[t].a]))<EPS && fabs(volume(a,b,c,P[F[t].b]))<EPS
			&& fabs(volume(a,b,c,P[F[t].c]))<EPS;
	}

	void solve()   //������ά͹��
	{
		int i,j,tmp;
		face add;
		bool flag=true;
		num=0;
		if(n<4) return;
		for(i=1;i<n;i++)    //�˶���Ϊ�˱�֤ǰ�ĸ��㲻����,���Ա�֤,���ȥ��
		{
			if(vlen(P[0]-P[i])>EPS){
				swap(P[1],P[i]);
				flag=false;
				break;
			}
		}
		if(flag) return;
		flag=true;
		for(i=2;i<n;i++)   //ʹǰ���㲻����
		{
			if(vlen((P[0]-P[1])*(P[1]-P[i]))>EPS){
				swap(P[2],P[i]);
				flag=false;
				break;
			}
		}
		if(flag) return;
		flag = true;
		for(i=3;i<n;i++)  //ʹǰ�ĵ㲻����
		{
			if(fabs((P[0]-P[1])*(P[1]-P[2])^(P[0]-P[i]))>EPS){
				swap(P[3],P[i]);
				flag=false;
				break;
			}
		}
		if(flag) return;
		for(i=0;i<4;i++){
			add.a=(i+1)%4;
			add.b=(i+2)%4;
			add.c=(i+3)%4;
			add.ok=true;
			if(dblcmp(P[i],add)>0)
				swap(add.b,add.c);
			g[add.a][add.b]=g[add.b][add.c]=g[add.c][add.a]=num;
			F[num++]=add;
		}
		for(i=4;i<n;i++){
			for(j=0;j<num;j++){
				if(F[j].ok && dblcmp(P[i],F[j])>EPS){
					dfs(i,j);
					break;
				}
			}
		}
		tmp=num;
		for(i=num=0;i<tmp;i++)
			if(F[i].ok)
				F[num++]=F[i];
	}

	int polygon()   //�������θ���
	{
		int i,j,res,flag;
		for(i=res=0;i<num;i++){
			flag=1;
			for(j=0;j<i;j++)
				if(same(i,j)){
					flag=0;
					break;
				}
				res+=flag;
		}
		return res;
	}
};
CH3D hull;
int main(){
	while( scanf("%d", &hull.n) != EOF ){
		for(int i=0 ; i < hull.n ; ++i)
			scanf("%lf%lf%lf", &hull.P[i].x, &hull.P[i].y, &hull.P[i].z);
		hull.solve();
		int res = hull.polygon();
		printf("%d\n", res);
	}
	return 0;
}