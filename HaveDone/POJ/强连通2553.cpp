/*求出度为0的强连通分量*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 1000000000
const int M = 50000;
const int N = 5005;
struct E{
	int v,next;
}e[M];
int heade[M],k,belong[N],bcnt,ans[N];
int dfn[N],low[N],indx,stack[N],top;
bool instack[N],out[N],mark[N];
void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
void init(){
	memset(heade,-1,sizeof(heade));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(instack,0,sizeof(instack));
	memset(out,0,sizeof(out));
	bcnt = indx = top = k= 0;
}
void tarjan(int u){
	dfn[u] = low[u] = ++indx;
	instack[u] = true;
	stack[top++] = u;
	for(int i=heade[u] ; i!=-1 ; i=e[i].next){
		if(!dfn[e[i].v]){
			tarjan(e[i].v);
			if(low[u] > low[e[i].v])
				low[u] = low[e[i].v];
		} else if(instack[e[i].v] && low[e[i].v] < low[u])
			low[u] = low[e[i].v];
	}
	if(dfn[u] == low[u]){
		bcnt++;
		int temp;
		do{
			temp = stack[--top];
			instack[temp] = false;
			belong[temp] = bcnt;
		}while(u != temp);
	}
}
int main()
{
	int n,m,i,a,b;
	while(scanf("%d",&n) && n)
	{
		scanf("%d",&m);
		init();
		for(i=0 ; i < m ; i++)
		{
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		for(i=1 ; i <= n ; i++)
			if(!dfn[i]) tarjan(i);
		for(i=1 ; i <= n ; i++)
			for(int j=heade[i] ; j!=-1 ; j=e[j].next)
				if(belong[i] != belong[e[j].v])
					out[belong[i]] = true;
		memset(mark,0,sizeof(mark));
		for(i=1,k=0 ; i <= bcnt ; i++)
			if(!out[i]){
				for(int j=1 ; j <= n ; j++)
					if(belong[j]==i && !mark[j]){
						mark[j] = true;
						ans[k++] = j;
					}
			}
		sort(ans,ans+k);
		for(i=0 ; i < k ; i++)
			if(!i)printf("%d",ans[i]);
			else printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}