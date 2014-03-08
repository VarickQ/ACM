#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//dp[r][i][k]��ʾ��r�е�״̬Ϊk����r-1�е�״̬Ϊiʱ��
//ǰr������ܹ���װ�Ĵ�������

int mat[102];
//mat[i]�Ķ����Ʊ�ʾÿһ�е�H�ֲ�״̬��
int cnt,stk[65],sum[65];
// cnt��ʾ״̬������stk[i]��ʾ��i��״̬��sum[i]��ʾ��i��״̬��װ�Ĵ�������
int dp[102][65][65];

bool ok(int x){//�ж�״̬x�Ƿ��Ƿ������������ڼ��С��2
	if(x & (x<<1)) return false;
	if(x & (x<<2)) return false;
	return true;
}
int GetSum(int x){//���״̬x�а�װ�˶����Ŵ��ڣ�x�Ķ������м���1
	int num=0;
	while(x > 0){
		if(x & 1) num++;
		x >>= 1;
	}
	return num;
}
void init(int n){//Ԥ����������п��ܵ�״̬��
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
		for(i=0 ; i < cnt ; ++i)//  ��һ�е�״̬���⿼�ǡ�
			if(!(stk[i]&mat[0]))
				dp[0][0][i] = sum[i];
		for(int r=1 ; r < n ; ++r)
			for(i=0 ; i < cnt ; ++i){//  ö�ٵ�r�е�״̬��
				if(stk[i]&mat[r]) continue;
				for(j=0 ; j < cnt ; ++j){//  ö�ٵ�r-1�е�״̬��
					if(stk[i]&stk[j]) continue;
					for(k=0 ; k < cnt ; ++k){//  ö�ٵ�r-2�е�״̬��
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