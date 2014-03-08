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
//����cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//�����㹲��
int dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}
//���������߶�ͬ��,�����߶��Ϸ���0
int same_side(point p1,point p2,line l){
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
//�е��Ƿ����߶���,�����˵�
int dot_online_in(point p,line l){
	return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
//�����߶��ཻ,�����˵�Ͳ����غ�
int intersect_in(line u,line v){
	if (!dots_inline(u.a,u.b,v.a)||!dots_inline(u.a,u.b,v.b))
		return !same_side(u.a,u.b,v)&&!same_side(v.a,v.b,u);
	return dot_online_in(u.a,v)||dot_online_in(u.b,v)||dot_online_in(v.a,u)||dot_online_in(v.b,u);
}
//���������߶����,�����߶��Ϸ���0
int opposite_side(point p1,point p2,line l){
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)<-eps;
}
//�����߶��ཻ,�������˵�Ͳ����غ�
int intersect_ex(line u,line v){
	return opposite_side(u.a,u.b,v)&&opposite_side(v.a,v.b,u);
}
//����ֱ��ƽ��
int parallel(line u,line v){
	return zero((u.a.x-u.b.x)*(v.a.y-v.b.y)-(v.a.x-v.b.x)*(u.a.y-u.b.y));
}
//������ֱ�߽���,ע�������ж�ֱ���Ƿ�ƽ��!
//�߶ν������������߶��ཻ(ͬʱ����Ҫ�ж��Ƿ�ƽ��!)
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