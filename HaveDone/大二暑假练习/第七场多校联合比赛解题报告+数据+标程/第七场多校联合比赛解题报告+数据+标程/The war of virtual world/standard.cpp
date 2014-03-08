#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
typedef long long LL ;
typedef double db;
const int PP = 1000000007;
const db EPS = 1e-8;
const db PI = acos(- 1.0) ;
const int maxn  = 505;
int sign(db x){return x < - EPS ? - 1 : x > EPS ;}
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
}P[maxn], tP[maxn];
struct Pair {
	double first;
	int second;
	Pair(double a = 0.0, int i = 0) : first(a), second(i) {}
};
inline bool operator < (const Pair& lhs, const Pair& rhs) {
	return lhs.first < rhs.first;
}
int f[maxn][maxn], s[maxn][maxn];
Pair pnt[maxn];
int n;
inline int g(int x,int y,int z){
    //y -> z
    if(f[x][y] > f[x][z]) return f[x][y] - f[x][z] - 1;
    return n - 2 - f[x][z] + f[x][y];
}
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
int get(){
    if(scanf("%d",&n)==EOF)return 0;
    int i;
    for(i =0 ; i< n; ++ i) P[i].get(),tP[i] = P[i] ;
    return 1;
}
void work(){
    int i,j,k;
	int i0, j0, k0;
    for(i = 0; i < n; ++ i){
        for(j = 0; j < n; ++ j) P[j] = tP[j];
        if(i) swap(P[0], P[i]) ;
        for(j = 1; j < n; ++ j) pnt[j - 1] = Pair( (atan2((db)P[j].y - P[0].y, (db)P[j].x - P[0].x)) ,j == i ? 0 : j) ;
        sort(pnt,pnt+n-1);
        for(j = 0; j < n - 1; ++ j) f[i][ pnt[j].second ] = (n - 1 - j) ;
        for(j = k = 0; j < n - 1; ++ j){
            if(pnt[j].first > EPS) break ;
            db r = pnt[j].first + PI ;
			while(k < n - 1 && !(pnt[ k ].first > r) ) ++ k;
            s[i][pnt[j].second] = n - 1 - k + j;
            s[pnt[j].second][i] = n - 2 - ( n - 1 - k + j);
        }
    }
    int in3;
	LL ans = 1;
	for(i = 0; i < n; ++ i) P[i] = tP[i];
	for(i0 = 0; i0 < n; ++ i0)
		for(j0 = i0 + 1; j0 < n; ++ j0){
			in3 = 0;
			for(k0 = 0; k0 < n; ++ k0) if(i0!= k0 && j0 != k0){
				i = i0; j = j0; k = k0;
				if((P[i] - P[k]).X(P[j] - P[k]) < 0) swap(i, j) ;
				int tmp  = g(i, j, k) + g(j, k, i)+ g(k, i, j);
				tmp += s[i][j] + s[j][k] + s[k][i];
				tmp -= 2 * (n - 3) ;
				in3 += g( k, i, j ) - tmp;
			}
			in3 >>= 1; 
			ans = (LL) ans * gao( in3) % PP;
		}
	printf("%lld\n", ans);
}
int main(){
    int tt = clock();
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
    while(get()){
        work();
        cerr <<"times = " << clock()-tt <<" ms " << endl; 
    }	
    return 0;
}
