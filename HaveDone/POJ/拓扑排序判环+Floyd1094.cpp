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
const int inf = 1000000000;
const int M = 1000200;
const int N = 30;

int n,mat[N][N],du[N];
int stack[N*10],top,ans[N];
bool vis[N];
bool topsort(){
	int i,j;
	top = 0;
	for( i=0 ; i < n ; ++i )
		if( du[i] == 0 )
			stack[top++] = i;
	for( i=0 ; i < n ; ++i){
		if( top == 0 ) return false;
		int u = stack[--top];
		for( j=0 ; j < n ; ++j )
			if( mat[u][j] ){
				if( --du[j] == 0 )
					stack[top++] = j;
			}
		ans[i] = u;
	}
	return true;
}
int main(){
	int m;
	while( scanf("%d%d", &n, &m) && (n+m) ){
		memset( mat, 0, sizeof( mat ) );
		memset( du, 0, sizeof( du ) );
		memset( ans, 0, sizeof( ans ) );
		char str[5];
		bool f = false;
		for(int cs=1 ; cs <= m ; ++cs){
			scanf("%s", str);
			if( f ) continue;
			int a = str[0]-'A';
			int b = str[2]-'A';
			if( !mat[a][b] ){
				mat[a][b] = 1;
				du[b]++;
			}
			if( !topsort() ){//判断是否有环
				printf("Inconsistency found after %d relations.\n",cs);
				f = true;
			}
			for(int k=0 ; k < n ; ++k)
				for(int i=0 ; i < n ; ++i)
					for(int j=0 ; j < n ; ++j)
						if( mat[i][k] && mat[k][j] )
							mat[i][j] = 1;
			//memset( du, 0, sizeof( du ) );
			for(int i=0 ; i < n ; ++i)
				for(int j=0 ; j < n ; ++j)
					if( mat[i][j] )	du[j]++;
			memset( vis, 0, sizeof( vis ) );
			bool ff = false;
			for(int i=0 ; i < n ; ++i)
				if( !vis[du[i]] ) vis[du[i]]=true;
				else ff = true;
			if( !ff ){	//能确定有序序列
				printf("Sorted sequence determined after %d relations: ", cs);
				for(int i=0 ; i < n ; ++i)
					printf("%c", ans[i]+'A');
				printf(".\n");
				f = true;
			}
		}
		if( !f )printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}