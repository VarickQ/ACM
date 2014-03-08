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
const int inf = 100000000;
const int M   = 10005;
const int N   = 505;
typedef long long LL;

int t[M];
struct Node{
	int v, next, c;
}e[M*2];
int head[N], en, n, m;
void init(){
	en = 0;
	memset( head, -1, sizeof( head ) );
	memset( t, 0, sizeof( t ) );
}
void add(int u, int v, int c ){
	e[en].c = c;
	e[en].v = v;
	e[en].next = head[u];
	head[u] = en++;
}
int d1[N], d2[N], d3[N], qu[M];
bool vis[N];
void spfa(int s, int dis[] ){
	int i, h=0, t=1;
	memset( vis, false, sizeof( vis ) );
	for( i=0 ; i <= m ; ++i ) dis[i] = inf;
	dis[s] = 0;
	qu[0] = s;
	while( t > h ){
		int u = qu[h];
		vis[u] = true;
		for( i=head[u] ; i!=-1 ; i=e[i].next ){
			int v = e[i].v;
			if( dis[v] > dis[u] + e[i].c ){
				dis[v] = dis[u] + e[i].c;
				if( !vis[v] ){
					vis[v] = true;
					qu[t++] = v;
				}
			}
		}
		vis[u] = false;
		h++;
	}
}
int main(){
	int l, q, cs = 1;
	int a, b, c;
	while( scanf("%d%d%d", &n, &m, &l) != EOF ){
		init();
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &t[i]);
		for(int i=0 ; i < l ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			add( a, b, c );
			add( b, a, c );
		}
		printf("Case #%d\n", cs++);
		scanf("%d", &q);
		for(int L=1 ; L <= q ; L++){
			scanf("%d%d%d", &a, &b, &c);
			spfa( t[a], d1 );
			spfa( t[b], d2 );
			spfa( t[c], d3 );
			int tmp, ans = inf;
			for(int i=1 ; i <= m ; ++i){
				tmp = d1[i] + d2[i] + d3[i];
				if( tmp < ans ) ans = tmp;
			}
			printf("Line %d: ", L);
			if( ans >= inf )
				printf("Impossible to connect!\n");
			else
				printf("The minimum cost for this line is %d.\n", ans);
		}
	}
	return 0;
}