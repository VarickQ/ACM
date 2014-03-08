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
const int inf = 1000000000;
const int M   = 105;
const int N   = 105;
typedef long long ll;

int n,m,k;
struct Matrix{
	ll row,col;
	ll mat[N][N];
	Matrix(){
		memset( mat, 0, sizeof( mat ) );
	}
}ma,pe;
Matrix initM(){
	Matrix ma;
	ma.col = n+1;
	ma.row = n+1;
	for(int i=0 ; i <= n ; ++i)
		ma.mat[i][i] = 1;
	return ma;
}
Matrix initP(){
	Matrix p;
	p.col = n+1;
	p.row = 1;
	p.mat[0][n] = 1;
	return p;
}
Matrix multiply( Matrix a, Matrix b ){
	int i,j,k;
	Matrix res;
	res.row = a.row;
	res.col = b.col;
	for( i=0 ; i < a.row ; ++i )
		for( j=0 ; j < a.col ; ++j )
			if( a.mat[i][j] )
				for( k=0 ; k < b.col ; ++k )
					res.mat[i][k]+=a.mat[i][j]*b.mat[j][k];
	return res;
}
void solve(){
	while( m ){
		if( m&1 )
			pe = multiply(pe,ma);
		m >>= 1;
		ma = multiply(ma,ma);
	}

	for(int i=0 ; i < n-1 ; ++i)
		printf("%lld ",pe.mat[0][i]);
	printf("%lld\n",pe.mat[0][n-1]);
}
int main(){
	while( scanf("%d%d%d", &n, &m, &k) && (n+m+k) ){
		ma = initM();
		pe = initP();
		char ch[2];
		int x,y;
		while( k-- ){
			scanf("%s", ch);
			if( ch[0] == 'g' ){
				scanf("%d", &x);
				ma.mat[n][x-1]++;
			}
			else if( ch[0] == 'e' ){
				scanf("%d", &x);
				for(int j=0 ; j <= n ; ++j)
					ma.mat[j][x-1] = 0;
			}
			else if( ch[0] == 's' ){
				scanf("%d%d", &x, &y);
				for(int j=0 ; j <= n ; ++j)
					swap(ma.mat[j][x-1],ma.mat[j][y-1]);
			}
		}
		solve();
	}
	return 0;
}