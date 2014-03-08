#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int N   = 1005;
typedef long long ll;

char str[N],s[205][N];
bool g[205][205],f,vis[205];
int n, hp, c, ans[205];
void dfs( int u ){
	ans[c] = u;
	if( hp == u ){
		f = true; return;
	}
	for(int i=1 ; i <= n ; ++i){
		if( g[u][i] && !vis[i] ){
			c++;
			vis[i] = true;
			dfs(i);
			if( f ) return ;
			vis[i] = false;
			c--;
		}
	}
}
int main(){
	int T, cs = 1;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d\n", &n);
		CLR( g, 0 );
		CLR( s, 0 );
		CLR( vis, 0 );
		for(int i=1 ; i <= n ; ++i){
			gets( str );
			int a = 0, b = 0, p = 0;
			if( str[0] == 'C' ){
				int j = 0;
				while( str[j] != '"' ) ++j;
				j++;
				while( str[j] != '"' ){
					s[i][p++] = str[j]; ++j;
				}
				s[i][p] = '\0';
				while( !(str[j]>='0' && str[j]<='9') )++j;
				while( str[j]>='0' && str[j]<='9' ){
					a = a*10+str[j]-'0'; ++j;
				}
				while( !(str[j]>='0' && str[j]<='9') )++j;
				while( str[j]>='0' && str[j]<='9' ){
					b = b*10+str[j]-'0'; ++j;
				}
				g[i][a] = true;
				g[i][b] = true;
			}
			else if( str[0] == 'E' ){
				int j = 0;
				while( str[j] != '"' ) ++j;
				j++;
				while( str[j] != '"' ){
					s[i][p++] = str[j];
					++j;
				}
				s[i][p] = '\0';
				while( !(str[j]>='A' && str[j]<='Z') )++j;
				char tmp[10];
				int t = 0;
				while( str[j]>='A' && str[j]<='Z' ){
					tmp[t++] = str[j]; ++j;
				}
				tmp[t] = '\0';
				if( !strcmp(tmp,"HAPPY") ) hp = i;
			}
		}
		c = 0;
		f = false;
		CLR( ans, 0 );
		vis[1] = true;
		dfs( 1 );
		printf("STORY %d\n", cs++);
		for(int i=0 ; i <= c ; ++i)
			printf("%s\n", s[ans[i]]);
	}
	return 0;
}