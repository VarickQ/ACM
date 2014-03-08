#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N = 100005;
const int M = 100005;
typedef long long LL;

struct Node{
	int v, nxt;
}e[M];
int head[N], ne, n;
LL ans;
void add(int u,int v){
	e[ne].v = v;
	e[ne].nxt = head[u];
	head[u] = ne++;
}
int dfs( int u, int dep ){
	int cnt = 0;
	for(int i=head[u] ; i!=-1 ; i=e[i].nxt){
		cnt += dfs(e[i].v,dep+1);
	}
	ans += n-dep-cnt;
	return cnt+1;
}
/* ’‚√¥–¥RE
int dfs( int u ){
	int cnt = 0;
	for(int i=head[u] ; i!=-1 ; i=e[i].nxt){
		int num = dfs(e[i].v);
		if( i != head[u] ) ans += cnt*num;
		cnt += num;
	}
	return cnt+1;
}*/
int main(){
	int T, u, v;
	scanf("%d", &T);
	for(int cs=1 ; cs <= T ; ++cs){
		scanf("%d", &n);
		ne = 0;
		memset( head, -1, sizeof( head ) );
		//for(int i=1 ; i <= n ; ++i) head[i] = -1;
		for(int i=0 ; i < n-1 ; ++i){
			scanf("%d%d", &u, &v);
			add( u, v );
		}
		ans = 0;
		int tot = dfs( 1, 1 );
		printf("Case %d: %d %lld\n", cs, tot-1, ans/2);
	}
	return 0;
}
