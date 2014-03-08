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
#define Lowbit(x) ((x)&(-x))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 2007;
const int N   = 11;
typedef long long LL;

/*
第二类斯特林数
将n个元素划分为k个非空集合
S(n, m) = m * S(n - 1, m) + S(n - 1, m - 1)
*/
LL mat[N][N],res[N][N],tmp[N][N],n,m;
void multi(LL a[][N], LL b[][N], LL c[][N]){
	memset( tmp, 0, sizeof( tmp ) );
	LL i, j, k;
	for( i=1 ; i <= m ; ++i )
		for( j=1 ; j <= m ; ++j )
			for( k=1 ; k <= m ; ++k )
				tmp[i][j] = (tmp[i][j]+(a[i][k]*b[k][j])%M)%M;
	for( i=1 ; i <= m ; ++i )
		for( j=1 ; j <= m ; ++j )
			c[i][j] = tmp[i][j];
}
void solve(LL n){
	while( n ){
		if( n&1 ) multi( mat, res, res );//res=res*mat;
		multi(mat,mat,mat);//mat=mat*mat;
		n >>= 1;
	}
}
LL stirling2( LL n, LL m ){
	memset( res, 0, sizeof( res ) );
	memset( mat, 0, sizeof( mat ) );
	mat[1][1] = res[1][1] = 1;
	for(int i=2 ; i <= m ; ++i){
		mat[i][i-1] = res[i][i] = 1;
		mat[i][i] = i;
	}
	solve(n-1);
	return res[m][1]%M;
}
int main(){
	while( ~scanf("%I64d%I64d", &n, &m) ){
		printf("%I64d\n",stirling2(n,m));
	}
	return 0;
}