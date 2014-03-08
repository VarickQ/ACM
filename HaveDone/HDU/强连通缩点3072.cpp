/*
给你n个点,m条边。属于同一个强连通块里面的点之间边的权值可以当做0，要是连通块间的距离和最小。
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
const int inf = 1000000000;
const int M   = 100010;
const int N   = 50010;
typedef long long LL;

int n, m;
struct Node{
	int c, v, next;
}e[M];
int head[N], en, belong[N], bcnt;
int st[M], top, ans[N];
bool vis[M];
int dfn[N], low[N], indx;
void addEdge( int u, int v, int c ){
	e[en].v = v;
	e[en].c = c;
	e[en].next = head[u];
	head[u] = en++;
}
void tarjan(int u){
	dfn[u] = low[u] = ++indx;
	vis[u] = true;
	st[top++] = u;
	for(int i=head[u] ; i!=-1 ; i=e[i].next){
		if( !dfn[e[i].v] ){
			tarjan(e[i].v);
			if( low[u] > low[e[i].v] )
				low[u] = low[e[i].v];
		}
		else if( vis[e[i].v] && dfn[e[i].v] < low[u] )
			low[u] = dfn[e[i].v];
	}
	if( dfn[u] == low[u] ){
		bcnt++;
		int tmp;
		do{
			tmp = st[--top];
			vis[tmp] = false;
			belong[tmp] = bcnt;
		}while(u != tmp);
	}
}
int main(){
	int a, b, l;
	while( scanf("%d%d", &n, &m) != EOF ){
		top = en = indx = bcnt = 0;
		memset( head, -1, sizeof( head ) );
		memset( dfn, 0, sizeof( dfn ) );
		memset( low, 0, sizeof( low ) );
		memset( vis, 0, sizeof( vis ) );
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &l);
			addEdge( a+1, b+1, l );
		}
		for(int i=1 ; i <= n ; ++i)
			if( !dfn[i] ) tarjan(i);
		memset( ans, -1, sizeof( ans ) );
		for(int i=1 ; i <= n ; ++i)
			for(int j=head[i] ; j!=-1 ; j=e[j].next)
				if( belong[i] != belong[e[j].v] )
					if( ans[belong[e[j].v]]==-1 || ans[belong[e[j].v]]>e[j].c)//!!
						ans[belong[e[j].v]] =  e[j].c;
		int res = 0;
		for(int i=1 ; i <= bcnt ; ++i)
			if( ans[i] != -1 )
				res += ans[i];
		printf("%d\n", res);
	}
	return 0;
}