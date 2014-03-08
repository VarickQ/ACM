/*�������ַ������󾭹����ٴε���ɾ�Ĳ�����ʹ�����ַ�����ͬ��
��poj2192���ƣ�
��dp[n][m]��¼ʹstr1ǰn���ַ���str2ǰm���ַ���ͬ�����ٲ�������
ÿ�ε��ж϶��������������str1ǰi���ַ�str2ǰj-1���ַ���
str1ǰi-1���ַ�str2ǰj���ַ���str1ǰi-1���ַ�str2ǰj-1���ַ���
ȡ��������������β��������Сֵ����*/
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
const int N = 1005;

int dp[N][N];
//str1 ǰi���ַ� �� str2 ǰj���ַ� �����Ҫ��������
int main(){
	int len1, len2;
	char str1[N],str2[N];
	while( scanf("%d%s%d%s", &len1, str1, &len2, str2) != EOF ){
		memset( dp, 0, sizeof( dp ) );
		for(int i=0 ; i <= len1 ; ++i)
			dp[i][0] = i;
		for(int i=0 ; i <= len2 ; ++i)
			dp[0][i] = i;
		for(int i=1 ; i <= len1 ; ++i)
			for(int j=1 ; j <= len2 ; ++j){
				if( str1[i-1] == str2[j-1] )
					dp[i][j] = min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]));
				else
					dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
			}
		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}