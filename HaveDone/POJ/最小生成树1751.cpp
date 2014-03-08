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
const int inf = 1000000000;
const int N   = 1005;

struct node{
	int x, y;
}a[N];

int d[N],mat[N][N];
int n,m,pre[N];
bool mark[N];

void Prim(){
	int i,j,mi,now,Min;
	for( i=1 ; i <= n ; ++i ){
		d[i] = mat[1][i];
		pre[i] = 1;
	}
	mark[1] = true;
	for( i=1 ; i < n ; ++i ){ // i<=n WA
		Min = inf;
		for( j=1 ; j <= n ; ++j ){
			if( !mark[j] && d[j] < Min ){
				Min = d[j];
				mi = j;
			}
		}
		mark[mi] = true;
		if( mat[mi][pre[mi]] )
			printf("%d %d\n", mi, pre[mi]);
		for( j=1 ; j <= n ; ++j ){
			if( !mark[j] && d[j] > mat[mi][j] ){
				pre[j] = mi;
				d[j] = mat[mi][j];
			}
		}
	}
}
int main(){
	int i,j,x,y;

	scanf("%d", &n);
	for( i=1 ; i <= n ; ++i )
		scanf("%d%d", &a[i].x, &a[i].y);
	memset( mark, 0, sizeof( mark ) );
	for( i=1 ; i <= n ; ++i )
		for( j=1 ; j <= i ; ++j )
			mat[i][j] = mat[j][i] = (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);

	scanf("%d", &m);
	for( i=1 ; i <= m ; ++i ){
		scanf("%d%d", &x, &y);
		mat[x][y] = mat[y][x] = 0;
	}
	Prim();

	return 0;
}