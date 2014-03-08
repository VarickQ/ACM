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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 100005;
typedef long long LL;
const LL MOD   = 1000000009;

class matrix{
public:
    LL mat[3][3];
	matrix(){
		memset( mat, 0, sizeof( mat ) );
	}
    matrix identity_matrix(){//单位矩阵
        matrix ret;
		for(int i=0 ; i < 3 ; ++i) ret.mat[i][i] = 1;
        return ret;
    }
    matrix operator * (matrix m){
        matrix ret;
        int i,j,k;
        for(i = 0; i < 3; ++ i){
            for(j = 0; j < 3; ++ j){
                LL c = 0;
                for(k = 0; k < 3; ++ k)
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

LL Fib(LL n){
    if(n <= 1) return 1 % MOD;
    matrix F,t;
	t.mat[0][0]=0;
	t.mat[0][1]=1;
	t.mat[0][2]=2;
	F.mat[0][2]=F.mat[1][2]=F.mat[2][2]=1;
	F.mat[1][0]=F.mat[2][1]=1;
    F = F ^ (n - 3);
	t = t*F;
	return t.mat[0][2] % MOD;
}

int main(){
	LL n;
	while( scanf("%lld", &n) && n ){
		if( n == 1 ) puts("0");
		else if( n == 2 ) puts("1");
		else if( n == 3 ) puts("2");
		else printf("%lld\n", Fib(n) );
	}
	return 0;
}