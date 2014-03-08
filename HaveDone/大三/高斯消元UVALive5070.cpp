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
const int inf = 1000000000;
const int N = 999;

int g[N][N];
bool guass( int n ){
	int c = 0, r = 0;
	for( ; r < n && c < n ; ++r, ++c ){
		int id = r;
		if( !g[r][c] ){
			for(int i=r+1 ; i < n ; ++i){
				if( g[i][c] ){
					id = i; break;
				}
			}
		}
		if( id != r ){
			for(int i=c ; i <= n ; ++i)
				swap( g[r][i], g[id][i] );
		}
		if( !g[r][c] ){
			--r; continue;
		}
		for(int i=r+1 ; i < n ; ++i){
			if( !g[i][c] ) continue;
			for(int j=c+1 ; j <= n ; ++j)
				g[i][j] ^= g[r][j];
		}
	}
	for(int i=r ; i < n ; ++i)
		if( g[i][n] ) return 0;
	return 1;
}
int main() {
	int n, m, d, x;
	while( scanf("%d%d%d", &m, &n, &d) && (n+m+d) ){
		memset( g, 0, sizeof( g ) );
		for(int i=0 ; i < n ; ++i){
			for(int j=0 ; j < m ; ++j){
				scanf("%d", &x);
				g[i*m+j][n*m] = (x==1);
			}
		}
		for(int i=0 ; i < n ; ++i){
			for(int j=0 ; j < m ; ++j){
				g[i*m+j][i*m+j] = true;
				for(int k=0 ; k < n ; ++k){
					for(int p=0 ; p < m ; ++p){
						if( abs(k - i) + abs(p - j) == d ){
							g[i*m+j][k*m+p] = true;
						}
					}
				}
			}
		}
		if( guass(n*m) ) puts("1");
		else puts("0");
	}
	return 0;
}