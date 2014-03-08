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
const int N = 500;
typedef long long LL;
const LL inf = (1LL<<60);

//dp[i][j],i节点花了j的时间获得的最大价值
int v[N],map[N][N],dp[N][N],n,m;
bool vis[N];
void dfs(int u){
	for(int v=1 ; v <= n ; ++v){
		if( !vis[v] && map[u][v] ){
			vis[v] = true;
			dfs( v );
			for(int j=m ; j >= 0 ; --j) for(int k=0 ; k <= m ; ++k)
				if( j >= k+2*map[u][v] )
				dp[u][j] = max(dp[u][j],dp[u][j-k-2*map[u][v]]+dp[v][k]);
		}
	}
}
int main(){
	int a, b, c, s;
	while( scanf("%d", &n) != EOF ){
		CLR( map, 0 );
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &v[i]);
		for(int i=1 ; i <= n-1 ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			map[a][b] = map[b][a] = c;
		}
		scanf("%d%d", &s, &m);
		for(int i=1 ; i <= n ; ++i)
			for(int j=0 ; j <= m ; ++j)
				dp[i][j] = v[i];
		CLR( vis, 0 );
		vis[s] = true;
		dfs( s );
		printf("%d\n", dp[s][m]);
	}
    return 0;
}