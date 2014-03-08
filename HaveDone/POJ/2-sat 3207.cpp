#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#define inf 2000000000
const int N = 20100;

struct E{
	int v,next;
}e[5000000];
int heade[N],k;
int belong[N],bcnt;
int stack[N],top;
bool instack[N];
int dfn[N],low[N],index;
int c[5000000][2],n,m;

void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
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
		}else if(instack[e[i].v] && dfn[e[i].v] < low[u])
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
	int u,v,i;
	scanf("%d%d",&n,&m);
	k = top = index = bcnt = 0;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(heade,-1,sizeof(heade));
	memset(instack,0,sizeof(instack));
	memset(c,0,sizeof(c));
	for(i=1 ; i <= m ; ++i){
		scanf("%d%d",&u,&v);
		if(u > v)swap(u,v);
		c[i][0] = u;
		c[i][1] = v;
	}
	for(i=1 ; i <= m ; ++i)
		for(int j=i+1 ; j <= m ; ++j)
			if(c[i][0]<c[j][0]&&c[i][1]>c[j][0]&&c[i][1]<c[j][1]
			||c[j][0]<c[i][0]&&c[j][1]>c[i][0]&&c[j][1]<c[i][1]){
				add(i,j+m);
				add(j+m,i);
				add(j,i+m);
				add(i+m,j);
			}
	for(i=1 ; i <= 2*m ; ++i)
		if(!dfn[i]) tarjan(i);
	for(i=1 ; i <= m ; ++i)
		if(belong[i]==belong[i+m]) break;
	if(i<=m)printf("the evil panda is lying again\n");
	else printf("panda is telling the truth...\n");
	return 0;
}