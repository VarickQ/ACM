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
const int N   = 20;
const int inf = 2000000000;
typedef __int64 LL;

LL p[N], num[N], ans, l;
void dfs(int x, int len){
	if( l <= len ){
		ans = min(ans,x); return;
	}
	for(int i=0 ; i <= 9 ; ++i){
		LL tmp = i*p[len]+x;
		tmp = tmp*tmp/p[len];
		tmp %= 10;
		if( tmp == num[len] )
			dfs( i*p[len]+x, len+1 );
	}
}
int main(){
	p[0] = 1;
	for(int i=1 ; i <= 10 ; ++i)
		p[i] = p[i-1]*10;
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		l = 0;
		while(n){
			num[l++] = n%10;
			n /= 10;
		}
		ans = inf;
		dfs( 0, 0 );
		if( ans == inf ) printf("None\n");
		else printf("%I64d\n", ans);
	}
	return 0;
}