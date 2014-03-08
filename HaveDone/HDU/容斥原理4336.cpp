#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
const int N = 50;

double p[N],sp[N];
int main(){
	int n;
	while( scanf("%d", &n) != EOF ){

		memset( sp, 0, sizeof( sp ) );
		for(int i=0 ; i < n ; ++i)
			scanf("%lf", &p[i]);

		for(int i=1 ; i < (1<<n) ; ++i){
			int cnt = 0;
			double tmp = 0;
			for(int j=0 ; j < n ; ++j){
				if( i&(1<<j) ){
					cnt++;
					tmp += p[j];
				}
			}
			sp[cnt] += 1.0/tmp;
		}

		double ans = 0;
		for(int i=1 ; i <= n ; ++i){
			if( i&1 ) ans += sp[i];
			else ans -= sp[i];
		}

		printf("%lf\n", ans);
	}
	return 0;
}