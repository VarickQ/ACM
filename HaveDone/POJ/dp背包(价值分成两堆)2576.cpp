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
const int N   = 45005;
typedef long long LL;

int a[101];
bool mark[N], dp[101][N];
//mark[i]表示体重和为i是否可达
//dp[i][j]表示i个人可以达到j的体重
int main(){
	int n, sum;
	while( scanf("%d", &n) != EOF ){
		memset( mark, 0, sizeof( mark ) );
		memset( dp, 0, sizeof( dp ) );
		sum = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		mark[0] = mark[sum] = true;
		dp[0][0] = true;
		for(int i=1 ; i <= n ; ++i)
			for(int j=sum ; j >= a[i] ; --j)
				if( mark[j-a[i]] ){
					mark[j] = true;
					for(int k=0 ; k < n ; ++k)
						if( dp[k][j-a[i]] )
							dp[k+1][j] = true;
				}
		int ans,tmp = 10000000;
		for(int i=0 ; i <= sum ; ++i)
			if( mark[i] && (dp[n/2][i]||dp[n-n/2][i]) )
				if( abs(sum-2*i) < tmp ){
					tmp = abs(sum-2*i);
					ans = min( sum-i, i );
				}
		printf("%d %d\n", ans, sum-ans);
	}
	return 0;
}