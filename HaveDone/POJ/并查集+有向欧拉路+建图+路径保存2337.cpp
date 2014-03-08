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
const int N = 1005;

int n,in[30],out[30],fa[30],ans[N],top;
bool mark[30];
struct words{
	char str[30];
}a[N*10];
struct Edge{
	int v,next,vis;
}e[N];
int heade[30],k;
bool cmp(const words a,const words b ){
	return strcmp( a.str, b.str ) >= 0;
}
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void Union(int x,int y){
	x = find(x);
	y = find(y);
	if(x != y) fa[x] = y;
}
void add(int u, int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
void init(){
	int i;
	k = top = 0;
	memset( e, 0, sizeof( e ) );
	memset( in, 0, sizeof( in ) );
	memset( out, 0, sizeof( out ) );
	memset( ans, 0, sizeof( ans ) );
	memset( mark, 0, sizeof( mark ) );
	memset( heade, -1, sizeof( heade ) );
	for( i=0 ; i <= 26 ; ++i ) fa[i] = i;
}
int jundge(){
	int i,c1=0,c2=0,id=-1;
	for( i=0 ; i < 26 ; ++i )
		if( mark[i] ) break;
	int key = find(i);
	for( i=0 ; i < 26 ; ++i ){
		if( mark[i] && find(i)!=key )//判断图连通
			return -1;
		if( in[i] != out[i] ){
			if(in[i]-out[i]==1) c1++;
			else if(out[i]-in[i]==1){
				c2++; id = i;
			}
			else return -1;
		}
	}
	//判断有向图欧拉路径
	if(!((c1==1&&c2==1)||(c1==0&&c2==0)))
		return -1;
	if( id == -1 ){
		for( i=0 ; i < 26 ; ++i )
			if( out[i] > 0 ){
				id = i; break;
			}
	}
	return id;
}
void dfs(int u, int id){
	for(int i=heade[u] ; i!=-1 ; i=e[i].next){
		if( !e[i].vis ) {
			e[i].vis = 1;
			dfs( e[i].v, i );
		}
	}
	if( id != -1 ) ans[top++] = id;
}
int main(){
	int T,i,j;
	scanf("%d", &T);
	while( T-- ){
		init();
		scanf("%d", &n);
		for( i=0 ; i < n ; ++i )
			scanf("%s", a[i].str);
		sort( a, a+n, cmp );
		for( i=0 ; i < n ; ++i ){
			int len = strlen(a[i].str);
			int u = a[i].str[0]-'a';
			int v = a[i].str[len-1]-'a';
			mark[u] = mark[v] = true;
			in[v]++; out[u]++;
			add( u, v );
			Union( u, v );
		}
		int st = jundge();
		if( st == -1 ) printf("***\n");
		else {
			dfs( st, -1 );
			for( i=top-1 ; i > 0 ; --i)
				printf("%s.", a[ans[i]].str);
			printf("%s\n", a[ans[0]].str);
		}
	}
	return 0;
}