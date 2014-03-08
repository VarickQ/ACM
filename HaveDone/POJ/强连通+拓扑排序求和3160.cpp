/*
强连通缩点，拓扑排序求能达到的最大和。
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
const int M   = 150010;
const int N   = 30010;
typedef long long LL;

int n, m;
struct Node{
	int v, next;
}e[M],e2[M];
int head[N], en, belong[N], bcnt;
int st[M], top, in[N];
bool vis[M];
int dfn[N], low[N], indx;
int a[N], b[N], num[N];
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
	memset( st, 0, sizeof( st ) );
	top = 0;
	for(int i=1 ; i <= bcnt ; ++i)
		if( in[i] == 0 ){
			st[top++] = i;
			num[i] = b[i];
		}
	while( top ){
		int u = st[--top];
		for(int i=head2[u] ; i!=-1 ; i=e2[i].next){
			num[e2[i].v] = max(num[e2[i].v],num[u]+b[e2[i].v]);
			if( --in[e2[i].v] == 0 )
				st[top++] = e2[i].v;
		}
	}
}
int main(){
	int n, m, u, v;
	while( scanf("%d%d", &n, &m) != EOF ){
		memset( b, 0, sizeof( b ) );
		memset( in, 0, sizeof( in ) );
		init();
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &a[i]);
			if( a[i] < 0 ) a[i] = 0;
		}
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &u, &v);
			addEdge( u+1, v+1 );
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
		int ans = 0;
		for(int i=1 ; i <= bcnt ; ++i)
			ans = max(ans,num[i]);
		printf("%d\n", ans);
	}
	return 0;
}