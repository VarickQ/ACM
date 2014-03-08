#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
const int N = 2050;
const int M = 10010;

struct E{
	int v,next;
}e[M*10];
int heade[N],k;
int belong[N],bcnt,dfn[N],low[N],ind;
int stack[N],top;
bool instack[N];

void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
void tarjan(int u){
	dfn[u] = low[u] = ++ind;
	instack[u] = true;
	stack[top++] = u;
	for(int i=heade[u] ; i!=-1 ; i=e[i].next){
		int v = e[i].v;
		if(!dfn[v]){
			tarjan(v);
			if(low[u] > low[v])
				low[u] = low[v];
		}else if(instack[v] && dfn[v] < low[u])
			low[u] = dfn[v];
	}
	if(low[u] == dfn[u]){
		bcnt++;
		int temp;
		do{
			temp = stack[--top];
			instack[temp] = false;
			belong[temp] = bcnt;
		}while(u != temp);
	}
}
void init(){
	memset(heade,-1,sizeof(heade));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(instack,0,sizeof(instack));
	k = top = ind = bcnt = 0;
}
int a[M], b[M], c[M], n, m;
bool ok( int mid ){
	int i;
	init();
	for(int i=0 ; i < mid ; ++i){
		if( c[i] == 0 ){
			add( a[i], b[i]+n );
			add( b[i], a[i]+n );
		}
		else if( c[i] == 1 ){
			add( a[i], b[i] );
			add( b[i], a[i] );
			add( a[i]+n, b[i]+n );
			add( b[i]+n, a[i]+n );
		}
		else if( c[i] == 2 ){
			add( a[i]+n, b[i] );
			add( b[i]+n, a[i] );
		}
	}
	for(int i=0 ; i < 2*n ; ++i)
		if(!dfn[i]) tarjan(i);
	for(int i=0 ; i < n ; ++i)
		if( belong[i] == belong[i+n] )
			return false;
	return true;
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=0 ; i < m ; ++i)
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
		int l=1,r=m,mid,ans = 0;
		while( l <= r ){
			mid = l+r>>1;
			if( ok( mid ) ){
				ans = mid;
				l = mid+1;
			} else r = mid-1;
		}
		printf("%d\n", ans);
	}
	return 0;
}