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
#define abs(x) ((x)>0?(x):-(x))
typedef long long LL;
#define eps 1e-8
#define inf 1<<30
const int N = 105;

struct point{
	double x, y;
}a[N], t;
int n;
struct line{point a,b;};
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
point intersection(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
			/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
double ans;
bool judge(point p1,point p2,int pos){
	int i, ind;
	for( i=0 ; i < n ; ++i ){
		if( xmult(p2,a[i],p1) < -eps ){
			ind = 1; break;
		}
		if( xmult(p2,a[i+n],p1) > eps ){
			ind = 2; break;
		}
	}
	if(i == n) return true;
	if(i < pos) return false;
	point t;
	if( ind == 1 )
		t = intersection(p1,p2,a[i-1],a[i]);
	else t = intersection(p1,p2,a[i-1+n],a[i+n]);
	ans = max( ans, t.x );
	return false;
}
int main(){
	while( scanf("%d", &n) && n ){
		for(int i=0 ; i < n ; ++i){
			scanf("%lf%lf", &a[i].x, &a[i].y);
			a[n+i].x = a[i].x;
			a[n+i].y = a[i].y-1;
		}
		ans = -inf;
		bool ok = false;
		for(int i=0 ; i < n ; ++i){
			if( ok ) break;
			for(int j=i+1 ; j < n ; ++j){
				if( judge(a[i],a[j+n],j) ){
					ok = true; break;
				}
				if( judge(a[i+n],a[j],j) ){
					ok = true; break;
				}
			}
		}
		if( ok ) puts("Through all the pipe.");
		else printf("%.2lf\n", ans);
	}
	return 0;
}