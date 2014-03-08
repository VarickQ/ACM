#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
const int N = 50;

int g[N][N];
int a[N], b[N];
int guass( int n ){
	int c = 0, r = 0;
	for( ; r < n && c < n ; ++r, ++c ){
		int id = r;
		if( !g[r][c] ){
			for(int i=r+1 ; i < n ; ++i)
				if( g[i][c] ){
					id = i; break;
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
		if( g[i][n] ) return -1;
	if( r == n ) return 1;
	return (1 << (n - r));
}
int main(){
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		memset( g, 0, sizeof( g ) );
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i) scanf("%d", &a[i]);
		for(int i=0 ; i < n ; ++i) scanf("%d", &b[i]);
		int u, v;
		while( scanf("%d%d", &u, &v) && (u+v) )
			g[v-1][u-1] = true;
		for(int i=0 ; i < n ; ++i){
			g[i][i] = true;
			g[i][n] = a[i]^b[i];
		}
		int ans = guass( n );
		if( ans == -1 ) printf("Oh,it's impossible~!!\n");
		else printf("%d\n", ans);
	}
	return 0;
}
