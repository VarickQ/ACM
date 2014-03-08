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
#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int inf = 2000000000;
const int M = 1300;
const int N = 15;

bool su[M];
int prime[M],cnt;
void primelist(){
	su[1] = su[0] = true;
	for(ll i=2 ; i <= M-100 ; i++)
		if(!su[i]){
			for(ll j=i*i ; j <= M-100 ; j+=i)
				su[j] = true;
		}
	cnt = 0;
	for(int i=2 ; i <= M-100 ; ++i)
		if(!su[i]) prime[cnt++] = i;
}
int dp[M-100][N];
int main(){
	primelist();
	int n,k;
	dp[0][0] = 1;
	for(int i=0 ; i < cnt ; ++i)
		for(int j=1120-prime[i] ; j >= 0 ; --j)
			for(int k=14 ; k >= 1 ; --k)
				dp[j+prime[i]][k] += dp[j][k-1];
	//dp[i][j],i由j个素数组成的种数
	while(scanf("%d%d",&n,&k) && (n+k)){
		printf("%d\n",dp[n][k]);
	}
	return 0;
}