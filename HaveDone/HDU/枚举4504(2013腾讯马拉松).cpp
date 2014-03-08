#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef __int64 LL;

int main(){
	LL a, b, t;
	LL f[25];
	f[0] = 1;
	f[1] = 1;
	for(int i=2 ; i <= 20 ; ++i)
		f[i] = f[i-1] * i;
	while( scanf("%I64d%I64d%I64d", &a, &b, &t) != EOF ){
		t /= 15;
		b += t / 2;
		t = (t + 1) / 2;
		LL ans = 0;
		for(LL i=0 ; i <= t ; ++i){
			for(LL j=0 ; i+j <= t ; ++j){
				if( 3*i+2*j+t-i-j+a > b )
					ans += f[t]/(f[i]*f[j]*f[t-i-j]);
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}