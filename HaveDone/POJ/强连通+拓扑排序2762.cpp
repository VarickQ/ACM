#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 1000000000
#define max(a,b) (a>b?a:b)
const int N = 1005;

struct E{
	int v,next;
}e[N*N],e2[N*N];
int heade[N],k,heade2[N],k2,belong[N],bcnt;
int dfn[N],low[N],index,num[N];
int stack[N],top,in[N];
bool instack[N],vis[N][N];
void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
void add2(int u,int v){
	e2[k2].v = v;
	e2[k2].next = heade2[u];
	heade2[u] = k2++;
}
void init(){
	memset(heade,-1,sizeof(heade));
	memset(heade2,-1,sizeof(heade2));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(instack,0,sizeof(instack));
	memset(vis,0,sizeof(vis));
	memset(in,0,sizeof(in));
	index = bcnt = top = k = k2 = 0;
}
void topsort(){
	memset(num,0,sizeof(num));
	memset(stack,0,sizeof(stack));
	top = 0;
	for(int i=1 ; i <= bcnt ; i++)
		if(in[i]==0){//建零入度顶点栈,入度为0者进栈
			stack[top++] = i;
			num[i]++;
		}
	while(top){
		int u = stack[--top];
		for(int i=heade2[u] ; i!=-1 ; i=e2[i].next)
		{	//对i号顶点的每个邻接点的入度减1
			if(--in[e2[i].v]==0){
				stack[top++] = e2[i].v;//若入度减为0，则入栈
				num[e2[i].v] = num[u]+1;
			}
		}
	}
}
void tarjan(int u){
	dfn[u] = low[u] = ++index;
	instack[u] = true;
	stack[top++] = u;
	for(int i=heade[u] ; i!=-1 ; i=e[i].next){
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
int main()
{
	int T,n,m,a,b,i;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(i=0 ; i < m ; i++)
		{
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		for(i=1 ; i <= n ; i++)
			if(!dfn[i])
				tarjan(i);
		for(i=1 ;i <= n ; i++)
			for(int j=heade[i] ; j!=-1 ; j=e[j].next){
				int v=e[j].v;
				if(belong[i]!=belong[v] && !vis[belong[i]][belong[v]]){
					vis[belong[i]][belong[v]]=true;
					add2(belong[i],belong[v]);
					in[belong[v]]++;
				}
			}
		topsort();
		int ans=-1;
		for(i=1 ; i <= bcnt ; i++)
			ans = max(ans,num[i]);
		if(ans==bcnt)printf("Yes\n");//连通块全部到达
		else printf("No\n");
	}
	return 0;
}