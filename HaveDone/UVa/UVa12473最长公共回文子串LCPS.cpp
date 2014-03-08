#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long LL;
const int N = 65;

char s1[N],s2[N];
int lcps[N][N][N][N];
int LCPS( char *x, char *y ){
	memset( lcps, 0, sizeof( lcps ) );
	int n = strlen( x+1 );
	int m = strlen( y+1 );
	for(int i=1 ; i <= n ; ++i)
		for(int j=i ; j <= n ; ++j)
			for(int k=1 ; k <= m ; ++k)
				for(int l=k ; l <= m ; ++l)
					if( ( i==j || k==l ) &&
						 ( x[i]==y[k] || x[i]==y[l]
						|| x[j]==y[k] || x[j]==y[l]) )
						lcps[i][j][k][l] = 1;
					else lcps[i][j][k][l] = 0;
	for(int xl=2 ; xl <= n ; ++xl)
		for(int yl=2 ; yl <= m ; ++yl)
			for(int i=1 ; i <= n-xl+1 ; ++i)
				for(int k=1 ; k <= m-yl+1 ; ++k){
					int j = i + xl - 1;
					int l = k + yl - 1;
					if( x[i]==x[j] && x[j]==y[k] && y[k]==y[l] )
						lcps[i][j][k][l] = 2+lcps[i+1][j-1][k+1][l-1];
					else
						lcps[i][j][k][l] = max(lcps[i+1][j][k][l],
							max(lcps[i][j-1][k][l],
								max(lcps[i][j][k+1][l],lcps[i][j][k][l-1])));
				}
	return lcps[1][n][1][m];
}
int main(){
	int T, cs=1;
	scanf("%d", &T);
	while( T-- ){
		scanf("%s%s", s1+1, s2+1);
		int ans = LCPS( s1, s2 );
		printf("Case %d: %d\n", cs++, ans);
	}
	return 0;
}