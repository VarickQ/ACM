#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 45005;
typedef long long LL;
#define eps 1e-8
#define PI acos(-1.0)

struct point{double x,y;};
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool dd(point a,point b){
	if( fabs(a.x-b.x)<=eps && fabs(a.y-b.y)<=eps ) return true;
	return false;
}
int main(){
	point a,b,c,d;
	double r1,r2,ans;
	while( scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&r1,&b.x,&b.y,&r2)!=EOF ){
		double tmp = dis(a,b);
		if( r1+r2 <= tmp )//相离||外切
			printf("0.000\n");
		else if( fabs(r1-r2) >= tmp )//内切||内含
			printf("%.3lf\n", min(PI*r1*r1,PI*r2*r2));
		else {//相交
			double phi1 = acos((r2*r2+tmp*tmp-r1*r1)/(2*r2*tmp));
			double phi2 = acos((r1*r1+tmp*tmp-r2*r2)/(2*r1*tmp));
			double s = (r1+r2+tmp)/2;
			s = sqrt(s*(s-r1)*(s-r2)*(s-tmp));
			ans = phi1*r2*r2+phi2*r1*r1-2*s;
			printf("%.3lf\n", ans);
		}
	}
	return 0;
}