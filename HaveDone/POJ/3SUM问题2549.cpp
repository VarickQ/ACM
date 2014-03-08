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
const int N   = 1005;
typedef long long LL;

//http://en.wikipedia.org/wiki/3SUM
LL a[N];
int main(){
	int n;
	while( scanf("%d", &n) && n ){
		for(int i=0 ; i < n ; ++i)
			scanf("%lld", &a[i]);
		if( n < 4 ){
			puts("no solution"); continue;
		}
		sort( a, a+n );
		bool f = false;
		for(int i=n-1 ; i >= 0 ; --i){
			for(int j=0 ; j <= n-3 ; ++j){
				int k = j+1, l = n-1;
				while( k < l ){
					LL tmp = a[j]+a[k]+a[l];
					if(tmp==a[i]&&i!=j&&i!=k&&i!=l){
						printf("%lld\n", a[i]); f=true; break;
					}
					else if( tmp > a[i] ) l--;
					else k++;
				}
				if(f) break;
			}
			if(f) break;
		}
		if(!f) puts("no solution");
	}
	return 0;
}