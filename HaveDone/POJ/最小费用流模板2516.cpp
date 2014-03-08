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
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 150000;
const int N   = 150;
typedef long long LL;

int n, m, k, a[N][N], b[N][N];
int out[N], in[N];
// 最小费用流 模板（链表）
// 用法： init(), addedge(u,v,sap,cost), MCMF(S,T,n)
const int MAXN = 150;
const int MAXM = 150000;
const int INF = 1000000000;
struct Edge
{
	int u, v, cap, cost;
	int next;
}edge[MAXM<<2];

int NE;
int head[MAXN], dist[MAXN], pp[MAXN];
bool vis[MAXN];
void init()
{
	NE = 0;
	memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int cap, int cost)
{
	edge[NE].u = u; edge[NE].v = v; edge[NE].cap = cap; edge[NE].cost = cost;
	edge[NE].next = head[u]; head[u] = NE++;
	edge[NE].u = v; edge[NE].v = u; edge[NE].cap = 0; edge[NE].cost = -cost;
	edge[NE].next = head[v]; head[v] = NE++;
}
bool SPFA(int s, int t, int n)
{
	int i, u, v;
	int top = 0, tail = 0;
	int qu[MAXN<<6];    // 队列长度为点的64倍
	memset(vis,false,sizeof(vis));
	memset(pp,-1,sizeof(pp));
	for(i = 0; i <= n; i++) dist[i] = INF;
	vis[s] = true; dist[s] = 0;
	qu[++tail] = s;
	while (top < tail)
	{
		u = qu[++top];
		vis[u] = false;
		for(i = head[u]; i != -1; i = edge[i].next)
		{
			v = edge[i].v;
			if(edge[i].cap && dist[v] > dist[u] + edge[i].cost)
			{
				dist[v] = dist[u] + edge[i].cost;
				pp[v] = i;
				if(!vis[v])
				{
					qu[++tail] = v;
					vis[v] = true;
				}
			}
		}
	}
	if(dist[t] == INF) return false;
	return true;
}
int MCMF(int s, int t, int n) // minCostMaxFlow 0 开始
{
	int flow = 0; // 总流量
	int i, minflow, mincost;
	mincost = 0;
	while(SPFA(s, t, n))
	{
		minflow = INF + 1;
		for(i = pp[t]; i != -1; i = pp[edge[i].u])
			if(edge[i].cap < minflow)
				minflow = edge[i].cap;
		flow += minflow;
		for(i = pp[t]; i != -1; i = pp[edge[i].u])
		{
			edge[i].cap -= minflow;
			edge[i^1].cap += minflow;
		}
		mincost += dist[t] * minflow;
	}
	return mincost;
}
int main(){
	int c;
	while( scanf("%d%d%d", &n, &m, &k) != EOF ){
		if( n+m+k == 0 ) break;
		memset( in, 0, sizeof( in ) );
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= k ; ++j){
				scanf("%d", &a[i][j]);
				in[j] += a[i][j];
			}
		memset( out, 0, sizeof( out ) );
		for(int i=1 ; i <= m ; ++i)
			for(int j=1 ; j <= k ; ++j){
				scanf("%d", &b[i][j]);
				out[j] += b[i][j];
			}
		bool f = false;
		for(int i=1 ; i <= k ; ++i)
			if( in[i] > out[i] ){
				f = true; break;
			}
		int s = 0, t = n+m+1, ans = 0;
		for(int i=1 ; i <= k ; ++i){
			init();
			for(int j=1 ; j <= n ; ++j)
				for(int p=1 ; p <= m ; ++p){
					scanf("%d", &c);
					addedge( p, j+m, inf, c );
				}
			if( f ) continue;
			for(int j=1 ; j <= m ; ++j)
				addedge( s, j, b[j][i], 0 );
			for(int j=1 ; j <= n ; ++j)
				addedge( j+m, t, a[j][i], 0 );
			ans += MCMF( s, t, t+1 );
		}
		if( f ) puts("-1");
		else printf("%d\n", ans);
	}
	return 0;
}