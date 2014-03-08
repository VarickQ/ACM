#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 2000000000
const int N = 205;
int qu[N*1000];
int pre[N],a[N];
//pre记录父亲节点,a记录到i点前的最小残量并进行标记
int cap[N][N],flow[N][N];//最大容量和当前流量
int maxflow(int s,int t){
	memset(qu,0,sizeof(qu));
	memset(flow,0,sizeof(flow));//初始化流量
	int f = 0;//s流出的总流量
	int head=0,tail=0;
	while(true){
		memset(a,0,sizeof(a));
		a[s] = inf;//源点初始化
		qu[tail++] = s;
		while(head < tail){//bfs寻找一次增广路
			int u = qu[head++];
			for(int v=0 ; v <= t ; v++){//一共有几点
				if(!a[v] && cap[u][v] > flow[u][v]){
					//寻找未标记的点并且边有残量
					pre[v] = u;//记录父亲节点
					qu[tail++] = v;
					//更新到达a[i]的最小残量
					a[v] = min(a[u],cap[u][v]-flow[u][v]);
				}
			}
		}
		if(a[t]==0) break;//找不着增广路了
		for(int u=t ; u!=s ; u=pre[u])//从汇点往回走
		{
			flow[pre[u]][u] += a[t];//更新正向流量
			flow[u][pre[u]] -= a[t];//更新反向流量
		}
		f += a[t];//更新从s流出的总流量
	}
	return f;
}
int main()
{
	int i,n,m,s,e,w;
	while(scanf("%d %d",&n,&m) == 2){
		memset(cap,0,sizeof(cap));
		for(i=0 ; i < n ; i++){
			scanf("%d %d %d",&s,&e,&w);
			cap[s-1][e-1] += w;//有重边！所以用+=！
		}
		printf("%d\n",maxflow(0,m-1));
	}
	return 0;
}