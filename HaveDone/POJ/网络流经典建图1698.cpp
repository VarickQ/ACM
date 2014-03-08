#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 400
#define inf 1<<30
int p[MAXN],a[MAXN],t,sum=0;
//p记录父亲节点,a记录到i点前的最小残量并进行标记
int cap[MAXN][MAXN],flow[MAXN][MAXN];//最大容量和当前流量
int maxflow(int s,int t){//s源点,t汇点
	memset(flow,0,sizeof(flow));//流量全为0
	int f = 0;//s流出的总流量
	queue<int> q;
	while(1){
		memset(a,0,sizeof(a));
		a[s]=inf; //源点初始化
		q.push(s);
		while(!q.empty()){ //bfs寻找一次增广路
			int u=q.front(); q.pop();
			for(int v=0 ; v <= t ; v++){ //一共有几点
				if(!a[v] && cap[u][v]>flow[u][v]){//寻找未标记的点并且边有残量
					p[v] = u; //记录父亲节点
					q.push(v);
					a[v]=a[u]<(cap[u][v]-flow[u][v])?a[u]:(cap[u][v]-flow[u][v]);
					//更新到达a[i]的最小残量
				}
			}
		}
		if(a[t]==0) break; //找不着增广路了
		for(int u=t ; u != s ; u=p[u]) //从汇点往回走
		{
			flow[p[u]][u] += a[t]; //更新正向流量
			flow[u][p[u]] -= a[t]; //更新反向流量
		}
		f += a[t]; //更新从s流出的总流量
	}
	return f; //返回最大流量
}

struct Node{
	int workday[8];
	int d,w;
}film[25];

int main()
{
	int cs,fn,i,j,temp,k,Max;
	scanf("%d",&cs);
	while(cs--)
	{
		memset(cap,0,sizeof(cap));
		scanf("%d",&fn);
		Max=sum=0;
		for(i=1 ; i <= fn ; i++){//有几部电影
			k = 0;
			for(j=1 ; j <= 7 ; j++){
				scanf("%d",&temp);
				if(temp==1)
					film[i].workday[k++]=j;//星期几工作
			}
			scanf("%d%d",&film[i].d,&film[i].w);
			if(Max<film[i].w)Max=film[i].w;
			sum += film[i].d;
			//构图
			cap[0][i]=film[i].d;//前fn点个图
			for(int p=0 ; p < film[i].w ; p++){
				for(j=0 ; j < k ; j++){
					int day=p*7+fn+film[i].workday[j];
					cap[i][day]=1;
				}
			}
		}
		//继续构图
		t=fn+Max*7+1;
		for(i=fn+1 ; i < t ; i++)
			cap[i][t]=1;
		if(maxflow(0,t)==sum)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}