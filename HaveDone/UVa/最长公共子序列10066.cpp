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
const int M   = 10005;
const int N   = 105;
typedef long long ll;

int a[N],b[N],dp[N][N];
int main(){
	int n1,n2,cs=1;
	while( scanf("%d%d", &n1, &n2) && (n1+n2) ){

		for(int i=1 ; i <= n1 ; ++i)
			scanf("%d", &a[i]);
		for(int i=1 ; i <= n2 ; ++i)
			scanf("%d", &b[i]);

		memset( dp, 0, sizeof( dp ) );
		for(int i=1 ; i <= n1 ; ++i)
			for(int j=1 ; j <= n2 ; ++j){
				if( a[i] == b[j] )
					dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
				else
					dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", cs++, dp[n1][n2]);
	}
	return 0;
}