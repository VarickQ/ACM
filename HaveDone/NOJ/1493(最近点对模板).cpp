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
const int N = 5010;
const double eps = 1e-8;
const double inf = 1e12;

struct point{
	double x,y;
}a[N];
//最近点对模板
int dd(double x,double y){ return fabs(x-y)<eps;} // x==y
int dy(double x,double y){ return x>y+eps;}   // x>y
int xy(double x,double y){ return x<y-eps;}   //x<y
int dyd(double x,double y){ return x>y-eps;}  //x>=y
int xyd(double x,double y){ return x<y+eps;}  //x<=y
double disp2p(point a,point b){
	return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) );
}
double getmin(double a,double b){
	return xy(a,b) ? a : b;
}
bool cmp(point a,point b){
	if( dd(a.x,b.x) ) return xy(a.y,b.y);
	return xy(a.x,b.x);
}
bool cmpy(point a,point b){
	if( dd(a.y,b.y) ) return xy(a.x,b.x);
	return xy(a.y,b.y);
}
point y[N];
double nearpot(int l,int r,point *p){
	if( l == r ) return inf;
	if( l == r-1 ) return disp2p(p[l],p[r]);
	if( l == r-2 )
		return getmin( getmin(disp2p(p[l],p[l+1]),disp2p(p[l],p[l+2])), disp2p(p[l+1],p[l+2]) );
	int mid = (l+r)>>1;
	double ans = getmin( nearpot(l,mid,p), nearpot(mid+1,r,p) );
	int len = 0;
	for(int i=mid; i>=l && xy(p[mid].x-p[i].x,ans); i--)
		y[len++] = p[i];
	for(int i=mid+1; i<=r && xy(p[i].x-p[mid].x,ans); i++)
		y[len++] = p[i];
	sort(y,y+len,cmpy);
	for(int i=0; i<len-1; i++)
		for(int k=i+1; k<len; k++){
			if( dyd(y[k].y-y[i].y,ans) )
				break;
			ans = getmin(ans,disp2p(y[i],y[k]));
		}
	return ans;
}
double solve(int n,point *p){
	sort( p, p+n, cmp );
	return nearpot(0,n-1,p);
}
int main(){
	int n;
	while( scanf("%d", &n) && n ){
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf", &a[i].x, &a[i].y);
		printf("%.2lf\n", solve(n,a));
	}
	return 0;
}