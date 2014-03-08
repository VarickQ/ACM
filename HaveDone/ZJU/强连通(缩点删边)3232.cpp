/*
给定一个矩阵，求最少用多少条边可以达到矩阵给出的这个状态。

根据矩阵建边，用强连通缩点，同一个联通块里面最多边就是成环，重新根据联通块个数建边，利用floyd将边删除，最后加上必要的边，即可。
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
const int N   = 205;
typedef long long LL;

int n, mat[N][N];
struct Node{
	int v, next;
}e[M];
int head[N], en, belong[N], bcnt;
int st[M], top, cnt[N];
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
			cnt[bcnt]++;
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
	int a;
	while( scanf("%d", &n) != EOF ){
		init();
		memset( cnt, 0, sizeof( cnt ) );
		memset( mat, 0, sizeof( mat ) );
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j){
				scanf("%d", &a);
				if( a==1 && i!=j ) addEdge(i,j);
			}
		for(int i=1 ; i <= n ; ++i)
			if( !dfn[i] ) tarjan(i);

		int ans = 0;
		for(int i=1 ; i <= bcnt ; ++i)//同一个联通块成环用边最少
			if( cnt[i] > 1 ) ans += cnt[i];
		for(int i=1 ; i <= n ; ++i)
			for(int j=head[i] ; j!=-1 ; j=e[j].next)
				mat[belong[i]][belong[e[j].v]] = 1;
		for(int k=1 ; k <= bcnt ; ++k)
			for(int i=1 ; i <= bcnt ; ++i){
				if( i == k ) continue;
				for(int j=1 ; j <= bcnt ; ++j)
					if( k!=j && i!=j && mat[i][k] && mat[k][j] && mat[i][j] )
						mat[i][j] = 0;
			}
		for(int i=1 ; i <= bcnt ; ++i)
			for(int j=1 ; j <= bcnt ; ++j)
				if( i != j )
					ans += mat[i][j];
		printf("%d\n", ans);
	}
	return 0;
}