#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 1000000000;
const int M = 100000;
const int N = 50;

int a[N][N];
ll dp[N][N];
int main(){
	int n;
	char str[N];
	while(scanf("%d",&n) == 1){
		if(n == -1)  break;
		for(int i=0 ; i < n ; ++i){
			scanf("%s",str);
			for(int j=0 ; str[j] ; ++j)
				a[i][j] = str[j]-'0';
		}
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int i=0 ; i < n ; ++i)
			for(int j=0 ; j < n ; ++j)
				if(dp[i][j] && (i!=n-1 || j!=n-1)){
					if(j+a[i][j] < n)
						dp[i][j+a[i][j]] += dp[i][j];
					if(i+a[i][j] < n)
						dp[i+a[i][j]][j] += dp[i][j];
				}
		printf("%I64d\n",dp[n-1][n-1]);
	}
	return 0;
}