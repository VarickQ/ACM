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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long LL;
//方法一：
//LL get(LL n){
//	return 4*n*(n+1);
//}
//LL gao(LL n){
//	if( n < 0 ) return 0;
//	LL tmp,l = 0, r = 1518500249, mid;//r只有为1518500249才能AC
//	while( l <= r ){
//		mid = (l+r)/2;
//		if( get(mid)-1 < n ){
//			tmp = mid;
//			l = mid+1;
//		} else r = mid-1;
//	}
//	n = n-get(tmp)+1;
//	tmp++;
//	LL p = tmp*tmp*2-tmp;
//	if( n <= tmp*4 ) return p;
//	else return p + n - tmp*4;
//}
//方法二：
LL fuck(LL n){
	if( n < 0 ) return 0;
	LL x = (LL)sqrt(n+0.0);
	if( x&1 ) return x*(x+1)/2;
	else return n+1-x*(x+1)/2;
}
int main(){
	LL a, b;
	while( scanf("%lld%lld", &a, &b) != EOF ){
		printf("%lld\n", fuck(b)-fuck(a-1));
	}
    return 0;
}