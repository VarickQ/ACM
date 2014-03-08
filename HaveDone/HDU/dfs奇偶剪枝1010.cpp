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
const int N   = 10;

int mat[N][N],n,m,t;
bool vis[N][N],ans;
int v[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void dfs( int x, int y, int c ){
	int a,b;
	if( ans ) return ;
	for(int i=0 ; i < 4 ; ++i){
		a = x+v[i][0];
		b = y+v[i][1];
		if(a>=1 && a<=n && b>=1 && b<=m && mat[a][b]!=1 && !vis[a][b]){
			vis[a][b] = true;
			if( mat[a][b]==2 && c+1 == t ){
				ans = true; return ;
			}
			dfs( a, b, c+1 );
			if( ans ) return;
			vis[a][b] = false;
		}
	}
}
int main(){
	char ch;
	int num,sx,sy,ex,ey;
	while(scanf("%d%d%d",&n,&m,&t) && (n+m+t)){
		memset( vis, 0, sizeof( vis ) );
		num = 1;
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= m ; ++j){
				scanf(" %c", &ch);
				if(ch == 'S') {
					sx = i; sy = j;
					mat[i][j] = -1;
				}
				else if( ch == '.' ){
					mat[i][j] = 0;
					num++;
				}
				else if( ch == 'X')
					mat[i][j] = 1;
				else if( ch == 'D' ){
					ex = i; ey = j;
					mat[i][j] = 2;
				}
			}
		if(num < t){
			printf("NO\n"); continue;
		}
		ans = false;
		vis[sx][sy] = true;
		if( (abs(sx-ex)+abs(sy-ey))%2 == t%2 )
			dfs( sx, sy, 0 );

		if( ans ) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}