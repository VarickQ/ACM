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
typedef __int64 LL;
const LL N = 2050;
const LL M = 1000000007;
//222222224
//183120
//int main(){
//	LL c, a=0, b=1, ans = 0;
//	while( 1 ){
//		c = ( 3 * b + a ) % M;
//		a = b;
//		b = c;
//		ans++;
//		if( a == 0 && b == 1 ){
//			printf("%I64d\n", ans);
//			break;
//		}
//	}
//	return 0;
//}
struct Matrix
{
	LL Mt[2][2];
	void init0(){memset(Mt, 0, sizeof(Mt));}
	void init1() {init0(), Mt[0][0] = Mt[1][1] = 1;}
	Matrix(){init0();}
	Matrix(LL num) {init0();Mt[0][0] = Mt[1][1] = num;}
	Matrix(LL a, LL b, LL c, LL d){Mt[0][0] = a, Mt[0][1] = b, Mt[1][0] = c, Mt[1][1] = d;}
	Matrix Mul(const Matrix &b, LL mod)
	{
		int i, j, k;Matrix res;
		for(i = 0; i < 2; ++ i)
			for(j = 0; j < 2; ++ j)
				for(k = 0; k < 2; ++ k)
					res.Mt[i][j] = (res.Mt[i][j] + Mt[i][k] * b.Mt[k][j]) % mod;
		return res;
	}
	Matrix Rep(LL p, LL mod)
	{
		Matrix b = *this, res(1);
		if(p == 0) return res;
		if(p == 1) return b;
		while(p > 1)
		{
			if(p & 1) res = res.Mul(b, mod);
			b = b.Mul(b, mod);
			p >>= 1;
		}
		return b.Mul(res, mod);
	}
};
LL gao( LL n, LL Mod ){
	Matrix a(1,0,0,0),b(3,1,1,0);
	if( !n ) return 0;
	return a.Mul( b.Rep(n-1,Mod), Mod ).Mt[0][0];
}
int main(){
	LL n;
	while( ~scanf("%I64d", &n) ){
		printf("%I64d\n",gao(gao(gao(n,183120),222222224),M));
	}
	return 0;
}