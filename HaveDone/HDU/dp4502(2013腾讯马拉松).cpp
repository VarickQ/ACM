#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

struct Node{
	int s, e, c;
}a[1005];
int dp[105];
int main(){
	int T, m, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &m, &n);
		for(int i=1 ; i <= n ; ++i)
			scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].c);
		memset( dp, 0, sizeof( dp ) );
		for(int j=1 ; j <= m ; ++j){
			dp[j] = max(dp[j],dp[j-1]);
			for(int i=1 ; i <= n ; ++i)
				if( j >= a[i].e )
					dp[j] = max(dp[j],dp[a[i].s-1]+a[i].c);
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}