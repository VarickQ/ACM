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

int c[12]={5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[N];
int main(){
	int a,b;
	dp[0] = 1;
	for(int i=0 ; i < 11 ; ++i)
		for(int j=c[i] ; j <= N-5 ; ++j)
			dp[j] += dp[j-c[i]];
	while( scanf("%d.%d", &a, &b) != EOF ){
		if( a == 0 && b == 0) break;
		int n = a*100+b;
		printf("%3d.%02d%17lld\n",a,b,dp[n]);
	}
	return 0;
}