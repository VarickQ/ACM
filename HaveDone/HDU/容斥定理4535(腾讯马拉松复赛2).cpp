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
typedef __int64 LL;
const LL MOD = 1000000007;
const int N = 105;

LL f[N];
LL c[N][N];
void CC(){
    for(int i=1; i <= 100; ++i){
        c[i][0] = c[i][i] = 1;
        for(int j=1; j < i; ++j)
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%MOD;
    }
}
int main(){
    CC();
    int T, n;
    f[0] = 1;
    f[1] = 1;
    for(int i=2 ; i <= 100 ; ++i)
        f[i] = (f[i-1]*i)%MOD;
    scanf("%d", &T);
    while( T-- ){
        scanf("%d", &n);
        LL ans = f[n];
        for(int i=1 ; i <= n ; ++i){
            if(i&1) ans = (ans-(c[n][i]*f[n-i])%MOD+MOD)%MOD;
            else ans = (ans+(c[n][i]*f[n-i])%MOD)%MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}