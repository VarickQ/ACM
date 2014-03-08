/*
强连通缩点，拓扑排序求从一点能达到的点最多。
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
const int M   = 50050;
const int N   = 1010;
typedef long long LL;

int n, m;
struct Node{
	int v, next;
}e[M],e2[M];
int head[N], en, belong[N], bcnt;
int st[M], top, in[N];
bool vis[M];
int dfn[N], low[N], indx;
int num[N], a[N], b[N];
void addEdge( int u, int v){
	e[en].v = v;
	e[en].next = head[u];
	head[u] = en++;
}
int k2, head2[N];
void add(int u,int v){
	e2[k2].v = v;
	e2[k2].next = head2[u];
	head2[u] = k2++;
}
void init(){
	top = en = indx = bcnt = k2 = 0;
	memset( head, -1, sizeof( head ) );
	memset( head2, -1, sizeof( head2 ) );
	memset( dfn, 0, sizeof( dfn ) );
	memset( low, 0, sizeof( low ) );
	memset( vis, 0, sizeof( vis ) );
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
			b[bcnt] += a[tmp];
		}while(u != tmp);
	}
}
void topsort(){
	memset( num, 0, sizeof( num ) );
	top = 0;
	for(int i=1 ; i <= bcnt ; ++i)
		if( in[i] == 0 ){
			st[top++] = i;
			num[i] = b[i];
		}
	while( top ){
		int u = st[--top];
		for(int i=head2[u] ; i!=-1 ; i=e2[i].next){
			int v = e2[i].v;
			num[v] = max(num[v],num[u]+b[v]);
			if( --in[v] == 0 )
				st[top++] = e2[i].v;
		}
	}
	int ans = 0;
	for(int i=1 ; i <= bcnt ; ++i)
		ans = max( ans, num[i] );
	printf("%d\n", ans);
}
int main(){
	int T, n, m, u, v;
	scanf("%d", &T);
	while( T-- ){
		init();
		scanf("%d%d", &n, &m);
		memset( b, 0, sizeof( b ) );
		memset( in, 0, sizeof( in ) );
		for(int i=1 ; i <= n ; ++i) a[i] = 1;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &u, &v);
			addEdge( u, v );
		}
		for(int i=1 ; i <= n ; ++i)
			if( !dfn[i] ) tarjan(i);
		for(int i=1 ; i <= n ; ++i){
			for(int j=head[i] ; j!=-1 ; j=e[j].next){
				v = e[j].v;
				if( belong[i] != belong[v] ){
					add( belong[i], belong[v] );
					in[belong[v]]++;
				}
			}
		}
		topsort();
	}
	return 0;
}