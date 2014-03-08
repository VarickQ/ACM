#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define max(a,b) (a>b?a:b)
#define inf 100000000
const int M = 1000000;
const int N = 105;
//问题1：初始至少需要向多少个学校发放软件，使得网络内所有的学校最终都能得到软件。
//问题2，至少需要添加几条传输线路（边），使任意向一个学校发放软件后，
//经过若干次传送，网络内所有的学校最终都能得到软件。
//		问题一：求零入度点的数目
//		问题二：求max(零入度点的数目，零出度点的数目)
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
int main()
{
	int n,i,a;
	while(scanf("%d",&n) == 1)
	{
		memset(heade,-1,sizeof(heade));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(instack,0,sizeof(instack));
		bcnt = indx = top = 0;
		for(i=1,k=0 ; i <= n ; i++)
		{
			while(1){
				scanf("%d",&a);
				if(a == 0) break;
				add(i,a);
			}
		}
		for(i=1 ; i <= n ; i++)
			if(!dfn[i]) tarjan(i);
		if(bcnt==1){
			printf("1\n0\n"); continue;
		}
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		for(i=1 ; i <= n ; i++)
			for(int j=heade[i] ; j!=-1 ; j=e[j].next){
				if(belong[i] != belong[e[j].v]){
					in[belong[e[j].v]] ++;	//入度
					out[belong[i]] ++;		//出度
				}
			}
		int ans1=0,ans2=0;
		for(i=1 ; i <= bcnt ; i++){
			if(in[i] == 0)ans1++;
			if(out[i]== 0)ans2++;
		}
		printf("%d\n%d\n",ans1,max(ans1,ans2));
	}
	return 0;
}