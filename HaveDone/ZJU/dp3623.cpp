#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N = 400;
const int inf = 1000000000;
typedef long long LL;

struct Node{
	int t,d;
}a[N];
int dp[N][1010];
//dp[i][j],当前打掉i的hp,当前攻击力为j的情况下的最小时间
int main(){
	int n, m;
	while( scanf("%d%d", &n, &m) != EOF ){
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d", &a[i].t, &a[i].d);
		for(int i=0 ; i <= m ; ++i)
			for(int j=0 ; j < 1000 ; ++j)
				dp[i][j] = inf;
		dp[0][0] = 0;
		for(int i=0 ; i <= m ; ++i)
			for(int j=0 ; j < 1000 ; ++j)
				for(int k=0 ; k < n ; ++k)
					if( j>=a[k].d && i>=a[k].t*(j-a[k].d) )
						dp[i][j] = min(dp[i][j],dp[i-a[k].t*(j-a[k].d)][j-a[k].d]+a[k].t);
		int ans = inf;
		for(int i=0 ; i <= m ; ++i)
			for(int j=1 ; j < 1000 ; ++j){//不造的时候，放在最后，直接打
				int t = (m-i)/j;
				if( (m-i)%j ) t++;
				ans = min( dp[i][j]+t, ans );
			}
		printf("%d\n", ans);
	}
    return 0;
}