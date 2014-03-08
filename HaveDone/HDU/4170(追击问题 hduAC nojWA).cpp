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
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 10;
typedef long long LL;

struct A{
	double x,y,vx,vy;
}h[N],a,b;
double gettime(A u, A v){
	double a = v.vx*v.vx+v.vy*v.vy-u.vx*u.vx+0.0;
	double b = 2.0*(v.vx*(v.x-u.x)+v.vy*(v.y-u.y));
	double c = 1.0*(v.x-u.x)*(v.x-u.x)+1.0*(v.y-u.y)*(v.y-u.y);
	if( fabs(a) < eps ) return -c/b;
	if( a+eps < 0.0 ) a=-a,b=-b,c=-c;
	return (-b+sqrt(b*b-4*a*c))/(2*a);
}
int res[3];
void getans(double t){
	res[0] = (int)t;
	t -= res[0]+0.0;
	res[1] = (int)(t*=60.0);
	t -= res[1]+0.0;
	res[2] = (int)(t*60.0+0.99999999);
	if( res[2] == 60 ) res[2]=0,res[1]++;
	if( res[1] == 60 ) res[1]=0,res[0]++;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\Qian\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\Qian\\Desktop\\out.txt","w",stdout);
#endif
////////////////////////////////////////
	int n,p[N],cs = 1;
	while( scanf("%d", &n) && n ){
		for(int i=1 ; i <= n ; ++i){
			p[i] = i;
			scanf("%lf%lf%lf%lf", &h[i].x, &h[i].y, &h[i].vx, &h[i].vy);
		}
		scanf("%lf%lf%lf", &h[0].x, &h[0].y, &h[0].vx);
		a.vx = h[0].vx;
		double t,ans = 1e9;
		do{
			t = gettime( h[0], h[p[1]] )+1.0;
			for(int i=2 ; i <= n ; ++i){
				a.x = h[p[i-1]].x+t*h[p[i-1]].vx;
				a.y = h[p[i-1]].y+t*h[p[i-1]].vy;
				b = h[p[i]];
				b.x = h[p[i]].x+t*h[p[i]].vx;
				b.y = h[p[i]].y+t*h[p[i]].vy;
				t += gettime( a, b )+1.0;
			}
			b = h[p[n]];
			b.x = h[p[n]].x+t*h[p[n]].vx;
			b.y = h[p[n]].y+t*h[p[n]].vy;
			t += sqrt((b.x-h[0].x)*(b.x-h[0].x)*1.0+(b.y-h[0].y)*(b.y-h[0].y)*1.0)/h[0].vx;
			if( t < ans ) ans = t;
		}while( next_permutation(p+1,p+n+1) );
		getans(ans);
		printf("Case %d: %d hour(s) %d minute(s) %d second(s)\n",cs++,res[0],res[1],res[2]);
	}
	return 0;
}