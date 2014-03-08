#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
const int M = 40010;
const int N = 1005;
#define min(a,b) ((a)<(b)?(a):(b))

int n,m,ans;
struct Node{
	int cap,cost,v,next,re;
}e[M];
int heade[N],k;
void add( int u, int v, int ca, int co ){
	e[k].v = v;
	e[k].cap = ca;
	e[k].cost = co;
	e[k].next = heade[u];
	e[k].re = k+1;
	heade[u] = k++;

	e[k].v = u;
	e[k].cap = 0;
	e[k].cost = -co;
	e[k].next = heade[v];
	e[k].re = k-1;
	heade[v] = k++;
}
int stack[N],dis[N],pre[N];
bool vis[N];
bool spfa(){
	int i, top=0;
	for( i=0 ; i <= n ; ++i ){
		dis[i] = inf;
		vis[i] = false;
	}
	dis[0] = 0;
	stack[top++] = 0;
	vis[0] = true;
	while( top ){
		int u = stack[--top];
		for( i=heade[u] ; i!=0 ; i=e[i].next ){
			int v = e[i].v;
			if( e[i].cap && dis[v] > dis[u]+e[i].cost){
				dis[v] = dis[u]+e[i].cost;
				pre[v] = i;
				if( !vis[v] ){
					vis[v] = true;
					stack[top++] = v;
				}
			}
		}
		vis[u] = false;
	}
	if( dis[n] == inf ) return false;
	return true;
}
void end(){
	int i, p, sum=inf;
	for( i=n ; i!=0 ; i=e[e[p].re].v ){
		p = pre[i];
		sum = min( sum, e[p].cap );
	}
	for( i=n ; i!=0 ; i=e[e[p].re].v ){
		p = pre[i];
		e[p].cap -= sum;
		e[e[p].re].cap += sum;
		ans += sum * e[p].cost;
	}
}

int main(){
	int a,b,c;
	scanf("%d%d", &n, &m );
	k = 1;
	while( m-- ){
		scanf("%d%d%d", &a, &b, &c);
		add( a, b, 1, c );
		add( b, a, 1, c );
	}
	add( 0, 1, 2, 0 );
	add( n, n+1, 2, 0 );
	ans = 0;
	while( spfa() ) end();
	printf("%d\n", ans);
	return 0;
}