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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N = 155;

int n, ans[N];
bool map[N][N], vis[N], f;
void dfs(int u,int cnt){
	ans[cnt] = u;
	if( f ) return ;
	if( cnt == n ){
		if( map[u][1] ){
			 f = true; return;
		}
	}
	for(int v=1 ; v <= n ; ++v){
		if( f ) break;
		if( map[u][v] && !vis[v] ){
			vis[v] = true;
			dfs( v, cnt+1 );
			vis[v] = false;
		}
	}
}
int main(){
	int m;
	while( scanf("%d%d", &n, &m) != EOF ){
		int a, b;
		memset( map, 0, sizeof( map ) );
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &a, &b);
			map[a][b] = map[b][a] = 1;
		}
		f = false;
		memset( vis, 0, sizeof( vis ) );
		vis[1] = true;
		dfs( 1, 1 );
		if( f ){
			for(int i=1 ; i <= n ; ++i){
				if(i==n)printf("%d\n", ans[i]);
				else printf("%d ", ans[i]);
			}
		} else puts("no solution");
	}
	return 0;
}