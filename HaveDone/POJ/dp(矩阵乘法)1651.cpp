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
const int M   = 105;
const int N   = 105;
typedef long long ll;

int dp[N][N],a[N];
int main(){
	int n;
	while( scanf("%d", &n) == 1 ){
		memset( dp, 0, sizeof( dp ) );
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &a[i]);
		for(int l=2 ; l < n ; ++l)//ö�ٳ���
			for(int i=0 ; i+l < n ; ++i){//ö�����
				int j=i+l;//��β
				int Min = inf;
				for(int k=i+1 ; k < j ; ++k)//ʹ��һ��ֵ��С
					Min = min(Min,dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
				if( Min < dp[i][j] || dp[i][j]==0 )
					dp[i][j] = Min;
			}
		printf("%d\n", dp[0][n-1]);
	}
	return 0;
}