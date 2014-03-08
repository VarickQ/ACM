/*
有n个男人，n个女人。男人喜欢女人，输入n行表示第i个男人喜欢哪几个女人，最后一行n个数，表示第i个女人一定会和第i个男人结婚。问每个男人可以选择哪几个女人而不和其他的男人冲突。

强连通，在同一个强连通块中的女人就是男人可以选择的。
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
const int M   = 400010;
const int N   = 401000;
typedef long long LL;

int n, m;
struct Node{
	int v, next;
}e[M];
int head[N], en, belong[N], bcnt;
int st[M], top, ans[N];
bool vis[N];
int dfn[N], low[N], indx;
void addEdge( int u, int v ){
	e[en].v = v;
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
void init(){
	top = en = indx = bcnt = 0;
	memset( head, -1, sizeof( head ) );
	memset( dfn, 0, sizeof( dfn ) );
	memset( low, 0, sizeof( low ) );
	memset( vis, 0, sizeof( vis ) );
}
int main(){
	int n, a, b;
	while( scanf("%d", &n) != EOF ){
		init();
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &a);
			for(int j=0 ; j < a ; ++j){
				scanf("%d", &b);
				addEdge( i, b+n );
			}
		}
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &a);
			addEdge( a+n, i );
		}
		for(int i=1 ; i <= 2*n ; ++i)
			if( !dfn[i] ) tarjan(i);

		for(int i=1 ; i <= n ; ++i){
			int c = 0;
			for(int j=head[i] ; j!=-1 ; j=e[j].next)
				if( belong[i] == belong[e[j].v] )
					ans[c++] = e[j].v-n;
			sort( ans, ans+c );
			printf("%d", c);
			for(int i=0 ; i < c ; ++i)
				printf(" %d", ans[i]);
			puts("");
		}
	}
	return 0;
}