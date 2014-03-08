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
#define Lowbit(x) ((x)&(-x))
const int N = 200005;
typedef long long LL;

LL a,b,c,k;
LL exGcd(LL a,LL b,LL &x,LL &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    LL d = exGcd( b, a%b, x, y );
    LL temp = x;
    x = y;
    y = temp - (a/b) * y;
    return d;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	LL x, y, MOD;
	while( scanf("%lld%lld%lld%lld",&a,&b,&c,&k) && (a+b+c+k) ){
		MOD = (1LL << k);
		LL d = exGcd( c, MOD, x, y);
		LL K = (b-a+MOD)%MOD;
		if( K%d != 0 ) puts("FOREVER");
		else {
			x = K/d*x;
			MOD = MOD/d;
			x = (x%MOD+MOD)%MOD;
			printf("%lld\n", x);
		}
	}
	return 0;
}