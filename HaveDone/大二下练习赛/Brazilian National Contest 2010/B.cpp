//B 模拟 by Varick_Q
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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 2000100;
const int N   = 105;
typedef long long ll;

struct Node{
	int dir,x,y;//0,1,2,3东南西北
}a;
int n,m,q;
char mat[N][N],qu[50005];
bool check( int x, int y ){
	if(mat[x][y]!='#' && (x>=0&&x<n&&y>=0&&y<m))
		return true;
	return false;
}
int main(){
	while( scanf("%d%d%d", &n, &m, &q) && (n+m+q) ){
		int x,y;
		for(int i=0 ; i < n ; ++i){
			scanf("%s", mat[i]);
			for(int j=0 ; mat[i][j] ; ++j){
				if(mat[i][j]=='N'){//bei
					a.x = i;
					a.y = j;
					a.dir = 3;
				}
				else if( mat[i][j]=='S' ){//nan
					a.x = i;
					a.y = j;
					a.dir = 1;
				}
				else if( mat[i][j]=='L' ){//dong
					a.x = i;
					a.y = j;
					a.dir = 0;
				}
				else if( mat[i][j]=='O' ){//xi
					a.x = i;
					a.y = j;
					a.dir = 2;
				}
			}
		}
		scanf("%s", qu);
		int u,v,ans=0;
		for(int i=0 ; qu[i] ; ++i){
			if( qu[i] == 'D' ){
				a.dir = (a.dir+1)%4;
			}
			else if( qu[i] == 'E' ){
				a.dir = (a.dir-1+4)%4;
			}
			else if( qu[i] == 'F' ){
				if( a.dir == 0 ){
					u = a.x;
					v = a.y+1;
					if( check(u,v) ){
						a.x = u;
						a.y = v;
						if( mat[u][v] == '*' ){
							ans++;
							mat[u][v] = '.';
						}
					}
				}
				else if( a.dir == 1 ){
					u = a.x+1;
					v = a.y;
					if( check(u,v) ){
						a.x = u;
						a.y = v;
						if( mat[u][v] == '*' ){
							ans++;
							mat[u][v] = '.';
						}
					}
				}
				else if( a.dir == 2 ){
					u = a.x;
					v = a.y-1;
					if( check(u,v) ){
						a.x = u;
						a.y = v;
						if( mat[u][v] == '*' ){
							ans++;
							mat[u][v] = '.';
						}
					}
				}
				else if( a.dir == 3 ){
					u = a.x-1;
					v = a.y;
					if( check(u,v) ){
						a.x = u;
						a.y = v;
						if( mat[u][v] == '*' ){
							ans++;
							mat[u][v] = '.';
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}