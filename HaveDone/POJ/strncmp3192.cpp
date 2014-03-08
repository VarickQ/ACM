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
const int M   = 100000;
const int N   = 10000;

struct A{
	char str[10];
	int len;
}a[10];

int n,ans,mat[10][10],b[10];
bool mark[10];
void dfs(int x){
	if(x == n+1){
		int m = a[b[1]].len;
		for(int i=2 ; i <= n ; ++i)
			m += a[b[i]].len - mat[b[i-1]][b[i]];
		ans = ans>m?m:ans;
		return ;
	}
	for(int i=1 ; i <= n ; ++i)
		if( !mark[i] ){
			mark[i] = true;
			b[x] = i;
			dfs( x+1 );
			mark[i] = false;
		}
}
int main(){
	int i,j,k;
	while( scanf("%d", &n) == 1 ){

		memset( a, 0, sizeof( a ) );
		memset( mat, 0, sizeof( mat ) );
		memset( mark, 0, sizeof( mark ) );
		for( i=1 ; i <= n ; ++i){
			scanf( "%s", a[i].str );
			a[i].len = strlen( a[i].str );
		}

		for( i=1 ; i <= n ; ++i)
			for( j=1 ; j <= n ; ++j){
				if(i != j){
					bool f = false;
					for( k=0 ; k < a[i].len - a[j].len ; ++k)
						if(strncmp( a[i].str+k, a[j].str, a[j].len) == 0){
							mat[i][j] = a[j].len;
							f = true;
							break;
						}
					if( f ) break;
					k = max( 0, a[i].len - a[j].len );
					for( ; k < a[i].len ; ++k)
						if(strncmp( a[i].str+k, a[j].str, a[i].len-k ) == 0){
							mat[i][j] = a[i].len - k;
							break;
						}
				}
			}

		ans = inf;
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}