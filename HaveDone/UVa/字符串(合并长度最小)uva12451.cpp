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
const int N = 105;
const int MOD = 1000000007;
typedef long long ll;

char str[N];
struct Node{
	int j,s;
}tm;
vector<Node> v[N];
int dp[N];
int L(int n){
	int c = 0;
	while(n){
		n/=10; c++;
	}
	return c;
}
int main(){
	int T;
	scanf("%d\n", &T);
	while( T-- ){
		scanf("%s", str+1);
		int len = strlen(str+1);
		CLR( dp, 0 );
		for(int i=0 ; i <= len ; ++i)
			v[i].clear();
		for(int k=1 ; k <= len/2+1 ; ++k)
		{
			for(int i=len ; i >= 2*k ; --i)
			{
				int tt = 1;
				while( i-tt*k-k >= 0 ){
					bool f = false;
					int l = k;
					for(int j=i-tt*k,p=i ; l > 0 ; --l,--j,--p)
					{
						if( str[p] != str[j] ){
							f = true; break;
						}
					}
					if( !f ){
						tm.j = i-tt*k-k+1;
						tm.s = k;
						v[i].push_back(tm);
						tt++;
					} else break;
				}
			}
		}
		dp[0] = 0;
		for(int i=1 ; i <= len ; ++i){
			dp[i] = dp[i-1]+1;
			for(int p=0 ; p < v[i].size() ; ++p)
			{
				int j = v[i][p].j;
				int s = v[i][p].s;
				dp[i] = min(dp[i],dp[j-1]+min(s+2+L((i-j+1)/s),i-j+1));
			}
		}
		printf("%d\n", dp[len]);
	}
	return 0;
}