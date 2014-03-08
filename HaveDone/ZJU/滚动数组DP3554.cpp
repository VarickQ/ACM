#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int M = 10100;
const int N = 121;

bool dp[2][N][N][N];
int a[N],b[N],c[N];
int main(){
	int n,x,y,z;
	while(scanf("%d",&n) == 1){
		memset(dp,0,sizeof(dp));
		x = y = z = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			x += a[i];
			y += b[i];
			z += c[i];
		}
		int t = 1;//int u,v;
		dp[1][0][0][0] = true;
		for(int w=0 ; w < n ; ++w){
			t = 1-t;//u = w&1; v = u^1;
			memset(dp[t],0,sizeof(dp[t]));//dp[u]
			for(int i=0 ; i <= x ; ++i)
				for(int j=0 ; j <= y ; ++j)
					for(int k=0 ; k <= z ; ++k){
						if(i>=a[w]&&dp[1-t][i-a[w]][j][k]||//dp[v]
							j>=b[w]&&dp[1-t][i][j-b[w]][k]||
							k>=c[w]&&dp[1-t][i][j][k-c[w]])
							dp[t][i][j][k] = true;//dp[u]
					}
		}
		int res = 0;
		for(int i=1 ; i <= 120 ; ++i)
			if(dp[t][i][i][i]){//dp[u]
				res = i; break;
			}
		if(res) printf("%d\n",res);
		else printf("NO\n");
	}
	return 0;
}