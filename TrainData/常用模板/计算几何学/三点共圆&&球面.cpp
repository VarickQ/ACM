struct point{
	double x,y;
};
struct line{
	point a,b;
};

//计算两直线交点
point intersection(line u,line v)
{
	point ret=u.a;
	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
			/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x+=(u.b.x-u.a.x)*t;
	ret.y+=(u.b.y-u.a.y)*t;
	return ret;
}

//构造p1,p2中垂线
line pline(point p1,point p2)
{
	line ret;
	ret.a.x=(p1.x+p2.x)/2;
	ret.a.y=(p1.y+p2.y)/2;
	ret.b.x=ret.a.x-p1.y+p2.y;
	ret.b.y=ret.a.y+p1.x-p2.x;
	return ret;
}

//过三点圆的圆心,一定要保证三点不共线!
inline point circle(point a,point b,point c)
{
	return intersection(pline(a,b),pline(b,c));
}


////////////////////////////////////////////////////////
#include <math.h>
const double pi=acos(-1);

//计算圆心角lat表示纬度,-90<=w<=90,lng表示经度
//返回两点所在大圆劣弧对应圆心角,0<=angle<=pi
double angle(double lng1,double lat1,double lng2,double lat2)
{
	double dlng=fabs(lng1-lng2)*pi/180;
	while (dlng>=pi+pi)
		dlng-=pi+pi;
	if (dlng>pi)
		dlng=pi+pi-dlng;
	lat1*=pi/180,lat2*=pi/180;
	return acos(cos(lat1)*cos(lat2)*cos(dlng)+sin(lat1)*sin(lat2));
}

//计算距离,r为球半径
double line_dist(double r,double lng1,double lat1,double lng2,double lat2)
{
	double dlng=fabs(lng1-lng2)*pi/180;
	while (dlng>=pi+pi)
		dlng-=pi+pi;
	if (dlng>pi)
		dlng=pi+pi-dlng;
	lat1*=pi/180,lat2*=pi/180;
	return r*sqrt(2-2*(cos(lat1)*cos(lat2)*cos(dlng)+sin(lat1)*sin(lat2)));
}

//计算球面距离,r为球半径
inline double sphere_dist(double r,double lng1,double lat1,double lng2,double lat2)
{
	return r*angle(lng1,lat1,lng2,lat2);
}