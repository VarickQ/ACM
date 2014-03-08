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
#define eps 1e-6
const int N = 305;

struct point{
	double x, y;
}p[N],c;
point rotate(point v,point p,double angle,double scale){
	point ret=p;
	v.x-=p.x,v.y-=p.y;
	p.x=scale*cos(angle);
	p.y=scale*sin(angle);
	ret.x+=v.x*p.x-v.y*p.y;
	ret.y+=v.x*p.y+v.y*p.x;
	return ret;
}
inline double dis(const point &a,const point &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point getPoint(const point &a,const point &b){
	double d = dis( a, b );
	double tha = acos(d/2.0);
	return rotate(a,b,tha,1.0/d);
}
int main(){
	int n;
	while( scanf("%d", &n) && n ){
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		int Max = 1;
		for(int i=0 ; i < n ; ++i)
			for(int j=i+1 ; j < n ; ++j){
				if( dis(p[i],p[j]) > 2.0+eps ) continue;
				c = getPoint(p[i],p[j]);
				int tmp = 0;
				for(int k=0 ; k < n ; ++k){
					if( dis(p[k],c) <= 1.0+eps )
						tmp++;
				}
				if( Max < tmp ) Max = tmp;
			}
		printf("%d\n", Max);
	}
	return 0;
}