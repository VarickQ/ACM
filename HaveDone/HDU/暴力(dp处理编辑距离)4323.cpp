#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N = 1505;

char c[N][15];
int n, m, dp[15][15];
int ok(char a[], char b[],int l1,int l2){
	//CLR( dp, 0x4f );
	dp[0][0] = 0;
	for(int i=1 ; i <= l1 ; ++i) dp[i][0] = i;
	for(int i=1 ; i <= l2 ; ++i) dp[0][i] = i;
	for(int i=1 ; i <= l1 ; ++i)
		for(int j=1 ; j <= l2 ; ++j)
			if( a[i-1] == b[j-1] )
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
	return dp[l1][l2];
}
int gao(char s[], int t){
	int res = 0;
	int l1 = strlen(s);
	for(int i=0 ; i < n ; ++i){
		int l2 = strlen(c[i]);
		if( abs(l1-l2) > t ) continue;
		if( ok( s, c[i], l1, l2 ) <= t ) res++;
	}
	return res;
}
int main(){
	int T, t, cs = 1;
	char s[15];
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d\n", &n, &m);
		for(int i=0 ; i < n ; ++i)
			gets( c[i] );
		printf("Case #%d:\n", cs++);
		while( m-- ){
			scanf("%s %d", s, &t);
			printf("%d\n", gao( s, t ));
		}
	}
    return 0;
}