#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int N = 100005;
typedef long long ll;

int dp[35][35];//猜i次，j次猜高的最大N
int main(){
	int g,l,cs=1;
	CLR( dp, 0 );
	for(int i=1 ; i <= 30 ; ++i)
		dp[i][0] = dp[i-1][0] + 1;
	for(int i=1 ; i <= 30 ; ++i)
		for(int j=1 ; j <= 30 ; ++j)
			dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+1;
	//dp[i-1][j-1] 猜高了, dp[i-1][j] 猜低了, +1猜对了
	while( scanf("%d%d", &g, &l) && (g+l) ){
		printf("Case %d: %d\n", cs++, dp[g][l]);
	}
	return 0;
}