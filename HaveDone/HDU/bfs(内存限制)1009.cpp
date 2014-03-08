#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int N   = 5001;
const int inf = 1000000000;
typedef long long LL;

struct Node{
	int x,y;
}p,s,f,ff,tmp,t;
int r,c,co;
int cost[N][N];
char mat[N][N];
int v[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
queue<Node> qu;
vector<Node> pp;
bool check( Node a ){
	if( a.x>=0 && a.x<r && a.y>=0 && a.y<c )
		return true;
	return false;
}
int main(){
	while( scanf("%d%d%d", &r, &c, &co) != EOF ){
		CLR( mat, 0 );
		pp.clear();
		for(int i=0 ; i < r ; ++i){
			scanf("%s", mat[i]);
			for(int j=0 ; j < c ; ++j){
				cost[i][j] = inf;
				if( mat[i][j] == 'P' ){
					p.x = i; p.y = j;
					pp.push_back(p);
				}
				if( mat[i][j] == 'C' ){
					t.x = i; t.y = j;
				}
				if( mat[i][j] == 'Y' ){
					s.x = i, s.y = j;
					cost[i][j] = 0;
				}
			}
		}
		while( !qu.empty() ) qu.pop();
		qu.push(s);
		while( !qu.empty() ){
			ff = qu.front(); qu.pop();
			if( ff.x==t.x && ff.y==t.y ) break;
			for(int i=0 ; i < 4 ; ++i){
				f.x = ff.x+v[i][0];
				f.y = ff.y+v[i][1];
				if( check( f ) && mat[f.x][f.y]!='#' && cost[f.x][f.y]==inf){
					if( mat[f.x][f.y] == 'P' ){
						for(int j=0 ; j < pp.size() ; ++j)
						{
							tmp.x = pp[j].x;
							tmp.y = pp[j].y;
							cost[tmp.x][tmp.y] = cost[ff.x][ff.y];
							qu.push(tmp);
						}
					}
					else {
						if( mat[f.x][f.y] == '*' )
							cost[f.x][f.y] = cost[ff.x][ff.y]+co;
						else cost[f.x][f.y] = cost[ff.x][ff.y];
						qu.push(f);
					}
				}
			}
		}
		if( cost[t.x][t.y] == inf ) printf("Damn teoy!\n");
		else printf("%d\n", cost[t.x][t.y]);
	}
	return 0;
}