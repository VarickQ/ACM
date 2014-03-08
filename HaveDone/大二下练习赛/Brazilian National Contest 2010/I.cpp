//I 强连通判断连通块 by Varick_Q
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
const int M   = 2000100;
const int N   = 2005;
typedef long long ll;
struct A{
	int v,next;
}e[M];
int heade[M],k;
//belong[i]=j:第i个点所在的强连通分量的编号是j
int in[N],out[N],belong[N],bcnt;
int stack[M],top;
bool instack[M];
//dfn[u]:节点u搜索的次序编号(时间戳)
//low[u]是u或u的子树能够追溯到的最早的栈中节点的次序号
int dfn[N],low[N],indx;

void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}

void tarjan(int u){
	dfn[u] = low[u] = ++indx;	//为节点u设定次序编号和Low初值
	instack[u] = true;		//标记进入栈
	stack[top++] = u;		//将节点u压入栈中
	for(int i=heade[u] ; i!=-1 ; i=e[i].next){//枚举每一条边
		if(!dfn[e[i].v]){	//如果节点v未被访问过
			tarjan(e[i].v);	//继续向下找
			if(low[u] > low[e[i].v])
				low[u] = low[e[i].v];
		} else if(instack[e[i].v] && dfn[e[i].v] < low[u])
			//如果节点u还在栈内
			low[u] = dfn[e[i].v];
	}
	
	if(dfn[u]==low[u]){		//如果节点u是强连通分量的根
		bcnt++;
		int temp;
		do{
			temp = stack[--top];	//将v退栈，为该强连通分量中一个顶点
			instack[temp] = false;
			belong[temp] = bcnt;	//缩点，bcnt就是强连通分量的个数
		}while(u != temp);
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0)
			break;
		memset(heade,-1,sizeof(heade));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(instack,0,sizeof(instack));
		bcnt = indx = top = 0;
		int i,a,b,c;
		for( i=0 ; i < m ; ++i ){
			scanf("%d%d%d", &a, &b, &c);
			if(c == 1) add(a,b);
			else if(c == 2){
				add(a,b);
				add(b,a);
			}
		}
		for(i=1 ; i <= n ; i++)
			if(!dfn[i]) tarjan(i);
		if(bcnt==1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}