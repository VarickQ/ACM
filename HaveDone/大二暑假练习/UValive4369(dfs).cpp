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
typedef long long LL;

LL n,s,e,r;
int main(){
	while( scanf("%lld%lld%lld%lld",&n,&r,&s,&e) != EOF ){
		if( n==-1 && r==-1 && s==-1 && e==-1 ) break;
		if( n==0 ){
			printf("1\n"); continue;
		}
		int ans = 0;
		for(LL i=s ; i <= e ; ++i){
			LL m = n, t = 0, c = i, x = r;
			while( m != 0 ) {
				LL mid = (1LL<<m)>>1LL;
				m--;
				if( x >= mid ){
					x -= mid;
					if( c >= mid ){
						c -= mid;
						t++;
					}
				} else {
					if( c >= mid ) c -= mid;
				}
			}
			ans += t&1?(-1):(1);
		}
		printf("%d\n", ans);
	}
	return 0;
}