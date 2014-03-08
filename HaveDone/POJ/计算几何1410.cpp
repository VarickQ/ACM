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