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
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 55;
typedef long long ll;

int mat[N][N],cnt;
bool vis[N][N];
void dfs(int i,int j){
	if( !vis[i][j] ){
		vis[i][j] = true;
		cnt++;
		if( !(mat[i][j]&1) ) dfs(i,j-1);
		if( !(mat[i][j]&2) ) dfs(i-1,j);
		if( !(mat[i][j]&4) ) dfs(i,j+1);
		if( !(mat[i][j]&8) ) dfs(i+1,j);
	}
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int m,n;
	while( scanf("%d%d", &m, &n) != EOF ){
		CLR( mat, 0 );
		for(int i=1 ; i <= m ; ++i)
			for(int j=1 ; j <= n ; ++j)
				scanf("%d", &mat[i][j]);
		CLR( vis, 0 );
		int ans = 0, r = 0;
		for(int i=1 ; i <= m ; ++i)
			for(int j=1 ; j <= n ; ++j){
				cnt = 0;
				if( !vis[i][j] )
					dfs(i,j);
				if( cnt != 0 ) r++;
				if( cnt > ans ) ans = cnt;
			}
		printf("%d\n%d\n", r, ans);
	}
	return 0;
}