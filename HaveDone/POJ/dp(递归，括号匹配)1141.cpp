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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 505;
typedef long long ll;

char str[N];
int dp[N][N],v[N][N];
void print(int i,int j){
	if( i > j ) return ;
	if( i == j ){
		if( str[i]=='(' || str[i]==')' )
			printf("()");
		else printf("[]");
	}
	else {
		if( v[i][j] == -1 ){
			printf("%c", str[i]);
			print(i+1, j-1);
			printf("%c", str[j]);
		}
		else {
			print( i, v[i][j] );
			print( v[i][j]+1, j );
		}
	}
}
int main(){
	while( gets(str) ){
		CLR( dp, 0 );
		CLR( v, 0 );
		int len = strlen(str);
		for(int i=0 ; i < len ; ++i)
			dp[i][i] = 1;
		for(int l=1 ; l < len ; ++l){
			for(int i=0 ; i < len-l ; ++i){
				int j = i+l;
				dp[i][j] = inf;
				if( (str[i]=='('&&str[j]==')') || (str[i]=='['&&str[j]==']') )
					if( dp[i][j] > dp[i+1][j-1] ){
						dp[i][j] = dp[i+1][j-1];
						v[i][j] = -1;
					}
				for(int k=i ; k < j ; ++k){
					if( dp[i][j] > dp[i][k] + dp[k+1][j] ){
						dp[i][j] = dp[i][k] + dp[k+1][j];
						v[i][j] = k;
					}
				}
			}
		}
		print(0, len-1);
		printf("\n");
	}
	return 0;
}