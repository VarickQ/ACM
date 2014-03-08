#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
const int N = 2005;
const int M = 2005;
typedef long long LL;

char ma[N][N];
int n, st[N*N], in[N];
bool topsort(){
	int top = 0, cnt = 0;
	for(int i=0 ; i < n ; ++i)
		if( in[i] == 0 )
			st[top++] = i;
	cnt = top;
	if( !top ) return true;
	while( top ){
		int u = st[--top];
		for(int j=0 ; j < n ; ++j)
			if( ma[u][j] == '1' )
				if( --in[j] == 0 )
					st[top++] = j, cnt++;
	}
	if( cnt < n ) return true;
	return false;
}
int main(){
	int T, cs = 1;
	scanf("%d", &T);
	while( T-- ){
		CLR( in, 0 );
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i){
			scanf("%s", &ma[i]);
			for(int j=0 ; j < n ; ++j){
				if( ma[i][j]=='1' ) in[j]++;
			}
		}
		if( topsort() )
			printf("Case #%d: Yes\n", cs++);
		else printf("Case #%d: No\n", cs++);
	}
    return 0;
}