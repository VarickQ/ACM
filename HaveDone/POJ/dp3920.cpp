#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 ll;
const int inf = 2000000000;
const int N   = 205;

int a[N],dp[N][N];
int main(){
	int n,s,t;
	while( scanf ("%d", &n) && n ){
		scanf("%d %d", &s, &t);
		memset( a, 0, sizeof( a ) );
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &a[i]);
		for(int i=0 ; i <= n+1 ; ++i){
			for(int j=0 ; j <= n+1 ; ++j)
				dp[i][j] = -inf;
			dp[0][i] = 0;
		}
		for(int i=1 ; i <= s ; ++i)
			dp[1][i] = a[i];
		int pos = 0;
		for(int i=2 ; i <= t ; ++i){
			for(int j=i ; j <= i*s && j <= n+1 ; ++j){
				for(int k=1 ; k <= s ; ++k)
					dp[i][j] = max( dp[i][j], dp[i-1][j-k]+a[j]);
				if( dp[i][n+1] != -inf ) pos = i;
			}
		}

		int ans = -inf;
		for(int i=pos ; i <= t ; ++i)
			if( dp[i][n+1] > ans )
				ans = dp[i][n+1];
		printf("%d\n", ans);
	}
	return 0;
}