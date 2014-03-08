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
const int N   = 10010;
typedef long long LL;

struct Node{
	int v, next;
}e[M];
int head[N], k, n, m;
int in[N], out[N], belong[N], bcnt;
int st[M], top;
bool inst[M];
int dfn[N], low[N], indx;

void addedge(int u,int v){
	e[k].v = v;
	e[k].next = head[u];
	head[u] = k++;
}
void tarjan(int u){
	dfn[u] = low[u] = ++indx;
	inst[u] = true;
	st[top++] = u;
	for(int i=head[u] ; i!=-1 ; i=e[i].next){
		if( !dfn[e[i].v] ){
			tarjan(e[i].v);
			if( low[u] > low[e[i].v] )
				low[u] = low[e[i].v];
		}
		else if( inst[e[i].v] && dfn[e[i].v] < low[u] )
			low[u] = dfn[e[i].v];
	}
	if( dfn[u] == low[u] ){
		bcnt++;
		int tmp;
		do{
			tmp = st[--top];
			inst[tmp] = false;
			belong[tmp] = bcnt;
		}while( u != tmp );
	}
}
int main(){
	int u, v;
	while( scanf("%d%d", &n, &m) && (n+m) ){
		k = bcnt = top = indx = 0;
		memset( dfn, 0, sizeof( dfn ) );
		memset( low, 0, sizeof( low ) );
		memset( inst, 0, sizeof( inst ) );
		memset( head, -1, sizeof( head ) );
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &u, &v);
			addedge( u, v );
		}
		for(int i=1 ; i <= n ; ++i)
			if( !dfn[i] ) tarjan(i);
		if( bcnt == 1 ) puts("Yes");
		else puts("No");
	}
	return 0;
}