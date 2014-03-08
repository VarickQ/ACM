//1008
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
const int N   = 105;

int mat[N][N],n,m,c;
int v[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
void dfs(int x,int y)
{
	int i,a,b;
	for( i=0 ; i < 8 ; i++ ){
		a = x+v[i][0];
		b = y+v[i][1];
		if(a>=1 && a<=n && b>=1 && b<=m && mat[a][b]==1)
		{
			mat[a][b] = 0;
			dfs(a,b);
		}
	}
}
int main(){
	char ch;
	while(scanf("%d%d", &n, &m) && (n+m)){
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= m ; ++j){
				scanf(" %c", &ch);
				if( ch == '*' ) mat[i][j] = 0;
				else mat[i][j] = 1;
			}
		c = 0;
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= m ; ++j)
				if( mat[i][j] ){
					dfs( i, j ); c++;
				}
		printf("%d\n", c);
	}
	return 0;
}
//1006
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
const int N   = 20;

int a[22],n,vis[22];
bool su(int n){
	int i;
	for(i=2 ; i*i <= n ; ++i)
		if( n%i == 0 ) break;
	if( i*i > n ) return true;
	return false;
}
void dfs( int c ){
	if( c==n && su(a[0]+a[n-1]) ){
		for(int i=0 ; i < n-1 ; ++i)
			printf("%d ", a[i]);
		printf("%d\n", a[n-1]);
	} else {
		for(int i=2 ; i <= n ; ++i)
			if( !vis[i] && su(a[c-1]+i)){
				a[c] = i;
				vis[i] = 1;
				dfs( c+1 );
				vis[i] = 0;
			}
	}
}
int main(){
	int cs=1;
	while(scanf("%d", &n) == 1){
		printf("Case %d:\n", cs++);
		a[0] = 1;
		memset( vis, 0, sizeof( vis ) );
		dfs( 1 );
		printf("\n");
	}
	return 0;
}
//1007
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
//1001 ฒน
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