#include<stdio.h>
#include<string.h>
#include<time.h>
int a[55][1005], b[55][1005],dp[55][1005];
int Min(int a,int b)
{
	if(a==-1)
		return b;
	else return a<b?a:b;
}
int Abs(int x)
{
	return x>0?x:-x;
}
int main() {
	freopen("data.in","r",stdin);
	freopen("forcedata.out","w",stdout);
	int t, n, m, i, j, k, ans, c;
//	int t1=clock();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &c);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				scanf("%d", &b[i][j]);
			}
		}
		memset(dp,-1,sizeof(dp));
		for(j=0;j<m;++j)
			dp[0][j]=b[0][j]+Abs(a[0][j]-c);
		for(i=1;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				for(k=0;k<m;++k)
					dp[i][k]=Min(dp[i][k],dp[i-1][j]+Abs(a[i-1][j]-a[i][k])+b[i][k]);
			}
		}
		ans=-1;
		for(j=0;j<m;++j)
		{
			ans=Min(ans,dp[n-1][j]);
		}
		printf("%d\n",ans);
	}
//	printf("%d\n",clock()-t1);
}
