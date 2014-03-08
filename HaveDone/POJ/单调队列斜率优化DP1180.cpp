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
const int N = 10005;
const int MOD = 100000000;

int qu[N],head,tail;
ll t[N],f[N];
//t[i]表示从i到n的任务所需要的时间总和
//f[i]表示从i到n的费用系数总和
ll dp[N];
//dp[i]表示对于从i到n的任务安排的最优解
//dp[i]=dp[j]+(s+t[i]-t[j])*f[i] (i < j <= n+1)
int main(){
	int n,s,i;
	while(scanf("%d",&n) == 1)
	{
		scanf("%d",&s);
		for(i=1 ; i <= n ; ++i)
			scanf("%I64d%I64d",&t[i],&f[i]);
		for(i=n-1 ; i >= 1 ; --i){
			t[i] += t[i+1];
			f[i] += f[i+1];
		}
		head = tail = 0;
		qu[0] = n;
		dp[n] = (s+t[n])*f[n];
		for(i=n-1 ; i >= 1 ; --i){
			while(head<tail && (dp[qu[head+1]]-dp[qu[head]])<=(t[qu[head+1]]-t[qu[head]])*f[i])
				head++;
			ll temp = (s+t[i])*f[i];
			dp[i] = min(temp,dp[qu[head]]+(s+t[i]-t[qu[head]])*f[i]);
			while(head<tail && (dp[i]-dp[qu[tail]])*(t[qu[tail]]-t[qu[tail-1]])<=(t[i]-t[qu[tail]])*(dp[qu[tail]]-dp[qu[tail-1]]))
				tail--;
			qu[++tail] = i;
		}
		printf("%I64d\n",dp[1]);
	}
	return 0;
}