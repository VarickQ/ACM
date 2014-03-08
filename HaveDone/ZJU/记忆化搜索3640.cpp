#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 1001000;
const double pp = (1.0+sqrt(5.0))/2.0;

double dp[N];
int c[N],t[N],n;
bool vis[N];
double dfs(int f){
	if(vis[f]) return dp[f];
	vis[f] = true;
	for(int i=0 ; i < n ; ++i){
		if(f > c[i]) dp[f] += t[i];
		else dp[f] += dfs(c[i]+f)+1.0;
	}
	return dp[f]/=n;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\Qian\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\Qian\\Desktop\\out.txt","w",stdout);
#endif
////////////////////////////////////////
	int f;
	while( scanf("%d%d", &n, &f) != EOF ){
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &c[i]);
			t[i] = pp*c[i]*c[i];
		}
		memset( vis, 0, sizeof( vis ) );
		memset( dp, 0, sizeof( dp ) );
		printf("%.3lf\n", dfs(f));
	}
	return 0;
}