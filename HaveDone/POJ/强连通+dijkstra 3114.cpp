#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 1000000000
const int N = 505;

struct E{
	int val,v,next;
}e[N*N];
int heade[N],belong[N],dfn[N],low[N],dis[N];
int stack[N],top,index,bcnt,k,mat[N][N],n;
bool instack[N],vis[N];

void add(int u,int v,int w){
	e[k].v = v;
	e[k].val = w;
	e[k].next = heade[u];
	heade[u] = k++;
}
void init(){
	memset(heade,-1,sizeof(heade));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(instack,0,sizeof(instack));
	index = bcnt = top = k = 0;
	for(int i=1 ; i <= n ; i++)
		for(int j=1 ; j <= n ; j++)
			if(i!=j)mat[i][j] = inf;
			else mat[i][j] = 0;
}
void tarjan(int u){
	dfn[u] = low[u] = ++index;
	instack[u] = true;
	stack[top++] = u;
	for(int i=heade[u] ; i!=-1 ; i=e[i].next)
	{
		if(!dfn[e[i].v]){
			tarjan(e[i].v);
			if(low[u] > low[e[i].v])
				low[u] = low[e[i].v];
		} else if(instack[e[i].v] && dfn[e[i].v] < low[u])
			low[u] = dfn[e[i].v];
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
void dijkstra(int s){
	memset(vis,0,sizeof(vis));
	for(int i=1 ; i <= n ; i++)dis[i]=inf;
	dis[s] = 0;
	for(int i=1 ; i <= n ; i++)
	{
		int x=0,min=inf;
		for(int y=1 ; y <= n ; y++)
			if(!vis[y] && dis[y] <= min){
				min = dis[y];
				x = y;
			}
		vis[x] = true;
		for(int y=1 ; y <= n ; y++)
			if(!vis[y] && dis[y] > dis[x]+mat[x][y])
				dis[y] = dis[x] + mat[x][y];
	}
}
int main()
{
	int m,x,y,h,i,j,Q;
	while(scanf("%d%d",&n,&m) && (n+m))
	{
		init();
		for(i=0 ; i < m ; i++)
		{
			scanf("%d%d%d",&x,&y,&h);
			add(x,y,h);
		}
		for(i=1 ; i <= n ; i++)
			if(!dfn[i]) tarjan(i);
		for(i=1 ; i <= n ; i++)
			for(j=heade[i] ; j!=-1 ; j=e[j].next)
			{
				if(belong[i] != belong[e[j].v]){
					mat[i][e[j].v] = e[j].val;
				} else {
					mat[i][e[j].v] = 0;
				}
			}
		scanf("%d",&Q);
		for(i=0 ; i < Q ; i++)
		{
			scanf("%d%d",&x,&y);
			dijkstra(x);
			if(dis[y]==inf)
				printf("Nao e possivel entregar a carta\n");
			else printf("%d\n",dis[y]);
		}
		printf("\n");
	}
	return 0;
}