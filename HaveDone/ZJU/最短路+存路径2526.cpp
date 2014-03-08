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
const int inf = 1000000000;
const int M   = 250010;
const int N   = 505;
typedef long long LL;


bool vis[N];
int val[N], dis[N], cost[N], psum[N], pre[N], ans[N];
int n, m, rm1, rm2, mat[N][N];
void dijkstra(){
	memset( vis, 0, sizeof( vis ) );
	for(int i=0 ; i < n ; i++)dis[i] = inf;
	dis[rm1] = 0;
	for(int i=0 ; i < n ; i++)
	{
		int x,Min = inf;
		for(int y=0 ; y < n ; y++)
			if(!vis[y] && dis[y] <= Min){
				Min = dis[y];
				x = y;
			}
		vis[x] = true;
		for(int y=0 ; y < n ; y++)
			if(!vis[y] && dis[x]+mat[x][y] < dis[y])
				dis[y] = dis[x] + mat[x][y];
	}
}
void dijkstra2(){
	memset( vis, 0, sizeof( vis ) );
	memset( cost, 0, sizeof( cost ) );
	memset( psum, 0, sizeof( psum ) );
	pre[rm1] = -1;
	psum[rm1] = 1;
	cost[rm1] = val[rm1];
	for(int i=0 ; i < n ; i++)
	{
		int x,Min = inf;
		for(int y=0 ; y < n ; y++)
			if(!vis[y] && dis[y] <= Min){
				Min = dis[y];
				x = y;
			}
		vis[x] = true;
		for(int y=0 ; y < n ; y++)
			if(!vis[y] && dis[x]+mat[x][y] == dis[y]){
				psum[y] += psum[x];
				if( cost[y] < cost[x]+val[y] ){
					cost[y] = cost[x]+val[y];
					pre[y] = x;
				}
			}
	}
}
int main(){
	int u, v, l;
	while( scanf("%d%d%d%d",&n,&m,&rm1,&rm2) != EOF ){
		memset( pre, -1, sizeof( pre ) );
		for(int i=0 ; i < n ; ++i)
			for(int j=0 ; j < n ; ++j)
				mat[i][j] = inf;
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &val[i]);
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &u, &v, &l);
			if( l < mat[u][v] )
				mat[u][v] = mat[v][u] = l;
		}
		dijkstra();
		dijkstra2();
		printf("%d %d\n", psum[rm2], cost[rm2]);
		int cnt = 0;
		for(int i=rm2 ; i!=-1 ; i=pre[i])
			ans[cnt++] = i;
		for(int i=cnt-1 ; i > 0 ; --i)
			printf("%d ", ans[i]);
		printf("%d\n", ans[0]);
	}
	return 0;
}