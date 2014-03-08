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
const int M = 20005;
const int N = 10005;

struct Edge{
	int v,next;
}e[M];
int heade[N],k,n,num;
int fa[N],in[N];
int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
void Union(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fy != fx){
       fa[fx] = fy;
	   num--;
	}
}
void add( int u, int v ){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
int stack[N],top,a[M],b[M];
char ch[M];
void topsort(){
	int i,j;
	top = 0;
	for( i=0 ; i < n ; ++i ){
		if( in[i] == 0 && i == find(i) )
			 stack[top++] = i;
	}
	bool f = false;
	while( top ){
		if( top > 1 ) f = true;
		int u = stack[--top];
		num--;
		for( j=heade[u] ; j!=-1 ; j=e[j].next ){
			if( --in[e[j].v] == 0 )
				stack[top++] = e[j].v;
		}
	}
	if( num > 0 ) printf("CONFLICT\n");
	else if( f ) printf("UNCERTAIN\n");
	else printf("OK\n");
}
void init(){
	for(int i=0 ; i <= n ; ++i) fa[i] = i;
	memset( in, 0, sizeof( in ) );
	memset( heade, -1, sizeof( heade ) );
	k = 0;
	num = n;
}
int main(){
	int m;
	while( scanf("%d%d", &n, &m) != EOF ){
		init();
		bool f = false;
		for(int i=0 ; i < m ; ++i){
			scanf("%d %c %d", &a[i], &ch[i], &b[i]);
			if( ch[i]=='=' )
				Union( a[i], b[i] );
		}
		for(int i=0 ; i < m ; ++i){
			if( ch[i] == '=' ) continue;
			int x = find(a[i]);
			int y = find(b[i]);
			if( x == y ) f = true;
			if( ch[i]=='>' ){
				add( x, y );
				in[y]++;
			}
			else if( ch[i]=='<' ){
				add( y, x );
				in[x]++;
			}
		}
		if( f ) printf("CONFLICT\n");
		else topsort();
	}
	return 0;
}