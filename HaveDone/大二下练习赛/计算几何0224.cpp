//1001
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 ll;
const int inf = 1000000000;
const int N   = 1005;
const double eps = 1e-8;
#define zero(x) (((x)>0?(x):-(x))<eps)

struct point{double x,y;};
struct line{point a,b;};

line l,a[5];
//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//判三点共线
int dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}
//判两点在线段同侧,点在线段上返回0
int same_side(point p1,point p2,line l){
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
//判点是否在线段上,包括端点
int dot_online_in(point p,line l){
	return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
//判两线段相交,包括端点和部分重合
int intersect_in(line u,line v){
	if (!dots_inline(u.a,u.b,v.a)||!dots_inline(u.a,u.b,v.b))
		return !same_side(u.a,u.b,v)&&!same_side(v.a,v.b,u);
	return dot_online_in(u.a,v)||dot_online_in(u.b,v)||dot_online_in(v.a,u)||dot_online_in(v.b,u);
}
int main(){
	int T;
	double x1,y1,x2,y2;
	scanf("%d", &T);
	while( T-- ){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&l.a.x,&l.a.y,&l.b.x,&l.b.y,&x1,&y1,&x2,&y2);
		double temp = x1 + x2;
		x1 = min( x1, x2 );
		x2 = temp - x1;
		temp = y1 + y2;
		y1 = max( y1, y2 );
		y2 = temp - y1;

		a[0].a.x=x1; a[0].a.y=y1; a[0].b.x=x2; a[0].b.y=y1;
		a[1].a.x=x2; a[1].a.y=y1; a[1].b.x=x2; a[1].b.y=y2;
		a[2].a.x=x2; a[2].a.y=y2; a[2].b.x=x1; a[2].b.y=y2;
		a[3].a.x=x1; a[3].a.y=y2; a[3].b.x=x1; a[3].b.y=y1;

		bool f = false;
		for(int i=0 ; i < 4 ; ++i){
			if( intersect_in( l, a[i] ) ){
				f = true; break;
			}
		}
		if( !f ){
			bool ff = false;
			for(int i=0 ; i < 4 ; ++i)
				if( !same_side( l.a, a[(i+1)%4].b, a[i] ) 
					|| !same_side( l.b, a[(i+1)%4].b, a[i] ) ){
					ff = true; break;
				}
			if( !ff ) f = true;
		}
		if( f ) printf("T\n");
		else printf("F\n");
	}
	return 0;
}
//1002
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define PI 3.141592653589793
#include <stdlib.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{int x,y;};

point a[1200],b[1200];

//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//graham算法顺时针构造包含所有共线点的凸包,O(nlogn)
point p1,p2;
int graham_cp(const void* a,const void* b){
	double ret=xmult(*((point*)a),*((point*)b),p1);
	return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch){
	int i,k=0;
	for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
		if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
			p1=p[k=i];
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
		for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}

//构造凸包接口函数,传入原始点集大小n,点集p(p原有顺序被打乱!)
//返回凸包大小,凸包的点在convex中
//参数maxsize为1包含共线点,为0不包含共线点,缺省为1
//参数clockwise为1顺时针构造,为0逆时针构造,缺省为1
//在输入仅有若干共线点时算法不稳定,可能有此类情况请另行处理!
//不能去掉点集中重合的点
int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
	point* temp=new point[n];
	int s,i;
	_graham(n,p,s,temp);
	for (convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
		if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
			convex[n++]=temp[i];
	delete []temp;
	return n;
}

int main()
{
	int n=0,g;
	while(scanf("%d %d",&a[n].x,&a[n].y) == 2){n++;}
	g = graham(n,a,b,0,0);
	int t;
	for(int i=0 ; i < g ; i++)
		if(b[i].x==0 && b[i].y==0)t=i;
	for(int i=t ; i < g ; i++)
		printf("(%d,%d)\n",b[i].x,b[i].y);
	for(int i=0 ; i < t ; i++)
		printf("(%d,%d)\n",b[i].x,b[i].y);
	return 0;
}
//1007
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define PI 3.141592653589793
#include <stdlib.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};

point a[1200],b[1200];
//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//graham算法顺时针构造包含所有共线点的凸包,O(nlogn)
point p1,p2;
int graham_cp(const void* a,const void* b){
	double ret=xmult(*((point*)a),*((point*)b),p1);
	return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch){
	int i,k=0;
	for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
		if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
			p1=p[k=i];
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
		for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}

//构造凸包接口函数,传入原始点集大小n,点集p(p原有顺序被打乱!)
//返回凸包大小,凸包的点在convex中
//参数maxsize为1包含共线点,为0不包含共线点,缺省为1
//参数clockwise为1顺时针构造,为0逆时针构造,缺省为1
//在输入仅有若干共线点时算法不稳定,可能有此类情况请另行处理!
//不能去掉点集中重合的点
int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
	point* temp=new point[n];
	int s,i;
	_graham(n,p,s,temp);
	for (convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
		if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
			convex[n++]=temp[i];
	delete []temp;
	return n;
}

int main()
{
	int n;
	while( scanf("%d", &n) != EOF ){
		memset( a, 0, sizeof( a ) );
		memset( b, 0, sizeof( b ) );
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf", &a[i].x, &a[i].y);
		int g = graham( n, a, b, 0, 0 );
		double area = 0;
		for(int i=1 ; i < g-1 ; ++i)
			area += xmult( b[0], b[i], b[i+1] );
		area = fabs( area/100 );
		printf("%d\n", (int)area);
	}
	return 0;
}
//1006
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#include <stdlib.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};

point a[2100],b[2100];
//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//graham算法顺时针构造包含所有共线点的凸包,O(nlogn)
point p1,p2;
int graham_cp(const void* a,const void* b){
	double ret=xmult(*((point*)a),*((point*)b),p1);
	return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch){
	int i,k=0;
	for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
		if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
			p1=p[k=i];
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
		for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}

//构造凸包接口函数,传入原始点集大小n,点集p(p原有顺序被打乱!)
//返回凸包大小,凸包的点在convex中
//参数maxsize为1包含共线点,为0不包含共线点,缺省为1
//参数clockwise为1顺时针构造,为0逆时针构造,缺省为1
//在输入仅有若干共线点时算法不稳定,可能有此类情况请另行处理!
//不能去掉点集中重合的点
int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
	point* temp=new point[n];
	int s,i;
	_graham(n,p,s,temp);
	for (convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
		if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
			convex[n++]=temp[i];
	delete []temp;
	return n;
}
int dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}
int main()
{
	int T,n,g;
	scanf("%d", &T);
	while( T-- ){
		memset( a, 0, sizeof( a ) );
		memset( b, 0, sizeof( b ) );
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf", &a[i].x, &a[i].y);
		if( n <= 5 ){
			printf("NO\n"); continue;
		}
		bool f = false;
		for(int i=2 ; i < n ; ++i)
			if( !dots_inline(a[i-2],a[i-1],a[i]) )
				f = true;
		if( !f ){
			printf("NO\n"); continue;
		}
		g = graham( n, a, b, 0, 0 );
		
		f = false;
		for(int i=0 ; i < g-1 ; ++i){
			int num=0;
			for(int j=0 ; j < n ; ++j)
				if( dots_inline(a[j],b[i],b[i+1]) )
					num++;
			if( num < 3 ){
				f = true; break;
			}
		}
		if( f )	printf("NO\n");
		else {
			int num = 0;
			for(int j=0 ; j < n ; ++j)
				if( dots_inline(a[j],b[0],b[g-1]) )
					num++;
			if( num >= 3 ) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
//1003 pojAC
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define PI 3.141592653589793
#include <stdlib.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};
struct line{point a,b;};

line j,k;
//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//判三点共线
int dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}
//判两点在线段同侧,点在线段上返回0
int same_side(point p1,point p2,line l){
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
//判点是否在线段上,包括端点
int dot_online_in(point p,line l){
	return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
//判两线段相交,包括端点和部分重合
int intersect_in(line u,line v){
	if (!dots_inline(u.a,u.b,v.a)||!dots_inline(u.a,u.b,v.b))
		return !same_side(u.a,u.b,v)&&!same_side(v.a,v.b,u);
	return dot_online_in(u.a,v)||dot_online_in(u.b,v)||dot_online_in(v.a,u)||dot_online_in(v.b,u);
}
//判两点在线段异侧,点在线段上返回0
int opposite_side(point p1,point p2,line l){
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)<-eps;
}
//判两线段相交,不包括端点和部分重合
int intersect_ex(line u,line v){
	return opposite_side(u.a,u.b,v)&&opposite_side(v.a,v.b,u);
}
//判两直线平行
int parallel(line u,line v){
	return zero((u.a.x-u.b.x)*(v.a.y-v.b.y)-(v.a.x-v.b.x)*(u.a.y-u.b.y));
}
//计算两直线交点,注意事先判断直线是否平行!
//线段交点请另外判线段相交(同时还是要判断是否平行!)
point intersection(line u,line v){
	point ret=u.a;
	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
			/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x+=(u.b.x-u.a.x)*t;
	ret.y+=(u.b.y-u.a.y)*t;
	return ret;
}
bool same( point a, point b){
	if(a.x == b.x && a.y == b.y)
		return true;
	return false;
}
int main()
{
	int T;
	scanf("%d", &T);
	printf("INTERSECTING LINES OUTPUT\n");
	while( T-- ){
		scanf("%lf%lf%lf%lf",&j.a.x,&j.a.y,&j.b.x,&j.b.y);
		scanf("%lf%lf%lf%lf",&k.a.x,&k.a.y,&k.b.x,&k.b.y);
		if( parallel( j, k ) ){
			if( dots_inline( j.a, j.b, k.a ) )
				printf("LINE\n");
			else printf("NONE\n");
		} else {
			point res = intersection( j, k );
			printf("POINT %.2lf %.2lf\n",res.x,res.y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
