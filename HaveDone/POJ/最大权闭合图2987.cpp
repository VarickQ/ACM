//Accepted	2576K	329MS	C++	2624B
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
typedef long long LL;
const LL inf = (1LL<<60);
const int N = 20010;
const int M = 250010;

struct Edge{
	int from, to, next;
	LL val;
}e[M];
int w[N],que[N],dis[N],ne,cur[N];
void add( int from, int to, LL va ){
	e[ne].from = from;
	e[ne].to = to;
	e[ne].val = va;
	e[ne].next = w[from];
	w[from] = ne++;

	e[ne].from = to;
	e[ne].to = from;
	e[ne].val = 0;
	e[ne].next = w[to];
	w[to] = ne++;
}
int bfs( int n, int s, int t ){
	int head, tail, id;
	head = tail = 0;
	que[tail++] = s;
	memset( dis, -1, sizeof( int )*n );
	dis[s] = 0;
	while( head < tail ){
		for( id=w[que[head++]] ; id!=-1 ; id=e[id].next ){
			if( e[id].val>0 && dis[e[id].to]==-1 ){
				dis[e[id].to] = dis[e[id].from]+1;
				que[tail++] = e[id].to;
				if( e[id].to == t ) return 1;
			}
		}
	}
	return 0;
}
LL Dinic( int n, int s, int t ){
	LL Mflow=0, tmp, i;
	while( bfs( n, s, t ) ){
		int u = s, tail = 0;
		for( i=0 ; i < n ; ++i ) cur[i] = w[i];
		while( cur[s]!=-1 ){
			if(u!=t&&cur[u]!=-1&&e[cur[u]].val>0&&dis[u]!=-1&&dis[u]+1==dis[e[cur[u]].to]){
				que[tail++] = cur[u];
				u = e[cur[u]].to;
			}
			else if( u == t ){
				for( tmp=inf,i=tail-1 ; i >= 0 ; --i )
					tmp = min( tmp, e[que[i]].val );
				for( Mflow+=tmp,i=tail-1 ; i >=0 ; --i ){
					e[que[i]].val -= tmp;
					e[que[i]^1].val += tmp;
					if( e[que[i]].val==0 ) tail = i;
				}
				u = e[que[tail]].from;
			} else {
				while(tail>0&&u!=s&&cur[u]==-1)
					u = e[que[--tail]].from;
				cur[u] = e[cur[u]].next;
			}
		}
	}
	return Mflow;
}
bool vis[N];
int num;
void dfs(int u){
	for(int i=w[u] ; i!=-1 ; i=e[i].next){
		if( !vis[e[i].to] && e[i].val ){
			vis[e[i].to] = true;
			dfs(e[i].to);
		}
	}
}
int n, m;
int main(){
	while( scanf("%d%d", &n, &m) != EOF ){
		memset( w, -1, sizeof( w ) );
		ne = 0;
		LL a,sum = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%lld", &a);
			if( a >= 0 ){
				add( 0, i, a );
				sum += a;
			}
			else add( i, n+1, -a );
		}
		int u, v;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &u, &v);
			add( u, v, inf );
		}
		sum -= Dinic( n+2, 0, n+1 );
		memset( vis, 0, sizeof( vis ) );
		num = 0;
		dfs(0);
		for(int i=1 ; i <= n ; ++i) if(vis[i]) num++;
		printf("%d %lld\n", num, sum);
	}
	return 0;
}
/*
	Accepted	2556K	782MS	C++	2460B
int main(){
	while( scanf("%d%d", &n, &m) != EOF ){
		memset( w, -1, sizeof( w ) );
		ne = 0;
		LL a,sum = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%lld", &a);
			a = a*10000-1;
			if( a >= 0 ){
				add( 0, i, a );//放大流量
				sum += a;
			}
			else add( i, n+1, -a );
		}
		int u, v;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &u, &v);
			add( u, v, inf );
		}
		sum -= Dinic( n+2, 0, n+1 );
		int num = -(sum%10000-10000)%10000;//因为方大过流量，直接算出解雇人数
		sum = (sum+num)/10000;//根据人数得到受益
		printf("%d %lld\n", num, sum);
	}
	return 0;
}
*/