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
const int N   = 10005;
typedef long long LL;

LL ans;
int c[N],y[N];
int main(){
	int n, s;
	while( scanf("%d%d", &n, &s) != EOF ){
		ans = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%d%d", &c[i], &y[i]);
			if( i ){
				if( c[i] > c[i-1]+s ) ans+=(c[i-1]+s)*y[i];
				else ans += c[i]*y[i];
			} else ans += c[i]*y[i];
		}
		printf("%lld\n", ans);
	}
    return 0;
}