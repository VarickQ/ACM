#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define PI 3.1415926535897932384626433832795

struct ball{
	double l,r;
}b[1005];
bool cmp(const ball &a, const ball &b){
	return a.r < b.r;
}
bool kill(ball a, double x){
	if( a.l < a.r ){
		if( a.l <= x && x <= a.r ) return true;
	} else {
		if( a.l <= x || x <= a.r ) return true;
	}
	return false;
}
int main () {
	int T,n,x,y,r;
	scanf ("%d", &T);
	while (T --) {
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i){
			scanf("%d%d%d", &x, &y, &r);
			double tr = atan2((double)y,(double)x);
			double d = sqrt((double)(x*x+y*y));
			double th = asin((double)r/d);
			b[i].l = tr - th;
			if( b[i].l < -PI ) b[i].l += 2.0*PI;
			b[i].r = tr + th;
			if( b[i].r >= PI ) b[i].r -= 2.0*PI;
		}
		sort( b, b+n, cmp );
		int ans = n;
		for(int i=0 ; i < n ; ++i){
			int cnt = 1;
			double last = b[i].r;
			for(int j=(i+1)%n ; j!=i ; j=(j+1)%n){
				if( !kill(b[j],last) ){
					cnt++;
					last = b[j].r;
				}
			}
			ans = min( cnt, ans );
		}
		printf("%d\n", ans);
	}
	return 0;
}