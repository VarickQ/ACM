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
#define EPS 1e-6
const int N = 50005;

struct A{
	int b,h,w,d;
}a[N];
int main(){
	int T, n, v;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		double l=0,r=0,mid,M=0,now;
		for(int i=0 ; i < n ; ++i){
			scanf("%d%d%d%d", &a[i].b, &a[i].h, &a[i].w, &a[i].d);
			if( a[i].b+a[i].h+1.0 > r )
				r = a[i].b+a[i].h+1.0;
			M += a[i].d*a[i].w*a[i].h;
		}
		scanf("%d", &v);
		if( v > M ){
			puts("OVERFLOW"); continue;
		}
		int lim = 100;
		while( lim-- ){
			mid = (l+r)/2.0;
			now = 0;
			for(int i=0 ; i < n ; ++i){
				if( mid > a[i].b*1.0 ){
					double t = min((mid-a[i].b),a[i].h);
					now += t*a[i].w*a[i].d;
				}
			}
			if( v > now ) l = mid;
			else r = mid;
		}
		printf("%.2lf\n", mid);
	}
	return 0;
}