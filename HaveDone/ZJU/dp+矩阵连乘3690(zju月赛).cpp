/*
dp[i][0]表示第i个位置取 <= k 的值
dp[i][1]表示第i个位置取 > k 的值
dp[i][0] = dp[i-1][0] * k-1 + dp[i-1][1] * k;
dp[i][1] = dp[i-1][0] * (m - k) + dp[i-1][1] * (m - k);
由于n很大，要用到矩阵连乘。
*/
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
const LL MOD = 1000000007;
const int M = 10005;
const int N = 400005;

class matrix{
public:
    LL mat[2][2];
	matrix(){
		memset( mat, 0, sizeof( mat ) );
	}
    matrix identity_matrix(){//单位矩阵
        matrix ret;
		for(int i=0 ; i < 2 ; ++i) ret.mat[i][i] = 1;
        return ret;
    }
    matrix operator * (matrix m){
        matrix ret;
        int i,j,k;
        for(i = 0; i < 2; ++ i){
            for(j = 0; j < 2; ++ j){
                LL c = 0;
                for(k = 0; k < 2; ++ k)
                c = (c + (LL)mat[i][k] * m.mat[k][j] % MOD) % MOD;
                ret.mat[i][j] = c;
            }
        }
        return ret;
    }
    matrix operator ^ (LL k){//高效幂
        if(k == 0) return identity_matrix();     
        matrix ret = * this, a = ret;
        --k;
        while(k){
            if(k & 1) ret = ret * a;
            a = a * a;
            k >>= 1;
        }
        return ret;
    }
};
LL solve( LL n, LL m, LL k ){
	matrix F, t;
	t.mat[0][0] = k;
	t.mat[0][1] = m - k;
	F.mat[0][0] = k - 1;
	F.mat[1][0] = k;
	F.mat[0][1] = F.mat[1][1] = m - k;
	F = F ^ (n - 1);
	t = t * F;
	return (t.mat[0][0] + t.mat[0][1]) % MOD;
}
int main(){
	LL n, m, k;
	while( scanf("%lld%lld%lld", &n, &m, &k) != EOF ){
		printf("%lld\n", solve( n, m, k ));
	}
	return 0;
}