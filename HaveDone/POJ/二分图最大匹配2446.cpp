#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 100000000;
const int M   = 35000;
const int N   = 1030;
typedef long long ll;

int mat[N][N],match[N],id[N][N];
bool vis[N],mark[N][N];
int n,m,k,dd;
bool find(int i){
	for(int j=1 ; j <= dd ; ++j){
		if( mat[i][j] && !vis[j] ){
			vis[j] = true;
			if( match[j]==0 || find(match[j]) ){
				match[j] = i;
				return true;
			}
		}
	}
	return false;
}
int v[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool check( int x, int y ){
	if( x>0&&x<=n && y>0&&y<=m && !mark[x][y] )
		return true;
	return false;
}
int main(){
	while( scanf("%d%d%d", &n,&m,&k) == 3 ){
		if( (n*m-k)%2 ) printf("NO\n");
		else {
			memset( mat, 0, sizeof( mat ) );
			memset( mark, 0, sizeof( mark ) );
			int a,b;
			for(int i=0 ; i < k ; ++i){
				scanf("%d%d", &b, &a);
				mark[a][b] = true;
			}
			dd = 0;
			for(int i=1 ; i <= n ; ++i)
				for(int j=1 ; j <= m ; ++j)
					if( !mark[i][j] )
						id[i][j] = ++dd;
			for(int i=1 ; i <= n ; ++i)
				for(int j=1 ; j <= m ; ++j)
					if( !mark[i][j] ){
						int x,y;
						for(int o=0 ; o < 4 ; ++o){
							x = i+v[o][0];
							y = j+v[o][1];
							if( check(x,y) )
								mat[id[i][j]][id[x][y]] = 1;
						}
					}
			memset( match, 0, sizeof( match ) );
			int ans = 0;
			for(int i=1 ; i <= dd ; ++i)
			{
				memset( vis, 0, sizeof( vis ) );
				if( find(i) ) ans++;
			}
			if(ans+k == n*m)
				printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}