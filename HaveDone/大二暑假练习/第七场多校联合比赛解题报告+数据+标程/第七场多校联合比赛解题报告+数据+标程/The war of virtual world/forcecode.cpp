#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
typedef long long LL ;
const int PP = 1000000007;
typedef double db;
const db EPS = 1e-8;
const db PI = acos(- 1.0) ;
const int maxn  = 1005;
inline int sign(LL x){return x < 0 ? - 1 : x > 0 ;}
LL powmod( LL a, int b, int c){
	LL ret = 1;
	while(b) {
		if(b&0x1) ret = ret * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return ret;
}
struct Mat{
	LL mat[ 3 ] [ 3 ] ;
	Mat operator*(const Mat M ) {
		int i, j, k;
		Mat ret ;
		for(i = 0; i< 2; ++ i) for(j = 0; j < 2; ++ j){
			ret.mat[i ][j] =0;
			for(k = 0; k < 2; ++ k) ret.mat[i][j] += mat[i][k] * M.mat[k][j], ret.mat[i][j] %= PP - 1;
		}
		return ret;
	}
	Mat operator^(int k) {
		Mat ret = *this, a = *this;
		-- k;
		while( k ) {
			if( k & 0x1) ret = ret * a;
			a = a * a;
			k >>= 1;
		}
		return ret;
	}
};

inline int Fib( int k) {
	if(k == 0) return 1;
	if(k == 1) return 1;
	Mat m;
	m.mat[0][0] = m.mat[0][1] = m.mat[1][0] = 1;
	m.mat[1][1] = 0;
	m = (m ^ ( k - 1));
	return ( m.mat[0][0] + m.mat[0][1] ) % (PP - 1);
}
int gao( int Ki) {
	// Ki^Fib( Ki ) mod  P
	// Fib( Ki) mod (P - 1)
	return (powmod( Ki, Fib( Ki ) , PP ) + 1) % PP;
}
inline int readT(){
	int ret = 0, sgn = 1; char c;
	while(c = getchar(), c != '-' && (c < '0' || c > '9'));
	if(c == '-') sgn = - 1; else ret = c - 48;
	while(c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
	return sgn == 1 ? ret : - ret;
}
struct TPoint{
    int x,y;
    TPoint(){}
    TPoint(int xx,int yy):x(xx),y(yy){}
    TPoint operator-(const TPoint P){return TPoint(x - P.x, y - P.y);}
    LL X(TPoint P){return (LL)x * P.y - (LL)y * P.x;}
    void get(){x = readT(); y = readT();}
}P[maxn];

int n;
int get(){
    if(scanf("%d",&n)==EOF)return 0;
    int i;
    for(i  =0 ; i< n; ++ i) P[i].get();
    return 1;
}
inline bool chk( TPoint a, TPoint b, TPoint c, TPoint d) {
	return sign((a - c).X(b - c)) * sign((a - d).X(b - d)) <= 0 &&
		sign((c - a).X(d - a)) * sign((c - b).X(d - b)) <= 0;
}

void work(){
    int i,j,k,l, tmp;
	LL ans = 1;
	for(i = 0; i < n; ++ i)
		for(j = i + 1; j < n; ++ j){
			tmp = 0;
			for(k = 0; k < n; ++ k) if( k != i && k != j) {
				for(l = k + 1; l < n; ++ l) if( l != i && l != j && chk( P[i], P[j], P[k], P[l]) ) ++ tmp; 
			}
			ans = ans *  gao( tmp ) % PP;
			//cout << tmp << endl;
		}
	printf("%lld\n", ans );
}
int main(){
    int tt = clock();
	freopen("data.in","r",stdin);
	freopen("forcedata.out","w",stdout);
	while(get()){
       work();
	   cerr <<"times = " << clock()-tt <<" ms " << endl; 
    }
    return 0;
}
