/*有n门课程作业，每门作业的截止时间为D,需要花费的时间为C，若作业不能按时完成，每超期1天扣1分。*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define ll __int64
const int N = (1<<15)+100;
const int inf = 1000000000;

struct B{//所需时间，前一状态，最少损失
	int cost,pre,reduced;
}dp[N];//dp[i][j]表示在第i天完成作业信息为j
//其中 2^n-1即为n项作业全部完成，0为没有作业完成
struct A{
	int cost,deadline;
	char name[105];
}a[16];

int main(){
	int T,n,i,j,c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0 ; i < n ; ++i)
			scanf("%s%d%d",a[i].name,&a[i].deadline,&a[i].cost);

		for(i=0 ; i < (1<<n) ; ++i)dp[i].reduced=inf;
		dp[0].cost = 0;
		dp[0].pre = -1;
		dp[0].reduced = 0;
		for(i=0 ; i < (1<<n) ; ++i)
		{
			for(j=0 ; j < n ; ++j){
				int s = 1<<j;
				if(i&s) continue;
				int t=dp[i].cost+a[j].cost-a[j].deadline;
				if(t < 0) t = 0;
				if(dp[i+s].reduced > dp[i].reduced+t)
				{
					dp[i+s].reduced = dp[i].reduced+t;
					dp[i+s].cost = dp[i].cost+a[j].cost;
					dp[i+s].pre = j;
				}
				else if(dp[i+s].reduced == dp[i].reduced+t)
					dp[i+s].pre = max(dp[i+s].pre,j);
			}
		}
		printf("%d\n",dp[(1<<n)-1].reduced);
		int out[15],k=0;
		for(i=(1<<n)-1 ; i > 0 ; i-=(1<<j)){
			j = dp[i].pre;
			out[k++] = j;
		}
		for(i=n-1 ; i >= 0 ; --i)
			printf("%s\n",a[out[i]].name);
	}
	return 0;
}