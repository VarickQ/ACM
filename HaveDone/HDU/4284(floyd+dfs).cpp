#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
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
typedef __int64 LL;
const int N = 110;
const int M = 5010;
const int inf = 1000000000;

int n,m,c,h;
int cost[N][N];
struct Node{
	int id,ci,di;
}a[N];
bool f, vis[N];
void dfs(int u,int have,int c){
	if( f ) return;
	if( have == h ){
		if( c-cost[u][1] >= 0)
			f = true;
		return ;
	}
	for(int i=0 ; i < h ; ++i){
		int t,v = a[i].id;
		if( !vis[v] && c-cost[u][v]-a[i].di>=0 ){
			vis[v] = true;
			t = c-cost[u][v]-a[i].di+a[i].ci;
			if( t >= 0 )
				dfs( v, have+1, t );
			if(f) return;
			vis[v] = false;
		}
	}
}
int main(){
	int T, u, v, w;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d", &n, &m, &c);
		for(int i=0 ; i <= n ; ++i){
			for(int j=0 ; j <= n ; ++j)
				cost[i][j] = inf;
			cost[i][i] = 0;
		}
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &u, &v, &w);
			if( cost[u][v] > w )
				cost[u][v] = cost[v][u] = w;
		}
		for(int k=1 ; k <= n ; ++k)
			for(int i=1 ; i <= n ; ++i)
				for(int j=1 ; j <= n ; ++j)
					if( cost[i][j]>cost[i][k]+cost[k][j] )
						cost[i][j]=cost[i][k]+cost[k][j];
		scanf("%d", &h);
		for(int i=0 ; i < h ; ++i)
			scanf("%d%d%d", &a[i].id, &a[i].ci, &a[i].di);
		f = false;
		memset( vis, 0, sizeof( vis ) );
		dfs( 1, 0, c );
		if( f ) puts("YES");
		else puts("NO");
	}
	return 0;
}