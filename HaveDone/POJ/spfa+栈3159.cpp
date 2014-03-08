#include <stdio.h>
#include <math.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 10000000;
const int N = 30005;

struct A{
	int v,c,next;
}e[N*5];
int k,n,heade[N],d[N];
int s[N*100];
bool vis[N];

void add(int u,int v,int w){
	e[k].v = v;
	e[k].c = w;
	e[k].next = heade[u];
	heade[u] = k++;
}

void spfa(){
	for(int i=1 ; i <= n ; i++){
		vis[i] = false;
		d[i] = inf;
	}
	d[1] = 0;
	int top=0;
	s[top++] = 1;
	while( top != 0 ){
		int u = s[--top];
		vis[u] = true;
		for(int i=heade[u] ; i != -1 ; i=e[i].next){
			int v = e[i].v;
			if(d[v] > d[u] + e[i].c){
				d[v] = d[u] + e[i].c;
				if(!vis[v]){
					vis[v] = true;
					s[top++] = v;
				}
			}
		}
		vis[u]=false;
	}
}
int main()
{
	int m,a,b,c;
	while( scanf("%d%d", &n, &m) != EOF ){
		memset( heade, -1, sizeof( heade ) );
		k = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			add( a, b, c );
		}
		spfa();
		printf("%d\n",d[n]);
	}
	return 0;
}