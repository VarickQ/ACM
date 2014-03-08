#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define Lowbit(x) ((x)&(-x))
const double eps = 1e-10;
const int inf = 2000000000;
const int M   = 200100;
const int N   = 2005;
typedef long long LL;

int g[N][N], n, m, ans, d[N];
bool vis[N];
void prim(){
	int i, j, Min, mi;
	for( i=0 ; i <= n ; ++i ) d[i] = g[1][i];
	CLR( vis, false );
	vis[1] = true;
	for( i=2 ; i <= n ; ++i ){
		Min = inf; mi = i;
		for( j=2 ; j <= n ; ++j ){
			if( !vis[j] && d[j] < Min )
				Min = d[mi=j];
		}
		if( Min > ans ) ans = Min;
		vis[mi] = true;
		for( j=2 ; j <= n ; ++j )
			if( !vis[j] && d[j] > g[mi][j] )
				d[j] = g[mi][j];
	}
	printf("%d\n", ans);
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	while( scanf("%d%d", &n, &m) != EOF ){
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				g[i][j] = inf;
		int a, b, l;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &l);
			if( g[a][b] > l )
				g[a][b] = g[b][a] = l;
		}
		ans = 0;
		prim();
	}
	return 0;
}