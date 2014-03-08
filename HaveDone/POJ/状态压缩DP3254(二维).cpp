#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 4200;
const int MOD = 100000000;

int mat[15];
int dp[15][N];
//dp[i][k]表示第r行处于状态k时，前r行的情况数总和。
int cnt,stk[N];
bool ok(int x){
	if(x & (x<<1)) return false;
	return true;
}
void init(int n){
	cnt = 0;
	for(int i=0 ; i < (1<<n) ; ++i)
		if(ok(i)) stk[cnt++] = i;
}
int main(){
	int n,m,a,i,j,r;
	while(scanf("%d%d",&n,&m) == 2)
	{
		memset(dp,0,sizeof(dp));
		init(m);
		for(i=0 ; i < n ; ++i)
			for(j=0 ; j < m ; ++j){
				scanf("%d",&a);
				if(a==0) mat[i] |= (1<<j);
			}
		for(i=0 ; i < cnt ; ++i)
			if(!(stk[i]&mat[0]))
				dp[0][i] = 1;
		for(int r=1 ; r < n ; ++r)
			for(i=0 ; i < cnt ; ++i){
				if(stk[i]&mat[r]) continue;
				for(j=0 ; j < cnt ; ++j){
					if(stk[i]&stk[j]) continue;
					dp[r][i] = (dp[r][i]+dp[r-1][j])%MOD;
				}
			}
		int ans = 0;
		for(i=0 ; i < cnt ; ++i)
			ans = (ans+dp[n-1][i])%MOD;
		printf("%d\n",ans);
	}
	return 0;
}