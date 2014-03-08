#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 1005;
typedef __int64 LL;
const LL MOD   = 1000000009;
const double eps = 1e-8;

int main(){
	int T;
	LL n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%I64d", &n);
		LL i=1, ans1, ans2, cnt=0;
		for( ; i*i <= n ; ++i ) cnt++;
		for( i=n+1 ; cnt ; ++i)
			if( ceil(sqrt(i*1.0))-floor(sqrt(i*1.0)) > eps )
				cnt--;
		ans1 = i-1;

		ans2 = 0;
		for( i=1 ; i*i <= ans1 ; ++i)
			ans2 += (2*i+1)*i;
		i--;
		ans2 -= (2*i+1)*i;
		for(LL j=i*i ; j <= ans1 ; ++j)
			ans2 += (LL)floor(sqrt(j*1.0));
		printf("%I64d %I64d\n", ans1, ans2);
	}
	return 0;
}