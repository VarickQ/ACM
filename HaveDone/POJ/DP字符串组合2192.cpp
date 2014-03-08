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
typedef __int64 ll;
const int inf = 2000000000;
const int M   = 100000;
const int N   = 10000;

char s1[1005],s2[1005],s3[2010];
int dp[1005][1005];
//���⮔s1ǰi���ֺ�s2ǰj�����ܽM��s3 ǰi+j�֕r,
//���s1��s2����ܽM��s3, ��s1ǰi+1���ֺ�s2ǰj����
//���� s1ǰi���ֺ�s2ǰj+1����Ҳ�ض��ܽM��s3��ǰi+j+1����...
int main(){
	int n,i,j,cs,l1,l2;
	scanf("%d", &n);
	for( cs=1 ; cs <= n ; ++cs ){
		scanf("%s %s %s", s1, s2, s3);
		memset( dp, 0, sizeof( dp ) );
		l1 = strlen( s1 );
		l2 = strlen( s2 );
		dp[0][0] = 1;
		for( i=0 ; i <= l1 ; ++i){
			for( j=0 ; j <= l2 ; ++j){
				if( i!=0 && dp[i-1][j] ){
					if( s1[i-1] == s3[i+j-1] )
						dp[i][j] = 1;
				}
				else if( j!=0 && dp[i][j-1] ){
					if( s2[j-1] == s3[i+j-1] )
						dp[i][j] = 1;
				}
			}
		}
		printf("Data set %d: ", cs);
		if( dp[l1][l2] )
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}