#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
const int M = 5000;
const int N = 105;
//typedef long long ll;

bool vis[N],mark[N];
int n,s,d;
int mat[N][N],pre[N];
void dfs( int u ){
	if( u == d || mark[u] ){//******–¥¥Í¡À
		for( ; u!=s ; u=pre[u] )
			mark[u] = true;
		return ;
	}
	for(int i=0 ; i < n ; ++i){
		if( mat[u][i] && !vis[i] ){
			pre[i] = u;
			vis[i] = true;
			dfs(i);
			vis[i] = false;
		}
	}
}
int main(){
	int m;
	while( scanf("%d%d%d%d", &n, &m, &s, &d) != EOF ){
		memset( mat, 0, sizeof( mat ) );
		int a, b;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &a, &b);
			mat[a][b] = mat[b][a] = 1;
		}

		memset( mark, 0, sizeof( mark ) );
		memset( pre, -1, sizeof( pre ) );
		memset( vis, 0, sizeof( vis ) );
		vis[s] = true;
		dfs( s );

		int ans = 0;
		for(int i=0 ; i < n ; ++i)
			if( !mark[i] && i!=d && i!=s )
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}