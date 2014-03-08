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
typedef __int64 ll;
const int inf = 2000000000;
const int N   = 22;

int n,m,mat[N][N];
int sx,sy,ex,ey,ans;
int v[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool check( int x, int y ){
	if(x>=1 && x<=n && y>=1 && y<=m)
		return true;
	return false;
}
void dfs( int x, int y, int c){
	if( c >= ans ) return;
	int tx,ty;
	for(int i=0 ; i < 4 ; ++i){
		if( check( x+v[i][0], y+v[i][1] ) && mat[x+v[i][0]][y+v[i][1]]!=1 ){
			for(int j=1 ; check( x+v[i][0]*j, y+v[i][1]*j ) ; ++j ){
				tx = x+v[i][0]*j;
				ty = y+v[i][1]*j;
				if( mat[tx][ty] == 1 ){
					mat[tx][ty] = 0;
					dfs( tx-v[i][0], ty-v[i][1], c+1 );
					mat[tx][ty] = 1;
					break;
				}
				if( mat[tx][ty] == 3){
					if(ans > c+1) ans = c+1;
					return;
				}
			}
		}
	}
}
int main(){
	while(scanf("%d%d", &m, &n) && (n+m)){
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= m ; ++j){
				scanf("%d", &mat[i][j]);
				if(mat[i][j] == 2){
					sx = i; sy = j;
					mat[i][j] = 0;
				}
				else if(mat[i][j] == 3){
					ex = i; ey = j;
				}
			}
		ans = 11;
		dfs( sx, sy, 0 );
		if( ans == 11 ) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}