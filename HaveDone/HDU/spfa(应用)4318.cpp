#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
typedef long long LL;
const int N   = 50005;
const int M   = 2500005;
const int inf = 1000000000;

struct Node{
	int v, next, val;
}e[M];
int head[N],ne,n,m;
double dis[N],ans[N];
void init(){
	ne = 0; CLR( head, -1 );
}
void addedge(int u,int v,int c){
	e[ne].val = c;
	e[ne].v = v;
	e[ne].next = head[u];
	head[u] = ne++;
}
queue<int> qu;
void spfa(int s){
	int i;
	for( i=0 ; i <= n ; ++i ) dis[i] = inf;
	dis[s] = 0;
	qu.push(s);
	while( !qu.empty() ){
		int u = qu.front(); qu.pop();
		for( i=head[u] ; i!=-1 ; i=e[i].next ){
			int v = e[i].v;
			if( dis[v] > dis[u]+e[i].val/100.0*ans[u] ){
				dis[v] = dis[u]+e[i].val/100.0*ans[u];
				ans[v] = ans[u]-e[i].val/100.0*ans[u];
				qu.push(v);
			}
		}
	}
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int v, c;
	while( scanf("%d", &n) != EOF ){
		init();
		while( !qu.empty() ) qu.pop();
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &m);
			while( m-- ){
				scanf("%d%d", &v, &c);
				addedge( i, v, c );
			}
		}
		int s, t;
		scanf("%d%d%d", &s, &t, &m);
		if( s == t ){
			printf("0.00\n"); continue;
		}
		CLR( ans, 0 );
		ans[s] = m;
		spfa(s);
		if( dis[t] >= inf ) puts("IMPOSSIBLE!");
		else printf("%.2lf\n", dis[t]);
	}
    return 0;
}