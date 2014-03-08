#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 100000000;
const int M   = 35000;
const int N   = 505;
typedef long long ll;

struct node{
	int x,y,val;
	bool operator < (const node &a) const{
		//return c < a.c;//从大到小
		return val > a.val;//从小到大
	}
}a;
int n,m,t;
bool vis[N][N];
char mat[N][N];
int v[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
priority_queue<node> qu;
int bfs()
{
	qu.push(a);
	int i;
	while( !qu.empty() )
	{
		node ff=qu.top(); node f;  qu.pop();
		for( i=0 ; i < 4 ; i++ )
		{
			f.x = ff.x+v[i][0];
			f.y = ff.y+v[i][1];
			f.val = ff.val+1;
			if( f.x<0 || f.x>=n || f.y<0 || f.y>=m )
				return f.val;
			if( f.x>=0&&f.x<n && f.y>=0&&f.y<m && mat[f.x][f.y]!='#')
			{
				if( !vis[f.x][f.y] ){
					vis[f.x][f.y] = true;
					if( mat[f.x][f.y]=='.' ) qu.push(f);
					else if( mat[f.x][f.y]=='@'){
						f.val += t;
						qu.push(f);
					}
				}
			}
		}
	}
    return -1;
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		memset( vis, 0, sizeof( vis ) );
		while( !qu.empty() ) qu.pop();
		scanf("%d%d%d",&n,&m,&t);
		for(int i=0 ; i < n ; ++i)
			scanf("%s", mat[i]);
		for(int i=0 ; i < n ; ++i)
			for(int j=0 ; j < m ; ++j)
				if( mat[i][j] == 'S' ){
					a.x = i;
					a.y = j;
					a.val = 0;
				}
		vis[a.x][a.y] = true;
		printf("%d\n",bfs());
	}
	return 0;
}