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
const int N   = 55;

struct point{
	int x,y,d,times;
}s,e;
int n,m,mat[N][N],vis[N][N][4];
int v[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int bfs(){
	queue<point> qu;
	s.times = 0;
	if( s.x==e.x && s.y==e.y ) return 0;
	qu.push( s );
	while( !qu.empty() ){
		point f,ff = qu.front(); qu.pop();

		f = ff;//buzhuan
		if( !vis[f.x][f.y][f.d] ){
			qu.push( f );
			vis[f.x][f.y][f.d] = 1;
		}
		f.d = (ff.d+1)%4; f.times = ff.times+1;//zuozhuan1
		if( !vis[f.x][f.y][f.d] ){
			qu.push( f );
			vis[f.x][f.y][f.d] = 1;
		}
		f.d = (ff.d-1+4)%4; f.times = ff.times+1;//youzhuan1
		if( !vis[f.x][f.y][f.d] ){
			qu.push( f );
			vis[f.x][f.y][f.d] = 1;
		}

		f = ff;
		for(int i=1 ; i <= 3 ; ++i){
			f.x = ff.x+v[ff.d][0]*i;
			f.y = ff.y+v[ff.d][1]*i;
			if(f.x>0 && f.x<n && f.y>0 && f.y<m){
				if( mat[f.x][f.y] == 1 ) break;
				if(!vis[f.x][f.y][f.d] && !mat[f.x][f.y]){
					vis[f.x][f.y][f.d] = 1;
					f.times++;
					if( f.x==e.x && f.y==e.y) return f.times;
					qu.push( f );
					f.times--;
				}
			} else break;
		}
	}
	return -1;
}
int main(){
	char str[20];
	while( scanf("%d%d", &n, &m) && (n+m) ){
		memset( vis, 0, sizeof( vis ) );
		memset( mat, 0, sizeof( mat ) );
		int x;
		for(int i=0 ; i < n ; ++i){
			for(int j=0 ; j < m ; ++j){
				scanf("%d", &x);
				if(x == 1){
					mat[i][j] = 1;
					if(mat[i][j+1] == 0) mat[i][j+1]=1;
					if(mat[i+1][j] == 0) mat[i+1][j]=1;
					if(mat[i+1][j+1]==0) mat[i+1][j+1]=1;
				}
			}
		}
		scanf("%d%d%d%d", &s.x, &s.y, &e.x, &e.y);
		scanf("%s", str);
		if( strcmp(str,"north") == 0 ) s.d = 0;
		else if( strcmp(str,"south") == 0 ) s.d = 2;
		else if( strcmp(str,"west") == 0 ) s.d = 3;
		else if( strcmp(str,"east") == 0 ) s.d = 1;
		vis[s.x][s.y][s.d] = 1;
		printf("%d\n", bfs());
	}
	return 0;
}