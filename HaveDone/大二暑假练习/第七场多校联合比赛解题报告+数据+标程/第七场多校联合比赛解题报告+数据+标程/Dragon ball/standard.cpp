#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1005;
const int M = 52;
const int INF = 2000000011;
struct P
{
    int p,e;
}data[M][N];
bool cmp(P a,P b)
{
    return a.p<b.p;
}
int dp[M][N],q[N],top,tail;
int abs(int x){return x>0?x:-x;}
int cost(int i,int k,int j)
{
    return dp[i-1][k]+abs(data[i-1][k].p-data[i][j].p);
}
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data1.out", "w", stdout);
    int T,m,n,l,i,j,k,t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&m,&n,&l);
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&data[i][j].p);
            }
        }
		for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&data[i][j].e);
            }
            sort(data[i]+1,data[i]+1+n,cmp);
        }
        for(i=1;i<=n;i++)dp[1][i]=abs(l-data[1][i].p)+data[1][i].e;
        for(i=2;i<=m;i++)
        {
            top=0;
            tail=-1;
            for(k=j=1;j<=n;j++)
            {
                dp[i][j]=INF;
                while(k<=n&&data[i-1][k].p<=data[i][j].p)
                {
                    t=cost(i,k,j);
                    while(tail>=top&&cost(i,q[tail],j)>=t)tail--;
                    q[++tail]=k;
                    k++;
                }
                if(tail>=top)dp[i][j]=cost(i,q[top],j);
            }
            top=0;
            tail=-1;
            for(k=j=n;j>0;j--)
            {
                while(k>0&&data[i-1][k].p>data[i][j].p)
                {
                    t=cost(i,k,j);
                    while(tail>=top&&cost(i,q[tail],j)>=t)tail--;
                    q[++tail]=k;
                    
                    k--;
                }
                if(tail>=top)
                {
                    t=cost(i,q[top],j);
                    if(dp[i][j]>t)dp[i][j]=t;
                }
            }
            for(j=1;j<=n;j++)dp[i][j]+=data[i][j].e;
        }
        t=INF;
        for(i=1;i<=n;i++)if(t>dp[m][i])t=dp[m][i];
        printf("%d\n",t);
    }
    return 0;
}
