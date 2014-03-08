#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a,b;
double ans;
double p[2010][4];
double dp[2010][3]; //0 all 1 left 2 right
void solve()
{
	int i,j;
	ans = 0;
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for( i = 0 ; i <= n ; i ++){
		double next = dp[i][0];
		for(j = a ; j <= b ; j ++){
			int t = i + j;
			if(t > n){
				ans += next;
				break;
			}
			dp[t][1] += next * p[t][2];
			dp[t][2] += next * p[t][1];
			dp[t][0] += next * p[t][3];
			ans += (1- p[t][0])*next;
			next *= p[t][0];
		}
		next = dp[i][1];
		for(j = a ; j <= b ; j ++){
			int t = i + j;
			if(t > n){
				ans += next;
				break;
			}
			dp[t][2] += next * p[t][1];
			dp[t][0] += next * p[t][3];
			ans += (1- p[t][0]-p[t][2])*next;
			next *= p[t][0]+p[t][2];
		}
		next = dp[i][2];
		for(j = a ; j <= b ; j ++){
			int t = i + j;
			if(t > n){
				ans += next;
				break;
			}
			dp[t][1] += next * p[t][2];
			dp[t][0] += next * p[t][3];
			ans += (1- p[t][0]-p[t][1])*next;
			next *= p[t][0]+p[t][1];
		}
	}
	printf("%lf\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int i,j;
		scanf("%d%d%d",&n,&a,&b);
		for( i = 1;  i<= n ; i ++)
			for(j = 0 ; j < 4 ; j ++)
				scanf("%lf",&p[i][j]);
		solve();
	}
	return 0;

}