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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 10005;
const int N   = 10005;
typedef long long ll;

struct Node{
	int c, v, next;
}e[N*2];
int heade[N*2],k;
int fire[N],d[N],dd[N];
bool vis[N];
int qu[N*3],n;
void add( int u, int v, int w ){
	e[k].v = v;
	e[k].c = w;
	e[k].next = heade[u];
	heade[u] = k++;
}
void spfa(int s,int *dist)//sÎªÔ­µã
{
	int i,head=0,tail=1;
	memset(vis,false,sizeof(vis));
	dist[s] = 0;
	qu[0] = s;
	while(tail > head){
		int u = qu[head];
		vis[u] = true;
		for(i=heade[u] ; i!=-1 ; i=e[i].next){
			int v=e[i].v;
			if(dist[v] > dist[u]+e[i].c){
				dist[v] = dist[u]+e[i].c;
				if(!vis[v]){
					vis[v] = true;
					qu[tail++] = v;
					//if(tail >= N)tail=0;
				}
			}
		}
		vis[u]=false;
		head++;
		//if(head >= N) head=0;
	}
}
int main(){
	int F;
	while( scanf("%d%d", &F, &n) != EOF ){
		for(int i=0 ; i < F ; ++i)
			scanf("%d", &fire[i]);
		memset( heade, -1, sizeof( heade ) );
		k = 0;
		int u,v,w;
		while( scanf("%d%d%d", &u,&v,&w) != EOF ){
			add( u, v, w );
			add( v, u, w );
		}
		for(int i=0 ; i <= n ; ++i)
			d[i]=inf;
		for(int i=0 ; i < F ; ++i)
			spfa( fire[i], d );
		int Min = inf,pos = 1;
		for(int i=1 ; i <= n ; ++i){
			int Max = 0;
			if(d[i] == 0) continue;
			for(int j=0 ; j <= n ; ++j)
				dd[j] = d[j];
			spfa( i, dd );
			for(int j=1 ; j <= n ; ++j)
				Max = max( Max, dd[j] );
			if( Max < Min ){
				Min = Max;
				pos = i;
			}
		}
		printf("%d\n", pos);
	}
	return 0;
}