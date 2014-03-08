#include <iostream>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define inf 10000000
#define eps 1e-6

int map[205][205],d[3][205],n;
struct Node{
	double x,y,r;
}p[205];
double dis(Node a,Node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int v[205];
void SPFA(int u){
	memset(v,0,sizeof(v));
	queue<int> q;
	q.push(u);
	v[u] = 1;
	d[u][u]=0;
	while(!q.empty())
	{
		int x=q.front(); q.pop();
		for(int i=0 ; i < n ; i++)
			if(!v[i] && map[x][i])
			{
				v[i] = 1;
				d[u][i] = d[u][x]+1;
				q.push(i);
			}
	}
}
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		memset(map,0,sizeof(map));
		scanf("%d",&n);

		for(i=0 ; i < 3 ; i++)
			for(j=0 ; j < n ; j++)
				d[i][j] = inf;
		d[0][0]=d[1][1]=d[2][2]=0;

		for(i=0 ; i < n ; i++)
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].r);
		for(i=0 ; i < n ; i++)
			for(j=i+1 ; j < n ; j++)
				if(dis(p[i],p[j])-p[i].r-p[j].r <= eps)
					map[i][j]=map[j][i]=1;

		int ans = inf;
		SPFA(0);
		SPFA(1);
		SPFA(2);
		for(i=0 ; i < n ; i++)
			if(d[0][i]+d[1][i]+d[2][i]<ans)
				ans = d[0][i]+d[1][i]+d[2][i]+1;
		if(ans==inf) printf("-1\n");
		else printf("%d\n",n-ans);
	}
	return 0;
}