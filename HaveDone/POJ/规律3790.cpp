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
typedef __int64 ll;
const int inf = 2000000000;
const int M = 100000;
const int N = 1005;

int dp[N];
int main()
{
	int T,n,cs=0;
	dp[1] = 1;
	dp[2] = dp[3] = 2;
	for(int i=4 ; i <= 1000 ; ++i){
		if(i&1)
			dp[i] = dp[i-2]+dp[i/2];
		else
			dp[i] = dp[i-1]+dp[i/2];
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d %d\n",++cs,dp[n]);
	}
	return 0;
}