#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int M = 1000000007;
long long dp1[1005][1005];
long long dp2[1005][1005];
int n,r,k,m;
void init(){
	memset(dp1,0,sizeof(dp1));
	dp1[1][1] = 1;
	int i,j;
	for( i = 1 ; i <= 999 ; i ++)
		for(j = 1 ; j <= i ; j ++)
		{
			dp1[i+1][j] = (dp1[i+1][j] +  j*dp1[i][j])%M;
			dp1[i+1][j+1] =(dp1[i+1][j+1]+ dp1[i][j])%M;
		}
}
int main()
{
	int i,j;
	init();
	while(4 == scanf("%d%d%d%d",&n,&r,&k,&m)){
		memset(dp2,0,sizeof(dp2));
		dp2[0][0] = 1;
		for(i = 1 ; i <= n ; i ++)
		{
			dp2[i][1] = i ;
			for( j = 2; j <= r ; j ++){
				dp2[i][j] = dp2[i-1][j];
				if( i >= k+1)
					dp2[i][j] = (dp2[i][j] + dp2[i-k][j-1])%M;
			}
		}
		int sum = 0;
		for( i = 1 ; i <= m ; i ++)
			sum = (sum + dp1[r][i])%M;
		printf("%lld\n",(dp2[n][r] * sum)%M );
	}

}