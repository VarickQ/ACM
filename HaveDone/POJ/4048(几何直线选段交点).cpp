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
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)

const int N = 1600;
struct point{double x,y;};
struct line{point a,b;};
point s,tmp;
line a[N],t;
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}
int same_side(point p1,point p2,line l){
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
int dot_online_in(point p,line l){
	return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
//判两线段相交,包括端点和部分重合
int intersect_in(line u,line v){
	if (!dots_inline(u.a,u.b,v.a)||!dots_inline(u.a,u.b,v.b))
		return !same_side(u.a,u.b,v)&&!same_side(v.a,v.b,u);
	return dot_online_in(u.a,v)||dot_online_in(u.b,v)||dot_online_in(v.a,u)||dot_online_in(v.b,u);
}
//矢量V以P为顶点逆时针旋转angle并放大scale倍
point rotate(point v,point p,double angle,double scale){
	point ret=p;
	v.x-=p.x,v.y-=p.y;
	p.x=scale*cos(angle);
	p.y=scale*sin(angle);
	ret.x+=v.x*p.x-v.y*p.y;
	ret.y+=v.x*p.y+v.y*p.x;
	return ret;
}
int main(){
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf%lf%lf",&a[i].a.x,&a[i].a.y,&a[i].b.x,&a[i].b.y);
		scanf("%lf%lf", &s.x, &s.y);
		int num, ans = 0;
		for(int i=0 ; i < n ; ++i){
			num = 0;
			tmp = rotate(a[i].a,s,0.0,10000.0);
			t.a = s; t.b = tmp;
			for(int j=0 ; j < n ; ++j)
				if( intersect_in(t,a[j]) )
					num++;
			if( num > ans ) ans = num;

			num = 0;
			tmp = rotate(a[i].b,s,0.0,10000.0);
			t.a = s; t.b = tmp;
			for(int j=0 ; j < n ; ++j)
				if( intersect_in(t,a[j]) )
					num++;
			if( num > ans ) ans = num;
		}
		printf("%d\n", ans);
	}
	return 0;
}