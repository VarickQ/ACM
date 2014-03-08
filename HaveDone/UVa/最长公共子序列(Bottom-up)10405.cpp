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
const int N   = 1005;
//typedef long long ll;

int dp[N][N];
int main(){
	char str1[N],str2[N];
	while( gets(str1) ){
		gets(str2);
		int len1 = strlen(str1);
		int len2 = strlen(str2);

		memset( dp, 0, sizeof( dp ) );
		for(int i=len1-1 ; i >= 0 ; --i)
			for(int j=len2-1 ; j >= 0 ; --j){
				if( str1[i] == str2[j] )
					dp[i][j] = dp[i+1][j+1]+1;
				else
					dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
			}
		printf("%d\n", dp[0][0]);
	}
	return 0;
}