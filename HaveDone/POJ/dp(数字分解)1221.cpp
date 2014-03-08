/*
1)        对任意正整数i(i<N)，若对正整数N的分解中存在i，则itg[N][i]可表示为N的分解中最小数等于i和最小数大于i，即大于等于i+1的部分，即：
itg[N][i] = itg[N-2i][i] + itg[N][i+1]
2)        初始化的问题，对于整数0的分解，根据1)中的讨论，有itg[0][i] = 1 (i=1,2, . . ., N)；另外，当i>N/2时，itg[N][i] = 1，这是显然的；
*/

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
const int N = 305;
typedef long long ll;

ll dp[N][N];
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int n;

	for(int i=1 ; i <= 300 ; ++i){
		dp[0][i] = 1;
		for(int j=i/2+1 ; j <= i ; ++j)
			dp[i][j] = 1;
	}
	for(int i=1 ; i <= 300 ; ++i)
		for(int j=i/2 ; j >= 1 ; --j)
			dp[i][j] = dp[i-2*j][j]+dp[i][j+1];

	while( scanf("%d", &n) && n ){
		printf("%d %lld\n", n, dp[n][1]);
	}
	return 0;
}