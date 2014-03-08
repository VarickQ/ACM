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

ll gcd(ll a,ll b){//�ݹ�
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
ll dp[12][12];//Ͷi�Σ��Ѿ���j����k������
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
				//dp[i-1][j]*jͶ���Ѿ�Ͷ����j���У�dp[i-1][j-1]*(n-j+1)Ͷ��û��Ͷ���ĵط�
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