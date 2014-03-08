#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long LL;
const int N = 1010;

struct Node{
	int w,s,id;
}a[N];
int dp[N],b[N],ans[N];
bool cmp( Node a, Node b ){
	if( a.w == b.w ) return a.s > b.s;
	return a.w < b.w;
}
int main(){
	int n, i, j;
	while( ~scanf("%d", &n) ){
		for( i=1 ; i <= n ; ++i ){
			scanf("%d%d", &a[i].w, &a[i].s);
			a[i].id = i;
		}
		sort( a+1, a+n+1, cmp );
		for( i=1 ; i <= n ; ++i )
			dp[i] = 1, b[i] = i;
		for( i=1 ; i <= n ; ++i ){
			for( j=1 ; j < i ; ++j )
				if( a[i].w>a[j].w && a[i].s<a[j].s && dp[i]<dp[j]+1)
					dp[i] = dp[j]+1, b[i] = j;
		}
		int pos, Max = 0;
		for( i=1 ; i <= n ; ++i )
			if( dp[i] > Max )
				Max = dp[i], pos = i;
		printf("%d\n", Max);
		for( i=0,j=pos ; Max-- ; j=b[j] )
			ans[i++] = a[j].id;
		for( --i ; i >= 0 ; --i )
			printf("%d\n", ans[i]);
	}
	return 0;
}