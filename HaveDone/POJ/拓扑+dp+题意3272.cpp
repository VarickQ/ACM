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
const int M = 50005;
const int N = 5005;

struct edge{
	int v,next;
}e[M],e1[M];
int heade[N],k,in[N];
int heade1[N],k1;
void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
void add1(int u,int v){
	e1[k1].v = v;
	e1[k1].next = heade1[u];
	heade1[u] = k1++;
}
int f[N],g[N],n;
int stack[N],top,path[N];
void topsort(){
	int i,j,k;
	top = 0;
	for( i=1 ; i <= n ; ++i)
		if( in[i] == 0 )
			stack[top++] = i;
	k = 0;
	while(top){
		int u = stack[--top];
		path[k++] = u;
		for( j=heade[u] ; j!=-1 ; j=e[j].next ){
			if(--in[e[j].v] == 0 )
				stack[top++] = e[j].v;
		}
	}
}
int main(){
	int m;
	while( scanf("%d%d", &n, &m) == 2 ){
		memset( heade, -1, sizeof( heade ) );
		memset( heade1, -1, sizeof( heade1 ) );
		memset( in, 0, sizeof( in ) );
		k = k1 = 0;
		int a,b;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &a, &b);
			add( a, b );
			add1( b, a );
			in[b]++;
		}
		topsort();
		memset( f, 0, sizeof( f ) );//入度为0的点到i点的条数
		for(int i=0 ; i < n ; ++i){
			int u = path[i];
			if( f[u] == 0 ) f[u] = 1;
			for(int j=heade[u] ; j!=-1 ; j=e[j].next)
				f[e[j].v] += f[u];
		}
		memset( g, 0, sizeof( g ) );//出度为0的点到i点的条数
		for(int i=n-1 ; i >= 0 ; --i){
			int u = path[i];
			if( g[u] == 0 ) g[u] = 1;
			for(int j=heade1[u] ; j!=-1 ; j=e1[j].next)
				g[e1[j].v] += g[u];
		}
		int Max = 0;
		for(int i=0 ; i < n ; ++i){
			int u = path[i];
			for(int j=heade[u] ; j!=-1 ; j=e[j].next)
				Max = max( Max, f[u]*g[e[j].v] );
		}
		printf("%d\n", Max);
	}
	return 0;
}