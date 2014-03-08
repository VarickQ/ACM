#include <stdio.h>
#include <math.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 10000000;
const int N = 30005;

int mat[6][7],temp[6][7];
int main()
{
	int T,cs=1;
	int i,j,p;
	scanf("%d", &T);
	while( T-- ){
		memset( mat, 0, sizeof( mat ) );
		for( i=1 ; i <= 5 ; ++i )
			for( j=1 ; j <= 6 ; ++j ){
				scanf("%d", &mat[i][j]);
				mat[i][j] = 1-mat[i][j];
			}
		printf("PUZZLE #%d\n", cs++);
		for( i=0 ; i < 64 ; ++i ){
			memset( temp, 0, sizeof( temp ) );
			int s = i;
			for( j=1 ; j <= 6 ; ++j ){
				temp[1][j] = s&1;
				s >>= 1;
			}
			for( j=2 ; j <= 5 ; ++j )
				for( p=1 ; p <= 6 ; ++p )
					temp[j][p]=!(mat[j-1][p]^temp[j-1][p]^temp[j-2][p]^temp[j-1][p-1]^temp[j-1][p+1]);
			bool f = false;
			for( j=1 ; j <= 6 ; ++j )
				if(!(mat[5][j]^temp[5][j]^temp[4][j]^temp[5][j-1]^temp[5][j+1])){
					f = true; break;
				}
			if( f ) continue;
			for( j=1 ; j <= 5 ; ++j ){
				for( p=1 ; p < 6 ; ++p )
					printf("%d ", temp[j][p]);
				printf("%d\n", temp[j][6]);
			}
			if( !f ) break;
		}
	}
	return 0;
}