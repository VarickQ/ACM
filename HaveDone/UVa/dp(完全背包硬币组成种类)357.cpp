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
const int N   = 30005;
typedef long long ll;

int c[5]={1,5,10,25,50};
ll dp[N];
int main(){
	int n;
	dp[0] = 1;
	for(int i=0 ; i < 5 ; ++i)
		for(int j=c[i] ; j <= N-5 ; ++j)
			dp[j] += dp[j-c[i]];
	while( scanf("%d", &n) != EOF ){
		ll ans = dp[n];
		if( ans == 1 )
			printf("There is only 1 way to produce %d cents change.\n",n);
		else
			printf("There are %lld ways to produce %d cents change.\n",ans,n);
	}
	return 0;
}