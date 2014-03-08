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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 1005;
const int inf = 1000000000;
typedef long long LL;

int s[55][N],v[55][N],dp[55][N];
int main(){
	int T, m, n, x;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d", &m, &n, &x);
		for(int i=0 ; i < m ; ++i)
			for(int j=0 ; j < n ; ++j)
				scanf("%d", &s[i][j]);
		for(int i=0 ; i < m ; ++i)
			for(int j=0 ; j < n ; ++j)
				scanf("%d", &v[i][j]);

		for(int i=0 ; i < n ; ++i)
			dp[0][i] = abs(x-s[0][i])+v[0][i];
		for(int i=1 ; i < m ; ++i){
			for(int j=0 ; j < n ; ++j){
				dp[i][j] = inf;
				for(int k=0 ; k < n ; ++k){
					int tmp = dp[i-1][k]+abs(s[i-1][k]-s[i][j])+v[i][j];
					if( tmp < dp[i][j] ) dp[i][j] = tmp;
				}
			}
		}
		int ans = inf;
		for(int i=0 ; i < n ; ++i)
			ans = min(ans,dp[m-1][i]);
		printf("%d\n", ans);
	}
	return 0;
}