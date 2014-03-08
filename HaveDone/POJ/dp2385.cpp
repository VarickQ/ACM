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
const int N   = 1005;
typedef long long LL;

int a[N],dp[N][50];
//第i分钟，走j次，最多拿几个苹果
int main(){
	int n, m;
	while( scanf("%d%d", &n, &m) != EOF ){
		CLR( dp, 0 );
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &a[i]);
		for(int i=1 ; i <= n ; ++i){
			dp[i][0] = dp[i-1][0]+a[i]%2;
			for(int j=1 ; j <= m ; ++j){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]);
				if( j%2+1 == a[i] ) dp[i][j]++;
			}
		}
		printf("%d\n", dp[n][m]);
	}
    return 0;
}