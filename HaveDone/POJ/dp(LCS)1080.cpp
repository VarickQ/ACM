//http://poj.org/showmessage?message_id=74842
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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 105;
typedef long long ll;

int dp[N][N],s[N][N];
int main(){
	int T,n1,n2;
	char s1[N],s2[N];
	s['A']['A'] = s['C']['C'] = s['G']['G'] = s['T']['T'] = 5;
	s['A']['C'] = s['C']['A'] = -1;
	s['A']['G'] = s['G']['A'] = -2;
	s['A']['T'] = s['T']['A'] = -1;
	s['A']['-'] = s['-']['A'] = -3;
	s['G']['C'] = s['C']['G'] = -3;
	s['T']['C'] = s['C']['T'] = -2;
	s['-']['C'] = s['C']['-'] = -4;
	s['T']['G'] = s['G']['T'] = -2;
	s['G']['-'] = s['-']['G'] = -2;
	s['T']['-'] = s['-']['T'] = -1;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%s%d%s", &n1, s1+1, &n2, s2+1);
		//int n = max(n1,n2);
		CLR( dp, 0 );
		for(int i=1 ; i <= n1 ; ++i)
			dp[i][0] = dp[i-1][0]+s[s1[i]]['-'];
		for(int i=1 ; i <= n2 ; ++i)
			dp[0][i] = dp[0][i-1]+s['-'][s2[i]];
		for(int i=1 ; i <= n1 ; ++i)
			for(int j=1 ; j <= n2 ; ++j)
				dp[i][j] = max(dp[i-1][j-1] + s[s1[i]][s2[j]] ,
				max(dp[i-1][j]+s[s1[i]]['-'],dp[i][j-1]+s['-'][s2[j]]));
		printf("%d\n", dp[n1][n2]);
	}
	return 0;
}