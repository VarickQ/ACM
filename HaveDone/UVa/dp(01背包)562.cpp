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

int c[N],sum;
bool dp[N*500];
int main(){
	int T,n,m,i;
	scanf("%d", &T);
	while( T-- ){
		//memset( sum, 0, sizeof( sum ) );
		memset( dp, 0, sizeof( dp ) );
		scanf("%d", &n);
		sum = 0;
		for( i=1 ; i <= n ; ++i ){
			scanf("%d", &c[i]);
			sum += c[i];
		}

		dp[0] = true;
		for( i=1 ; i <= n ; ++i )
			for(int j=sum-c[i] ; j >= 0 ; --j)
				if( dp[j] ) dp[j+c[i]] = true;

		for( i=sum/2 ; i >= 0 ; --i )
			if( dp[i] ) break;
		printf("%d\n", sum-2*i);
	}
	return 0;
}