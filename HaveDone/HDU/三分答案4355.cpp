#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <time.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 50005;
typedef __int64 LL;
#define eps 1e-8

struct A{
	double s,w;
}a[N];
int n;
inline double gao(double p){
	double s,res = 0;
	for(int i=0 ; i < n ; ++i){
		s = fabs(a[i].s-p);
		res += s*s*s*a[i].w;
	}
	return res;
}
int main(){
	int T, cs = 1;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf", &a[i].s, &a[i].w);
		double l = a[0].s, r = a[n-1].s;
		int t = 25;//!!!
		while( t-- ){
			double mid = (l+r)/2;
			double mmid = (mid+r)/2;
			if( gao(mmid) > gao(mid) )
				r = mmid;
			else l = mid;
		}
		printf("Case #%d: %.0lf\n", cs++, gao(l));
	}
	return 0;
}