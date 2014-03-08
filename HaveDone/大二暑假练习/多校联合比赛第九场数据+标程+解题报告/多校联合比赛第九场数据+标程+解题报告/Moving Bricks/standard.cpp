#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 1e8
using namespace std;

int x[20], y[20];
int dis[20][20];
int dp[1<<20];
int pre[1<<20];
struct node
{
	int a, b;
}ans[20];

bool mycmp(node a, node b)
{
	return a.a < b.a;
}

int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int t, n, a, b, ca = 0;
    scanf("%d",&t);
    while(t --)
    {
    	ca ++;
    	printf("Case %d:\n",ca);
        scanf("%d%d%d",&a,&b,&n);
        for(int i = 0; i < n; i ++)
            scanf("%d%d",&x[i],&y[i]);
        x[n] = a;
        y[n] = b;
        for(int i = 0; i <= n; i ++)
            for(int j = 0; j <= n; j ++)
                if(i != j)
                    dis[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        for(int i = 1; i < (1 << n); i ++)
            dp[i] = inf;
        dp[0] = 0;
        for(int i = 0; i < (1<<n); i ++)
        {
            for(int j = 0; j < n; j ++)
                if(!(i&(1<<j)))
                {
                    int t = i | (1<<j);
                    int l = dp[i] + dis[n][j] + dis[j][n];
                    if(dp[t] > l)
                    {
                    	dp[t] = l;
						pre[t] = i;
                    }
                    for(int k = j + 1; k < n; k ++)
                    if(!(t&(1<<k)))
					{
						int p = t | (1<<k);
						l = dp[i] + dis[n][j] + dis[j][k] + dis[k][n];
						if(dp[p] > l)
						{
							dp[p] = l;
							pre[p] = i;
						}
					}
                }
        }
        int t = 0;
        int m = (1<<n)-1;
        printf("%d\n",dp[m]);
        while(m)
        {
            bool tag = false;
            int temp = m ^ pre[m];
            ans[t].b = 30;
            for(int i = 0; i < n; i ++)
                if((temp>>i)&1)
				{
					if(!tag)
					{
						ans[t].a = i;
						tag = true;
					}
					else ans[t].b = i;
				}
            m = pre[m];
            t ++;
        }
        sort(ans, ans + t, mycmp);
        for(int i = 0; i < t; i ++)
		{
            if (i) printf(" ");
			printf("%d",ans[i].a + 1);
			if(ans[i].b < 30) printf(" %d",ans[i].b + 1);
		}
        puts("");
    }
    return 0;
}
