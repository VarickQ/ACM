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
const int M = 5000000;
const int N = 10005;

int a[N],dp[N][105];
int main(){
	int n,k;
	while( scanf("%d%d", &n, &k) == 2 ){
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &a[i]);
			a[i] %= k;
		}
		memset( dp, 0, sizeof( dp ) );
		dp[0][0] = true;
		for(int i=1 ; i <= n ; ++i)
			for(int j=k-1 ; j >= 0 ; --j)
				if( dp[i-1][j] ){
					dp[i][(j+a[i])%k] = true;
					dp[i][(k+j-a[i])%k] = true;
				}
		if( dp[n][0] )
			printf("Divisible\n");
		else printf("Not divisible\n");
	}
	return 0;
}