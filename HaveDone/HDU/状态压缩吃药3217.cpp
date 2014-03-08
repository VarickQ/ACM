#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int N = 1<<17;

int dp[17][N];
int main(){
    int n,m,i,j,s,w;
    while(scanf("%d",&n) && n)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&m);
        for(i=0 ; i < m ; ++i){
            scanf("%d%d",&s,&w);
            dp[0][s] = w;
        }
        for(i=1 ; i <= n ; ++i){
            for(j=0 ; j < (1<<n) ; ++j){
                if(j&(1<<(i-1))){
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-(1<<(i-1))];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int ans = -1;
        for(i=0 ; i < (1<<n) ; ++i)
            ans = max(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}