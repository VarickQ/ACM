#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 2000000000
const int N = 2010;
const int M = 2000010;

struct E{
	int u,v,next;
}e1[M],e2[M];
int heade1[N],k1,heade2[N],k2;
int belong[N],bcnt,dfn[N],low[N],index;
int stack[N],top,opp[N],col[N],in[N];
bool instack[N];

void add1(int u,int v){
	e1[k1].u = u;
	e1[k1].v = v;
	e1[k1].next = heade1[u];
	heade1[u] = k1++;
}
void add2(int u,int v){
	e2[k2].u = u;
	e2[k2].v = v;
	e2[k2].next = heade2[u];
	heade2[u] = k2++;
}
void tarjan(int u){
	dfn[u] = low[u] = ++index;
	instack[u] = true;
	stack[top++] = u;
	for(int i=heade1[u] ; i!=-1 ; i=e1[i].next){
		if(!dfn[e1[i].v]){
			tarjan(e1[i].v);
			if(low[u] > low[e1[i].v])
				low[u] = low[e1[i].v];
		}else if(instack[e1[i].v] && dfn[e1[i].v] < low[u])
			low[u] = dfn[e1[i].v];
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
void topsort(){
	memset(stack,0,sizeof(stack));
	memset(col,0,sizeof(col));
	top = 0;
	for(int i=1 ; i <= bcnt ; ++i)
		if(in[i]==0) stack[top++] = i;
	while(top){
		int u = stack[--top];
		if(col[u]==0){
			col[u] = 1;
			col[opp[u]] = -1;
		}
		for(int i=heade2[u] ; i!=-1 ; i=e2[i].next)
			if(--in[e2[i].v] == 0)
				stack[top++] = e2[i].v;
	}
}
void init(){
	memset(heade1,-1,sizeof(heade1));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(instack,0,sizeof(instack));
	k1 = top = index = 0;
}
int main()
{
	int n,m,i,a,b;
	char s1,s2;
	while(scanf("%d%d",&n,&m) && (n+m))
	{
		init();
		bcnt = 0;
		for(i=0 ; i < m ; ++i){
			scanf("%d%c %d%c",&a,&s1,&b,&s2);
			if(s1=='h' && s2=='h'){
				add1(a+n,b);
				add1(b+n,a);
			}
			else if(s1=='h' && s2=='w'){
				add1(a+n,b+n);
				add1(b,a);
			}
			else if(s1=='w' && s2=='h'){
				add1(a,b);
				add1(b+n,a+n);
			}
			else if(s1=='w' && s2=='w'){
				add1(a,b+n);
				add1(b,a+n);
			}
		}
		add1(0,0+n);//新娘到新郎的边
		for(i=0 ; i < n*2 ; ++i)
			if(!dfn[i]) tarjan(i);
		for(i=0 ; i < n ; ++i){
			if(belong[i] == belong[i+n]) break;
			opp[belong[i]]=belong[i+n];
			opp[belong[i+n]]=belong[i];
		}
		if(i<n)printf("bad luck\n");
		else {
			memset(in,0,sizeof(in));
			memset(heade2,-1,sizeof(heade2));
			k2 = 0;
			for(i=0 ; i < k1 ; ++i)
				if(belong[e1[i].u] != belong[e1[i].v]){
					add2(belong[e1[i].v],belong[e1[i].u]);
					in[belong[e1[i].u]]++;
				}
			topsort();
			for(i=1 ; i < n ; ++i)
				if(col[belong[i]] == 1){
					printf("%dh ",i);
				} else {
					printf("%dw ",i);
				}
			printf("\n");
		}
	}
	return 0;
}