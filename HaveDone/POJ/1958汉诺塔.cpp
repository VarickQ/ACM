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
const int M   = 100000;
const int N   = 10000;

int main(){
	int dp[15];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for(int i=4 ; i <= 12 ; ++i){
		int temp = inf;
		for(int k=1 ; k < i ; ++k)
			temp = min( temp , 2*dp[k]+(1<<(i-k))-1 );
		dp[i] = temp;
	}

	for(int i=1 ; i <= 12 ; ++i)
		printf("%d\n", dp[i]);
	return 0;
}