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
const int N = 1005;
typedef long long LL;

struct Node{
	int v, c, next;
}e[N*100];
int en, head[N], n;
void add(int u, int v,int c){
	e[en].v = v;
	e[en].c = c;
	e[en].next = head[u];
	head[u] = en++;
}
int d[N], qu[N*100], cnt[N];
bool vis[N];
int spfa(){
	for(int i=0 ; i <= n ; ++i) d[i] = -inf;
	memset( vis, 0, sizeof( vis ) );
	d[0] = 0;
	int h = 0, t = 1;
	qu[0] = 0;
	while( h < t ){
		int u = qu[h++];
		vis[u] = true;
		for(int i=head[u] ; i!=-1 ; i=e[i].next){
			int v = e[i].v;
			if( d[v] < d[u] + e[i].c ){
				d[v] = d[u] + e[i].c;
				if( !vis[v] ){
					qu[t++] = v;
					vis[v] = true;
					if( ++cnt[v]>=n ) return -1;//ÅÐ¸º»·
				}
			}
		}
		vis[u] = false;
	}
	return d[n];
}
int main(){
	int m, c, a, b;
	while( scanf("%d%d", &n, &m) != EOF ) {
		memset( cnt, 0, sizeof( cnt ) );
		memset( head, -1, sizeof( head ) );
		en = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &c);
			add( i, i-1, -c );//Si - Si-1 <= c
		}
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			add( a-1, b, c );//Sb - Sa-1 >= c
		}
		for(int i=1 ; i <= n ; ++i)
			add( i-1, i, 0 );//Si - Si-1 >= 0
		int ans = spfa();
		if( ans==-1 || ans==-inf ) puts("Bad Estimations");
		else printf("%d\n", ans);
	}
	return 0;
}