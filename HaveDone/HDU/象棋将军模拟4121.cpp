#include <stdio.h>
#include <math.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 10000000;
const int N = 12;

int mat[N][N];
int v[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int checkX(int a,int b,int c,int d){//can fly
	if( b != d ) return -1;
	int num = 0;
	for(int i=min(a,c)+1 ; i < max(a,c) ; ++i){
		if( mat[i][b] ) ++num;
	}
	return num;
}
int checkY(int a,int b,int c,int d){
	if( a != c ) return -1;
	int num = 0;
	for(int i=min(b,d)+1 ; i < max(b,d) ; ++i)
		if( mat[a][i] ) ++num;
	return num;
}
bool checkG( int x, int y ){
	if( x>=1 && x<=3 && y>=4 && y<=6 )
		return true;
	return false;
}
bool checkM( int x, int y ){
	if( x>=1 && x<=10 && y>=1 && y<=9 )
		return true;
	return false;
}
bool canLive( int x, int y ){
	for(int i=1 ; i <= 10 ; ++i){
		for(int j=1 ; j <= 9 ; ++j){
			if( mat[i][j] == 2 ){//jiang
				if( checkX(x,y,i,j) == 0 )
					return false;
			}
			else if( mat[i][j] == 3 ){//che
				if( checkX(x,y,i,j)==0 || checkY(x,y,i,j)==0 )
					return false;
			}
			else if( mat[i][j] == 4 ){//ma
				for(int p=0 ; p < 4 ; ++p){
					int tx = i+v[p][0];
					int ty = j+v[p][1];
					if( checkM(tx,ty) && mat[tx][ty]==0 ){
						if( p == 0 ){
							if(checkM(tx+1,ty-1) && x==tx+1 && y==ty-1)
								return false;
							if(checkM(tx+1,ty+1) && x==tx+1 && y==ty+1)
								return false;
						}
						else if( p == 1 ){
							if(checkM(tx-1,ty+1) && x==tx-1 && y==ty+1)
								return false;
							if(checkM(tx+1,ty+1) && x==tx+1 && y==ty+1)
								return false;
						}
						else if( p == 2 ){
							if(checkM(tx-1,ty-1) && x==tx-1 && y==ty-1)
								return false;
							if(checkM(tx-1,ty+1) && x==tx-1 && y==ty+1)
								return false;
						}
						else if( p == 3 ){
							if(checkM(tx+1,ty-1) && x==tx+1 && y==ty-1)
								return false;
							if(checkM(tx-1,ty-1) && x==tx-1 && y==ty-1)
								return false;
						}
					}
				}
			}
			else if( mat[i][j] == 5 ){//pao
				if( checkX(x,y,i,j)==1 || checkY(x,y,i,j)==1 )
					return false;
			}
		}
	}
	return true;
}
bool judge( int x, int y ){
	mat[x][y] = 0;
	for(int i=0 ; i < 4 ; ++i){
		int a = x+v[i][0];
		int b = y+v[i][1];
		if( checkG( a, b ) ){
			int temp = mat[a][b];
			mat[a][b] = 1;
			if( canLive( a, b ) )
				return false;
			mat[a][b] = temp;
		}
	}
	return true;
}
int n,a,b,c,d;
int main(){
	char str[2];
	int x,y;
	bool f = false;
	while( scanf("%d%d%d", &n, &a, &b) && (n+a+b) ){
		memset( mat, 0, sizeof( mat ) );
		mat[a][b] = 1;
		for(int i=0 ; i < n ; ++i){
			scanf("%s%d%d", str, &x, &y);
			if( str[0] == 'G' ){//jiang
				f = true;
				c = x; d = y;
				mat[x][y] = 2;
			}
			else if( str[0] == 'R' )//che
				mat[x][y] = 3;
			else if( str[0] == 'H' )//ma
				mat[x][y] = 4;
			else if( str[0] == 'C' )//pao
				mat[x][y] = 5;
		}
		if( f ){
			if( checkX(a,b,c,d) == 0 ){
				printf("NO\n"); continue;
			}
		}
		if( judge( a, b ) )
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}