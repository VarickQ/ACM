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

typedef long long ll;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-8;
const int inf = 1000000000;
const int M = 6050000;
const int N = 12;

char mine[N][N],p[N][N],ans[N][N];
int num[N][N];
int v[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};
int getnum(int x,int y){
	int cnt = 0;
	for(int i=0 ; i < 8 ; ++i){
		int a = x+v[i][0];
		int b = y+v[i][1];
		if( mine[a][b] == '*' )
			cnt++;
	}
	return cnt;
}
int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int n;
	while( scanf("%d", &n) != EOF ){

		for(int i=1 ; i <= n ; ++i)
			scanf("%s", mine[i]+1);
		for(int i=1 ; i <= n ; ++i)
			scanf("%s", p[i]+1);

		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				if( mine[i][j] != '*' )
					num[i][j] = getnum(i,j);

		bool dead = false;
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j){
				if( p[i][j] == 'x' ){
					if( mine[i][j] == '*' )
						dead = true;
					ans[i][j] = num[i][j]+'0';
				}
				else ans[i][j] = '.';
			}
		if( dead )
			for(int i=1 ; i <= n ; ++i)
				for(int j=1 ; j <= n ; ++j)
					if( mine[i][j] == '*' )
						ans[i][j] = '*';

		for(int i=1 ; i <= n ; ++i){
			for(int j=1 ; j <= n ; ++j)
				printf("%c", ans[i][j]);
			printf("\n");
		}
	}
    return 0;
}