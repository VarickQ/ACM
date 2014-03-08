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

char a[N],b[N];
int dp[N][N];
int main(){
	int n1,n2,cs=1;
	while( gets(a) ){
		if( a[0] == '#' ) break;
		gets( b );
		n1 = strlen(a);
		n2 = strlen(b);

		memset( dp, 0, sizeof( dp ) );
		for(int i=n1-1 ; i >= 0 ; --i)
			for(int j=n2-1 ; j >= 0 ; --j){
				if( a[i] == b[j] )
					dp[i][j] = max(dp[i][j],dp[i+1][j+1]+1);
				else
					dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
			}
		printf("Case #%d: you can visit at most %d cities.\n", cs++, dp[0][0]);
	}
	return 0;
}