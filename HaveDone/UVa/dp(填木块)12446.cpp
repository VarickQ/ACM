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
const int inf = 1000000000;
const int N = 1000005;
const int MOD = 1000000007;
typedef long long ll;

ll dp[N][2];
int main(){
	int T,n;
	dp[1][0] = 2;
	dp[2][0] = 9;
	dp[1][1] = 4;
	dp[2][1] = 12;
	for(int i=3 ; i <= 1000000 ; ++i)
	{
		//dp[i][0]第i层放平的种数
		//dp[i][1]第i层有凸起的种数
		dp[i][0] = (dp[i-1][0]*2+dp[i-2][0]+dp[i-1][1])%MOD;
		dp[i][1] = (dp[i-1][0]*4+dp[i-1][1])%MOD;
	}
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		printf("%lld\n", dp[n][0]);
	}
	return 0;
}