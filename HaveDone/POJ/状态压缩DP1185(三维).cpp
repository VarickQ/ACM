#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//dp[r][i][k]表示第r行的状态为k，第r-1行的状态为i时候，
//前r行最多能够安装的大炮数量

int mat[102];
//mat[i]的二进制表示每一行的H分布状态。
int cnt,stk[65],sum[65];
// cnt表示状态总数，stk[i]表示第i种状态，sum[i]表示第i种状态安装的大炮数量
int dp[102][65][65];

bool ok(int x){//判断状态x是否是否会出现两个大炮间隔小于2
	if(x & (x<<1)) return false;
	if(x & (x<<2)) return false;
	return true;
}
int GetSum(int x){//求出状态x中安装了多少门大炮，x的二进制有几个1
	int num=0;
	while(x > 0){
		if(x & 1) num++;
		x >>= 1;
	}
	return num;
}
void init(int n){//预处理求出多有可能的状态。
	cnt = 0;
	for(int i=0 ; i < (1<<n) ; ++i)
		if(ok(i)){
			stk[cnt] = i;
			sum[cnt++] = GetSum(i);
		}
}
int main(){
	int i,j,k,n,m;
	char ch;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		memset(dp,-1,sizeof(dp));
		for(i=0 ; i < n ; ++i)
			for(j=0 ; j < m ; ++j){
				scanf(" %c",&ch);
				if(ch == 'H') mat[i] |= (1<<j);
			}
		init(m);
		for(i=0 ; i < cnt ; ++i)//  第一行的状态特殊考虑。
			if(!(stk[i]&mat[0]))
				dp[0][0][i] = sum[i];
		for(int r=1 ; r < n ; ++r)
			for(i=0 ; i < cnt ; ++i){//  枚举第r行的状态。
				if(stk[i]&mat[r]) continue;
				for(j=0 ; j < cnt ; ++j){//  枚举第r-1行的状态。
					if(stk[i]&stk[j]) continue;
					for(k=0 ; k < cnt ; ++k){//  枚举第r-2行的状态。
						if(stk[i]&stk[k]) continue;
						if(dp[r-1][k][j] == -1) continue;
						dp[r][j][i]=max(dp[r][j][i],dp[r-1][k][j]+sum[i]);
					}
				}
			}
		int ans = 0;
		for(i=0 ; i < cnt ; ++i)
			for(j=0 ; j < cnt ; ++j)
				ans = max(ans,dp[n-1][i][j]);
		printf("%d\n",ans);
	}
	return 0;
}