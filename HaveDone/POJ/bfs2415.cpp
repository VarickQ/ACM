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

struct node{
	int a,b,c,step;
}s;
int vis[N][N][N],n;
char mat[N][N];
int bfs(){
	queue<node> qu;
	s.step = 0;
	if( s.a==s.b && s.b==s.c ) return 0;
	qu.push( s );
	while( !qu.empty() ){
		node ff = qu.front(); node f; qu.pop();
		for(int i=1 ; i <= n ; ++i){
			if( mat[ff.a][i]==mat[ff.b][ff.c] && !vis[i][ff.b][ff.c]){
				vis[i][ff.b][ff.c] = 1;
				f.a = i; f.b = ff.b; f.c = ff.c; f.step = ff.step+1;
				if(f.a == f.b && f.b == f.c)
					return f.step;
				qu.push( f );
			}
			if( mat[ff.b][i]==mat[ff.a][ff.c] && !vis[ff.a][i][ff.c]){
				vis[ff.a][i][ff.c] = 1;
				f.a = ff.a; f.b = i; f.c = ff.c; f.step = ff.step+1;
				if(f.a == f.b && f.b == f.c)
					return f.step;
				qu.push( f );
			}
			if( mat[ff.c][i]==mat[ff.a][ff.b] && !vis[ff.a][ff.b][i]){
				vis[ff.a][ff.b][i] = 1;
				f.a = ff.a; f.b = ff.b; f.c = i; f.step = ff.step+1;
				if(f.a == f.b && f.b == f.c)
					return f.step;
				qu.push( f );
			}
		}
	}
	return -1;
}
int main(){
	while( scanf("%d", &n) && n ){
		memset( vis, 0, sizeof( vis ) );
		memset( mat, 0, sizeof( mat ) );
		scanf("%d%d%d", &s.a, &s.b, &s.c);
		vis[s.a][s.b][s.c] = 1;
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				scanf(" %c", &mat[i][j]);
		int ans = bfs();
		if( ans != -1 ) printf("%d\n", ans);
		else printf("impossible\n");
	}
	return 0;
}