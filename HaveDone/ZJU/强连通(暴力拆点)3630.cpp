#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
const int N = 105;
const int M = 10000;
typedef long long LL;
const int inf = 1000000000;

struct E{
	int v, next;
}e[M];
int head[M],k,belong[N],bcnt;
int dfn[N],low[N],indx,st[N],top;
bool inst[N],out[N],mark[N];

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
		int v = e[i].v;
		if( !dfn[v] ){
			tarjan(v);
			if( low[u] > low[v] )
				low[u] = low[v];
		} else if( inst[v] && dfn[v] < low[u] )
			low[u] = dfn[v];
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
void init(){
	CLR( head, -1 ); CLR( dfn, 0 );
	CLR( low, 0 ); CLR( inst, 0 );
	bcnt = indx = top = k = 0;
}
int a[M], b[M], cnt[M];
int main(){
	int n, m;
	while( scanf("%d%d", &n, &m) != EOF ){
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &a[i], &b[i]);
			a[i]++; b[i]++;
		}
		if( n <= 2 ){
			printf("0\n"); continue;
		}
		int ans = inf;
		for(int i=1 ; i <= n ; ++i){
			init();
			for(int j=0 ; j < m ; ++j){
				if( a[j]==i || b[j]==i ) continue;
				addedge( a[j], b[j] );
			}
			for(int j=1 ; j <= n ; ++j)
				if( !dfn[j] ) tarjan(j);
			CLR( cnt, 0 );
			for(int j=1 ; j <= n ; ++j)
				cnt[belong[j]]++;
			int Max = 0;
			for(int j=1 ; j <= bcnt ; ++j)
				if( cnt[j] > Max ) Max = cnt[j];
			ans = min( ans, Max );
		}
		if( ans==1 ) ans = 0;
		printf("%d\n", ans);
	}
    return 0;
}