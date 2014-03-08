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
const int N   = 205;
typedef __int64 LL;
const LL MOD   = 1000000009;
const double eps = 1e-8;

struct A{
	int x, y, t, v;
}a[N];
int dis(A a){
	return a.x*a.x+a.y*a.y;
}
bool cmp( const A a, const A b ){
	return dis(a) < dis(b);
}
bool vis[N];
vector<A> va[N];
int dp[40100];
int main(){
	int n, t, cs=1;
	while( scanf("%d%d", &n, &t) != EOF ){
		for(int i=0 ; i < N ; ++i) va[i].clear();
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].t, &a[i].v);
		//sort( a, a+n, cmp );
		memset( vis, 0, sizeof( vis ) );
		int cnt = 0;
		for(int i=0 ; i < n ; ++i){
			if( vis[i] ) continue;
			vis[i] = true;
			va[cnt].push_back(a[i]);
			for(int j=i+1 ; j < n ; ++j){
				if( vis[j] ) continue;
				if( fabs(atan2(a[i].y*1.0,a[i].x*1.0)-atan2(a[j].y*1.0,a[j].x*1.0)) < eps ){
					vis[j] = true;
					va[cnt].push_back(a[j]);
				}
			}
			sort( va[cnt].begin(), va[cnt].end(), cmp );
			cnt++;
		}
		memset( dp, 0, sizeof( dp ) );
		for(int i=0 ; i < cnt ; ++i){
			for(int k=t ; k >= 0 ; --k){
				int tmp = 0, val = 0;
				for(int j=0 ; j < va[i].size() ; ++j){
					tmp += va[i][j].t;
					val += va[i][j].v;
					if( k >= tmp )
						dp[k] = max(dp[k],dp[k-tmp]+val);
					else break;
				}
			}
		}
		printf("Case %d: %d\n", cs++, dp[t]);
	}
	return 0;
}