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
#define Lowbit(x) ((x)&(-x))
const double eps = 1e-10;
const int inf = 1000000000;
const int M   = 200000;
const int N   = 25;
typedef long long LL;

int a[N];
double dp[N][M];
inline double val(int a,int b){
	return fabs(a-b+0.0)/a;
}
int main(){
	int n;
	while( scanf("%d", &n) != EOF ){
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &a[i]);
		}
		sort( a, a+n );
		for(int i=0 ; i < n ; ++i)
			for(int j=1 ; j <= M ; ++j)
				dp[i][j] = 1.0;
		for(int i=1 ; i <= M ; ++i)
			dp[n-1][i] = val(a[n-1],i);
		for(int i=n-2 ; i >= 0 ; --i)
			for(int j=1 ; j <= M ; ++j){
				double tmp = val(a[i],j);
				for(int k=1 ; k*j <= M ; ++k)
					dp[i][j] = min(dp[i][j] ,max( tmp, dp[i+1][k*j]) );
			}
		double ans = 1.0;
		for(int i=1 ; i <= M ; ++i)
			ans = min(ans,dp[0][i]);
		printf("%.12lf\n", ans);
	}
	return 0;
}