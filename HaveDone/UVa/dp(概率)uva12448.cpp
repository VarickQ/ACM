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
const int MOD = 1000000007;
typedef long long ll;

ll gcd(ll a,ll b){//递归
	return b?gcd(b,a%b):a;
}
ll C(int n, int k){
	ll r=1, i;
	for (i = 1; i <= k; ++ i) {
		r *= (n-i+1); r /= i;
	}
	return r;
}
ll Pow(int n,int l){
	ll ans = 1;
	for(int i=0 ; i < l ; ++i)
		ans *= n;
	return ans;
}
ll dp[12][12];//投i次，已经有j次在k个里面
int main(){
	int T,n,m,k;
	ll fz,fm,d;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d", &n, &m, &k);
		CLR( dp, 0 );
		dp[0][0] = dp[1][1] = 1;
		for(int i=1 ; i <= m ; ++i)
			for(int j=1 ; j <= k ; ++j)
				//dp[i-1][j]*j投在已经投过的j个中，dp[i-1][j-1]*(n-j+1)投在没有投过的地方
				dp[i][j] = dp[i-1][j]*j+dp[i-1][j-1]*(n-j+1);
		fz = dp[m][k];
		fm = Pow(n,m);
		d = gcd(fz,fm);
		fz /= d;
		fm /= d;
		if( fz==0 || fm==0 ) printf("0\n");
		else if( fz == fm ) printf("1\n");
		else printf("%lld/%lld\n", fz, fm);
	}
	return 0;
}