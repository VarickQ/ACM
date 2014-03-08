#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long LL;

LL L(LL x){
	LL a = 0;
	while(x){
		a++;
		x /= 10;
	}
	return a;
}
LL Pow(LL x){
	LL res = 1;
	for(LL i=0 ; i < x ; ++i)
		res *= 10;
	return res;
}
LL ten[15];
int main(){
	for(LL i=1 ; i <= 12 ; ++i)
		ten[i] = Pow(i);
	LL n,m;
	while( scanf("%lld%lld", &n, &m) != EOF ){
		LL tmp = ten[L(m)];
		LL now = tmp;
		LL t = 1, ans = 0;
		while( now >= n ){
			if( now <= m && now%5==0){
				//printf("%d***\n", now);
				ans ++;
			}
			if( now == 1 ) break;
			t *= 2;
			if( t == 16 ){
				t = 1;
				tmp /= 10;
				now = tmp;
			}
			else now = tmp/t;
		}
		if( n == 1 ) ans++;
		tmp = 2;
		for(LL i=0 ; tmp<=m ; ++i){
			if( tmp>=n ) ans++;
			tmp *= 10;
		}
		printf("%lld\n", ans);
	}
    return 0;
}
