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
const int N   = 85;

int n,m;
int mat[N][N];
struct A{
	int map[N][N];
}c[N],temp;
void work( int a, int b ){
	int i,j,k;
	bool f;
	for( i=0 ; i < m ; ++i )
		for( j=0 ; j < m ; ++j ){
			temp.map[i][j] = 0;
			for( k=0 ; k < m ; ++k )
				temp.map[i][j] += c[a].map[i][k]*c[b].map[k][j];
		}

	for( i=0 ; i < n ; ++i ){
		if( i==a || i==b ) continue;
		f = false;
		for( j=0 ; j < m ; ++j ){
			for( k=0 ; k < m ; ++k )
				if( c[i].map[j][k] != temp.map[j][k] ){
					f = true; break;
				}
			if( f ) break;
		}
		if( !f ) mat[a][i] = 1;
	}
}
void floyd(){
	int i,j,k;
	for( k=0 ; k < n ; ++k )
		for( i=0 ; i < n ; ++i ){
			if(i==k || mat[i][k] == inf) continue;
			for( j=0 ; j < n ; ++j ){
				if(k==j || i==j || mat[k][j] == inf)
					continue;
				if( mat[i][j] > mat[i][k]+mat[k][j] )
					mat[i][j] = mat[i][k]+mat[k][j];
			}
		}
}
int main(){
	int i,j,k;
	while( scanf("%d%d", &n, &m) && (n+m)){
		for( i=0 ; i < n ; ++i ){
			for( j=0 ; j < n ; ++j )
				mat[i][j] = inf;
			mat[i][i] = 0;
		}
		for( i=0 ; i < n ; ++i )
			for( j=0 ; j < m ; ++j )
				for( k=0 ; k < m ; ++k )
					scanf("%d", &c[i].map[j][k]);
		for( i=0 ; i < n ; ++i )
			for( j=0 ; j < n ; ++j )
				if( i != j ) work( i, j );
		floyd();
		int k;
		scanf("%d", &k);
		while( k-- ){
			scanf("%d%d", &i, &j);
			if( mat[i-1][j-1] < inf )
				printf("%d\n", mat[i-1][j-1]);
			else printf("Sorry\n");
		}
	}
	return 0;
}