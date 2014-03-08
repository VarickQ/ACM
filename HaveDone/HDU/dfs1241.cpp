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