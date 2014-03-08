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
const int M   = 100000;
const int N   = 25;
//typedef long long ll;

int a[N],b[N],dp[N][N];
int main(){
	int n,x;
	scanf("%d", &n);
	for(int i=1 ; i <= n ; ++i){
		scanf("%d", &x);
		a[x] = i;
	}
	while( scanf("%d", &x) == 1 ){
		b[x] = 1;
		memset( dp, 0, sizeof( dp ) );
		for(int i=2 ; i <= n ; ++i){
			scanf("%d", &x);
			b[x] = i;
		}

		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				if( a[i] == b[j] )
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		printf("%d\n", dp[n][n]);
	}
	return 0;
}