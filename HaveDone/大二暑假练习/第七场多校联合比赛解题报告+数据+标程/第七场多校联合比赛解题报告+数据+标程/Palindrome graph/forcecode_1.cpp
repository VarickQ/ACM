#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<iostream>
using namespace std;
typedef pair<int,int> per;
#define mp(x,y) make_pair(x,y)
const int N = 2005;
const int MOD = 100000007;
per sb[N];
int main()
{
	int n,m,k,i;
	freopen("data.in","r",stdin);
	freopen("forcedata_1.out","w",stdout);
	int t1=clock();
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(i=0;i<m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x++;y++;
			if(x>(n+1)/2)x=n-x+1;
			if(y>(n+1)/2)y=n-y+1;
			if(x<y)
			{
				int z=x;
				x=y;
				y=z;
			}
			sb[i].first=x;
			sb[i].second=y;
		}
		sort(sb,sb+m);
		int d=(n+1)/2;
		int r=d*(d+1)/2;
		for(i=0;i<m;i++)
		{
			if(!i||sb[i]!=sb[i-1])r--;
		}
		long long ret=1;
		for(i=0;i<r;i++)ret=ret*k%MOD;
		cout << ret << endl;
	}
	int t2=clock();
	//printf(" time :%d \n",t2-t1);
	return 0;
}
