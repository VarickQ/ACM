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
const int inf = 2000000000;
const int N   = 105;

int mat[N][N];
int m,n,d[N],vis[N];
void dijkstra(){
	memset(vis,0,sizeof(vis));
	for(int i=1 ; i <= n ; i++) d[i] = inf;
	d[1] = 0;
	for(int i=1 ; i <= n ; i++)
	{
		int x,Min = inf;
		for(int y=1 ; y <= n ; y++)
			if(!vis[y] && d[y] <= Min){
				Min = d[y];
				x = y;
			}
		vis[x] = true;
		for(int y=1 ; y <= n ; y++)
			if(!vis[y] && d[x]+mat[x][y] < d[y])
				d[y] = d[x] + mat[x][y];
	}
}
int main(){
	int a,b,c;
	while( scanf("%d%d", &n, &m) && (n+m) ){
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				mat[i][j] = inf;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			if( mat[a][b] > c )
				mat[a][b] = mat[b][a] = c;
		}
		dijkstra();
		printf("%d\n", d[n]);
	}
	return 0;
}