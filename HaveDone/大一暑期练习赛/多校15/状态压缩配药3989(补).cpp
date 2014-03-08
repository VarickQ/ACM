#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1<<21;

int dp[2][N];
int main(){
	int n,m,i,j,s,w;
	while(scanf("%d",&n) == 1)
	{
		if(n < 0) break;
		int ans = 0;
		memset(dp[0],0,sizeof(dp[0]));
		for(i=0 ; i < n ; ++i){
			scanf("%d%d",&s,&w);
			dp[0][s] += w;
		}
		for(i=1 ; i <=20 ; ++i){
			int flag=i&1,p=flag^1;
			memset(dp[flag],0,sizeof(dp[flag]));
			for(j=0 ; j < 1<<20 ; ++j){
				if(j&(1<<(i-1))){
					dp[flag][j] = dp[p][j]+dp[p][j-(1<<(i-1))];
				} else {
					dp[flag][j] = dp[p][j];
				}
				if(i==20)ans = max(ans,dp[flag][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}