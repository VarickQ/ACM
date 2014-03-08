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
const int N   = 105;

struct node{
	double x, y;
}a[N];
int n;
double mat[N][N],d[N];
bool mark[N];
double dis( node a, node b ){
	return  sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void Prim(){
	int i,j,mi;
	double Min,sum=0;
	for( i=1 ; i <= n ; ++i )
		d[i] = mat[i][1];
	mark[1] = true;
	for( i=1 ; i < n ; ++i ){
		Min = inf; mi = i;
		for( j=1 ; j <= n ; ++j ){
			if( !mark[j] && d[j] < Min ){
				Min = d[j];
				mi = j;
			}
		}
		sum += Min;
		mark[mi] = true;
		for( j=2 ; j <= n ; ++j )
			if( !mark[j] && d[j] > mat[mi][j] )
				d[j] = mat[mi][j];
	}
	printf("%.2lf\n", sum);
}
int main(){
	while( scanf("%d", &n) == 1 ){
		memset( mark, 0, sizeof( mark ) );
		for(int i=1 ; i <= n ; ++i)
			scanf("%lf%lf", &a[i].x, &a[i].y);
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= i ; ++j)
				mat[i][j] = mat[j][i] = dis( a[i], a[j] );
		Prim();
	}
	return 0;
}