#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int N   = 1001;
const int MOD = 100000007;
typedef long long LL;

LL dp[N][2*N][2];
//dp[i][j][0] 第i行分成j块时，第i行是分开的
//dp[i][j][1] 。。。是并在一起的。
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int T, n, k;
	dp[1][1][0] = 1;
	dp[1][2][1] = 1;
	for(int i=1 ; i <= 1000 ; ++i)
		dp[i][1][0] = 1;
	for(int i=2 ; i <= 1000 ; ++i){
		for(int j=2 ; j <= 2*i ; ++j){
			dp[i][j][0] = (dp[i-1][j][1]*2+dp[i-1][j-1][1]+dp[i-1][j][0]+dp[i-1][j-1][0])%MOD;
			dp[i][j][1] = (dp[i-1][j][1]+dp[i-1][j-1][1]*2+dp[i-1][j-2][1]
						+dp[i-1][j-1][0]*2+dp[i-1][j-2][0])%MOD;
		}
	}
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &k);
		printf("%lld\n", (dp[n][k][0]+dp[n][k][1])%MOD);
	}
	return 0;
}