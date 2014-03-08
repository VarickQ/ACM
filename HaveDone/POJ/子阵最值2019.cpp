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
const double eps = 1e-8;
const int inf = 1000000000;
const int N   = 255;
typedef long long ll;

int dp[N][N][2],a[N][N];
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int n,b,k;
	while( scanf("%d%d%d", &n, &b, &k) != EOF ){
		CLR( dp, 0 );
		for(int i=1 ; i <= n ; ++i){
			for(int j=1 ; j <= n ; ++j){
				scanf("%d", &a[i][j]);
				dp[i][j][0] = inf;
				if( j >= b )
					for(int p=j-b+1 ; p <= j ; ++p){
						dp[i][j][0] = min(dp[i][j][0],a[i][p]);
						dp[i][j][1] = max(dp[i][j][1],a[i][p]);
					}
			}
		}
		int x, y;
		while( k-- ){
			scanf("%d%d", &x, &y);
			y = y+b-1;
			int Min = inf,Max = 0;
			for(int i=x ; i < x+b ; ++i){
				Min = min(Min,dp[i][y][0]);
				Max = max(Max,dp[i][y][1]);
			}
			printf("%d\n", Max - Min);
		}
	}
	return 0;
}