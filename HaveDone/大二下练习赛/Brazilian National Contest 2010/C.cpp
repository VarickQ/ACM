//C dp by hhf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 100000000;
const int M   = 2000100;
const int N   = 100005;
typedef long long ll;

int n,m;
int f[50];
int dp[50][32009];
int ans[50];
int main(){
#ifndef ONLINE_JUDGE
	freopen ("test.txt", "r", stdin);
#endif
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n+m==0)
			break;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",&f[i]);
			ans[i]=0;
		}
		dp[0][16000]=1;
		for(int i=1;i<=n;i++)
			for(int j=-16000;j<=16000;j++){
				if(dp[i-1][j+16000]){

					dp[i][j+f[i]+16000]=1;

					if(j-f[i]+16000>=0)
						dp[i][j-f[i]+16000]=1;
				}
			}

		if(dp[n][m+16000]==0)
			printf("*\n");
		else{
			dp[n][m+16000]=-1;
			for(int i=n;i>=1;i--)
				for(int j=-16000;j<=16000;j++){
					if(! dp[i-1][j+16000])
						continue;
					if(dp[i][j+16000+f[i]]==-1){

						dp[i-1][j+16000]=-1;
						if(ans[i]==0)
							ans[i]=1;
						else if(ans[i]!=1)
							ans[i]=-2;
					}
					if( j-f[i]+16000>=0 &&dp[i][j+16000-f[i]]==-1){//

						dp[i-1][j+16000]=-1;
						if(ans[i]==0)
							ans[i]=-1;
						else if(ans[i]!=-1)
							ans[i]=-2;
					}
				}
			for(int i=1;i<=n;i++)
				if(ans[i]==-1)
					printf("-");
				else if(ans[i]==1)
					printf("+");
				else
					printf("?");
				printf("\n");
		}
	}
	return 0;
}