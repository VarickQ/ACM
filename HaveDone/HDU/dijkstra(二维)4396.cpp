/*
本题题意为找到至少走K条边的最短路 
算法：二维的dijkstra。 
开个二维数组，储存从起点到当前点走L条边的最短路，数组大小为K×N。 
当L>K时把它并入到走K条边的状态中，最后输出shortest[T][K] 
*/
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
const int N   = 5010;
const int M   = 200010;
const int inf = 2000000000;
typedef __int64 LL;

struct Edge{
	int next,v,c;
}e[M];
int head[N],en,S,T,K,n,m;
void add(int u,int v,int c){
	e[en].v = v;
	e[en].c = c;
	e[en].next = head[u];
	head[u] = en++;
}
int dis[N][55],vis[N][55];
struct Node{
	int v, c, k;
	bool operator < (const Node &a) const{
		return c > a.c;
	}
};
priority_queue<Node> qu;
void dijkstra(){
	Node t,f;
	memset( vis, 0, sizeof( vis ) );
	dis[S][0] = 0;
	while( !qu.empty() ) qu.pop();
	t.v = S; t.c = t.k = 0;
	qu.push(t);
	while( !qu.empty() ){
		t = qu.top(); qu.pop();
		int u = t.v;
		int p = t.k;
		vis[u][p] = 1;
		for(int i=head[u] ; i!=-1 ; i=e[i].next){
			int v = e[i].v;
			int tk = p < K ? p+1 : K;
			if( !vis[v][tk] && dis[v][tk] > dis[u][p]+e[i].c){
				dis[v][tk] = dis[u][p]+e[i].c;
				f.v = v; f.c = dis[v][tk]; f.k = tk;
				qu.push(f);
			}
		}
	}
}
int main(){
	int a,b,c;
	while( scanf("%d%d", &n, &m) != EOF ){
		memset( head, -1, sizeof( head ) );
		en = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			add( a, b, c );
			add( b, a, c );
		}
		scanf("%d%d%d", &S, &T, &K);
		K = K/10+(K%10>0);
		for(int i=1 ; i <= n ; ++i)
			for(int j=0 ; j <= K ; ++j)
				dis[i][j] = inf;
		dijkstra();
		if( dis[T][K] == inf ) printf("-1\n");
		else printf("%d\n", dis[T][K]);
	}
	return 0;
}