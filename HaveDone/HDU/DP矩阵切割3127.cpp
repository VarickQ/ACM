#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 12;

int x[N],y[N],c[N],dp[1001][1001];
int main(){
	int T,n,X,Y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&X,&Y);
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d%d",&x[i],&y[i],&c[i]);
		memset(dp,0,sizeof(dp));
		for(int i=1 ; i <= X ; ++i)
			for(int j=1 ; j <= Y ; ++j)
				for(int k=0 ; k < n ; ++k){
					if(i>=x[k] && j>=y[k]){
						dp[i][j]=max(dp[i][j],dp[i-x[k]][j]+dp[x[k]][j-y[k]]+c[k]);
						dp[i][j]=max(dp[i][j],dp[i][j-y[k]]+dp[i-x[k]][y[k]]+c[k]);
					}
					if(i>=y[k] && j>=x[k]){
						dp[i][j]=max(dp[i][j],dp[i][j-x[k]]+dp[i-y[k]][x[k]]+c[k]);
						dp[i][j]=max(dp[i][j],dp[i-y[k]][j]+dp[y[k]][j-x[k]]+c[k]);
					}
				}
		printf("%d\n",dp[X][Y]);
	}
	return 0;
}