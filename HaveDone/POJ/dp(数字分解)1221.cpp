/*
1)        ������������i(i<N)������������N�ķֽ��д���i����itg[N][i]�ɱ�ʾΪN�ķֽ�����С������i����С������i�������ڵ���i+1�Ĳ��֣�����
itg[N][i] = itg[N-2i][i] + itg[N][i+1]
2)        ��ʼ�������⣬��������0�ķֽ⣬����1)�е����ۣ���itg[0][i] = 1 (i=1,2, . . ., N)�����⣬��i>N/2ʱ��itg[N][i] = 1��������Ȼ�ģ�
*/

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
const int N = 305;
typedef long long ll;

ll dp[N][N];
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int n;

	for(int i=1 ; i <= 300 ; ++i){
		dp[0][i] = 1;
		for(int j=i/2+1 ; j <= i ; ++j)
			dp[i][j] = 1;
	}
	for(int i=1 ; i <= 300 ; ++i)
		for(int j=i/2 ; j >= 1 ; --j)
			dp[i][j] = dp[i-2*j][j]+dp[i][j+1];

	while( scanf("%d", &n) && n ){
		printf("%d %lld\n", n, dp[n][1]);
	}
	return 0;
}