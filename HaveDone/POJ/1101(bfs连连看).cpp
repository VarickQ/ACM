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
const int N   = 80;

int mat[N][N],vis[N][N];
struct point{
	int x,y,d,seg;
}s,e;
int v[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int w,h,ans;

void bfs(){
	queue<point> qu;
	s.seg = 0;s.d = 0; qu.push( s );
	while( !qu.empty() ){
		point ff = qu.front(); point f; qu.pop();
		for(int i=0 ; i < 4 ; ++i){
			f.x = ff.x+v[i][0];
			f.y = ff.y+v[i][1];
			f.d = i+1;
			if( ff.d != i+1 ) f.seg = ff.seg+1;
			else f.seg = ff.seg;
			if(f.x>=0 && f.x<=h+1 && f.y>=0 && f.y<=w+1){
				if( f.x==e.x && f.y==e.y ){
					if( ans > f.seg ) ans = f.seg;
				}
				if( !mat[f.x][f.y] && !vis[f.x][f.y] ){
					vis[f.x][f.y] = 1;
					qu.push( f );
				}
			}
		}
	}
	if( ans == inf ) printf("impossible.\n");
	else printf("%d segments.\n", ans);
}
int main(){
	int cs=1;
	char ch[N];
	while( scanf("%d%d", &w, &h) != EOF ){
		if( w==0 && h==0 ) break;
		getchar();
		memset( mat, 0, sizeof( mat ) );
		for(int i=1 ; i <= h ; ++i){
			gets( ch );
			for(int j=0 ; j < w ; ++j){
				if( ch[j] == 'X' ) mat[i][j+1] = 1;
				else mat[i][j+1] = 0;
			}
		}
		printf("Board #%d:\n", cs++);
		int css = 1;
		while(scanf("%d%d%d%d",&s.x,&s.y,&e.x,&e.y) && (s.x+s.y+e.x+e.y)){
			ans = inf;
			memset( vis, 0, sizeof( vis ) );
			swap( s.x, s.y );
			swap( e.x, e.y );
			printf("Pair %d: ", css++);
			bfs();
		}
		printf("\n");
	}
	return 0;
}