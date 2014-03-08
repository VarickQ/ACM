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
const int N = 300050;
const int MOD = 1000000007;
typedef long long ll;

bool dp[N];//设dp[i]为价值i的可达性. 初始dp[0]=1;
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int a[10],cs=1;
	while( scanf("%d", &a[1]) != EOF ){
		int t = a[1];
		for(int i=2 ; i <= 6 ; ++i){
			scanf("%d", &a[i]);
			t += a[i]*i;
		}
		if( t == 0 ) break;
		printf("Collection #%d:\n",cs++);
		if( t&1 ){
			printf("Can't be divided.\n\n");
			continue;
		}
		 t >>= 1;
		 CLR( dp, 0 );
		 dp[0] = true;
		 for(int i=1 ; i <= 6 ; ++i)
		 {
			 for(int j=t ; j >= 0 ; --j){
				 if( dp[j] ){
					 int p = j;
					 for(int k=0 ; k < a[i] ; ++k)
					 {
						 p += i;
						 dp[p] = true;
					 }
				 }
			 }
		 }
		 if( dp[t] ) printf("Can be divided.\n\n");
		 else printf("Can't be divided.\n\n");
	}
	return 0;
}