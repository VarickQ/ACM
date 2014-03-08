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
const int M   = 200010;
const int N   = 5010;
typedef long long LL;
const double g = 9.8;

struct Node{
	int c, v, next;
}e[M];
int head[N], en, c, d, ans;
bool vis[N];
void add(int u,int v,int c){
	e[en].c = c;
	e[en].v = v;
	e[en].next = head[u];
	head[u] = en++;
}
void dfs(int u,int val){
	if( u == d ){
		ans = val; return;
	}
	for(int i=head[u] ; i!=-1 ; i=e[i].next){
		int v = e[i].v;
		if( !vis[v] ){
			vis[v] = true;
			if( u <= v ) dfs( v, val+e[i].c );
			if( u > v ) dfs( v, val-e[i].c );
			if( ans >= 0 ) return;
			//vis[v] = false;
		}
	}
}
int main(){
	int n, m, k, a, b, s;
	while( scanf("%d%d%d", &n, &m, &k) != EOF ){
		en = 0;
		memset( head, -1, sizeof( head ) );
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &s);
			add( a-1, b, s );
			add( b, a-1, s );
		}
		for(int i=0 ; i < k ; ++i){
			scanf("%d%d", &c, &d);
			c--;
			memset( vis, 0, sizeof( vis ) );
			vis[c] = true;
			ans = -1;
			dfs( c, 0 );
			if( ans == -1 ) puts("UNKNOWN");
			else printf("%d\n", ans);
		}
		puts("");
	}
	return 0;
}