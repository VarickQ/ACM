/*定两个字符串，求经过多少次的增删改操作可使两个字符串相同。
与poj2192相似，
用dp[n][m]记录使str1前n个字符与str2前m个字符相同的最少操作数。
每次的判断都有三种情况，即str1前i个字符str2前j-1个字符，
str1前i-1个字符str2前j个字符，str1前i-1个字符str2前j-1个字符。
取三种情况经过本次操作后的最小值即可*/
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
const int N = 1005;

int dp[N][N];
//str1 前i个字符 和 str2 前j个字符 最多有要操作几步
int main(){
	int len1, len2;
	char str1[N],str2[N];
	while( scanf("%d%s%d%s", &len1, str1, &len2, str2) != EOF ){
		memset( dp, 0, sizeof( dp ) );
		for(int i=0 ; i <= len1 ; ++i)
			dp[i][0] = i;
		for(int i=0 ; i <= len2 ; ++i)
			dp[0][i] = i;
		for(int i=1 ; i <= len1 ; ++i)
			for(int j=1 ; j <= len2 ; ++j){
				if( str1[i-1] == str2[j-1] )
					dp[i][j] = min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]));
				else
					dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
			}
		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}