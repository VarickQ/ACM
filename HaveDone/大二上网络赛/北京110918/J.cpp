#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<csetjmp>
#include<bitset>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
#define PI 3.1415926535897932384626433832795028
#define N 100010
#define M 1<<10
#define inf 2000000000
int cost[20],have[20][20];
int add[20][20];
int mark[20],use[20];
int gain[M];
int dp[M][20];
int a[M][20];
int main(){
	int n,m,max1,max2,ans;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(!n&&!m) break;
		ans=0;
		for(int i=0;i<m;++i)
			scanf("%d",&cost[i]);
		for(int i=0;i<n;++i) for(int j=0;j<m;++j)
			scanf("%d",&have[i][j]);
		for(int i=0;i<n;++i) for(int j=0;j<n;++j)
			scanf("%d",&add[i][j]);
		max1=1<<n;
		memset(gain,0,sizeof(gain));
		for(int i=0;i<max1;++i){
			int temp=i,k=0;
			memset(mark,0,sizeof(mark));
			while(temp){
				if(temp&1) mark[k]=1;;
				temp>>=1;
				k++;
			}
			for(int k=0;k<n;++k) for(int j=k+1;j<n;++j)
				if(mark[k]&&mark[j]) gain[i]+=add[k][j];
			for(int j=0;j<m;++j){
				dp[i][j]=gain[i];
				for(int k=0;k<n;++k)
					if(mark[k]) dp[i][j]+=have[k][j]-cost[j];
			}
		}
		ans=0;
		for(int i=0;i<max1;++i) for(int j=0;j<m;++j)
			a[i][j]=-inf;
		for(int i=0;i<max1;++i)
			a[i][0]=dp[i][0];
		for(int j=0;j<m-1;++j){
			for(int i=max1-1;i>=0;--i){
				int temp=i,k=0;
				memset(mark,0,sizeof(mark));
				a[i][j+1]=max(a[i][j]+dp[i][j+1],a[i][j+1]);
				for(int k=0;k<i;++k)
					if((k&i)==k) a[k][j+1]=max(a[i][j]+dp[k][j+1],a[k][j+1]);
			}
		}
		for(int i=0;i<max1;++i) for(int j=0;j<m;++j)
			ans=max(a[i][j],ans);
		if(ans) printf("%d\n",ans);
		else printf("STAY HOME\n");
	}
	return 0;
}