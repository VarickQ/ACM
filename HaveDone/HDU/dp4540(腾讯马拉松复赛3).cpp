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
typedef long long LL;
const double eps = 1e-8;
const LL MOD = 1000000007;
const int inf = 1000000000;
const int M = 10005;
const int N = 25;

int a[N][N], dp[N][505];
int main(){
    int n, m;
    while( scanf("%d%d", &n, &m) != EOF ){
        for(int i=1 ; i <= n ; ++i){
            for(int j=1 ; j <= m ; ++j)
                scanf("%d", &a[i][j]);
            for(int j=0 ; j <= 500 ; ++j)
                dp[i][j] = inf;
        }
        for(int i=1 ; i <= m ; ++i)
            dp[1][a[1][i]] = 0;
        for(int i=1 ; i <= n ; ++i){
            for(int j=1 ; j <= m ; ++j){
                for(int k=1 ; k <= m ; ++k)
                    dp[i][a[i][j]] = min( dp[i][a[i][j]], dp[i-1][a[i-1][k]]+abs(a[i][j]-a[i-1][k]));
            }
        }
        int ans = inf;
        for(int i=1 ; i <= m ; ++i)
            ans = min( ans, dp[n][a[n][i]] );
        printf("%d\n", ans);
    }
    return 0;
}