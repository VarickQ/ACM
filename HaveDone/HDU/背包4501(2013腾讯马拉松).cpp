#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 105;
typedef long long LL;

struct Node{
	int p,c,val;
}a[N];
int dp[N][N][N][6];
int main(){
	int n, v1, v2, K;
	while( scanf("%d%d%d%d",&n,&v1,&v2,&K) != EOF ){
		for(int i=1 ; i <= n ; ++i)
			scanf("%d%d%d",&a[i].p,&a[i].c,&a[i].val);
		memset( dp, 0, sizeof( dp ) );
		for(int i=1 ; i <= n ; ++i){
			for(int j=0 ; j <= v1 ; ++j){
				for(int k=0 ; k <= v2 ; ++k){
					for(int q=0 ; q <= K ; ++q){
						dp[i][j][k][q] = dp[i-1][j][k][q];
						if( j >= a[i].p )
							dp[i][j][k][q]=max(dp[i][j][k][q],dp[i-1][j-a[i].p][k][q]+a[i].val);
						if( k >= a[i].c )
							dp[i][j][k][q]=max(dp[i][j][k][q],dp[i-1][j][k-a[i].c][q]+a[i].val);
						if( q > 0 )
							dp[i][j][k][q]=max(dp[i][j][k][q],dp[i-1][j][k][q-1]+a[i].val);
					}
				}
			}
		}
		printf("%d\n", dp[n][v1][v2][K]);
	}
	return 0;
}