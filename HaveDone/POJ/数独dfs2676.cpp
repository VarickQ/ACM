#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-8;
const int inf = 1000000000;
const int M = 6050000;
const int N = 10;

int map[N][N];
bool row[N][N],col[N][N],Mat[4][4][N],ans;
bool dfs(int r,int c){
	if( r==10 ){
		ans = true;
		return true;
	}
	if( map[r][c] > 0 ){
		if( c==9 ) dfs(r+1,1);
		else dfs(r,c+1);
	} else {
		for(int v=1 ; v <= 9 && !ans ; ++v){
			if( !row[r][v] && !col[c][v] && !Mat[(r+2)/3][(c+2)/3][v] ){
				map[r][c] = v;
				row[r][v] = true;
				col[c][v] = true;
				Mat[(r+2)/3][(c+2)/3][v] = true;
				if( c==9 ) dfs(r+1,1);
				else dfs(r,c+1);
				if( ans ) return true;
				map[r][c] = 0;
				row[r][v] = false;
				col[c][v] = false;
				Mat[(r+2)/3][(c+2)/3][v] = false;
			}
		}
	}
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	char str[15];
	int T;
	scanf("%d", &T);
	while( T-- ){
		CLR( row, false );
		CLR( col, false );
		CLR( Mat, false );
		for(int i=1 ; i <= 9 ; ++i){
			scanf("%s", str+1);
			for(int j=1 ; str[j] ; ++j){
				map[i][j] = str[j]-'0';
				if( map[i][j] > 0 ){
					row[i][map[i][j]] = true;
					col[j][map[i][j]]=true;
					Mat[(i+2)/3][(j+2)/3][map[i][j]]=true;
				}
			}
		}
		ans = false;
		if( dfs(1,1) ){
			for(int i=1 ; i <= 9 ; ++i){
				for(int j=1 ; j <= 9 ; ++j)
					printf("%d", map[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}