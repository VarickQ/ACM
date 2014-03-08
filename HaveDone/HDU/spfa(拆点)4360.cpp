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
const int N   = 15000;
const int M   = 13550;
typedef __int64 LL;
const LL inf = 1LL<<62;

struct Node{
	LL l;
	int v, next;
}e[M*10];
int en,head[N],n,m,len[N];
void addedge(int u,int v,LL c){
	e[en].l = c;
	e[en].v = v;
	e[en].next = head[u];
	head[u] = en++;
}
bool vis[N];
queue<int> qu;
LL dis[N];
void spfa(){
	int i;
	memset( vis, false, sizeof( vis ) );
	for(int i=0 ; i <= n*4 ; ++i) dis[i] = inf;
	dis[1] = 0;
	len[1] = 0;
	qu.push(1);
	while( !qu.empty() ){
		int u = qu.front(); qu.pop();
		for(i=head[u] ; i!=-1 ; i=e[i].next){
			int v=e[i].v;
			if(dis[v] > dis[u]+e[i].l){
				dis[v] = dis[u]+e[i].l;
				len[v] = len[u]+1;
				qu.push(v);
			}
			else if( dis[v]==dis[u]+e[i].l && len[v]<len[u]+1 ){
				len[v] = len[u]+1;
				qu.push(v);
			}
			if( v==n && len[v] < 4 ){
				dis[v] = dis[u]+e[i].l;
				len[v] = len[u]+1;
			}
		}
	}
}
int main(){
	int T, cs=1;
	char s[5];
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		en = 0;
		memset( head, -1, sizeof( head ) );
		while( !qu.empty() ) qu.pop();
		int u,v; LL l;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%I64d%s", &u, &v, &l, s);
			if( s[0] == 'L' ){
				addedge( u, v+n, l );
				addedge( v, u+n, l );
			} else if( s[0] == 'O' ){
				addedge( u+n, v+2*n, l );
				addedge( v+n, u+2*n, l );
			} else if( s[0] == 'V' ){
				addedge( u+2*n, v+3*n, l );
				addedge( v+2*n, u+3*n, l );
			} else if( s[0] == 'E' ){
				addedge( u+3*n, v, l );
				addedge( v+3*n, u, l );
			}
		}
		spfa();
		if( dis[n]!=inf && len[n]>=4 )
			printf("Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",cs++,dis[n],len[n]/4);
		else printf("Case %d: Binbin you disappoint Sangsang again, damn it!\n", cs++);
	}
	return 0;
}