//A
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
const int M = 200005;
const int N = 6005;

struct Node{
	int u,v,next;
}a[M];
int heade[N],k;
void add( int u, int v ){
	a[k].u = u;
	a[k].v = v;
	a[k].next = heade[u];
	heade[u] = k++;
}
int dp[N][2],in[N],ou[N];
void dfs( int now ){
	int i;
	//if( ou[now] == 0 ) return ;
	for( i=heade[now] ; i!=-1 ; i=a[i].next ){
		dfs(a[i].v);
		dp[now][1] += dp[a[i].v][0];
		dp[now][0] += max(dp[a[i].v][1],dp[a[i].v][0]);
	}
}
int main(){
	int n;
	while( scanf("%d", &n) == 1 ){
		memset( in, 0, sizeof( in ) );
		memset( ou, 0, sizeof( ou ) );
		memset( dp, 0, sizeof( dp ) );
		memset( heade, -1, sizeof( heade ) );
		k = 0;
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &dp[i][1]);
		int L,K;
		while( scanf("%d%d",&L,&K) && (L+K) ){
			add( K, L );
			ou[K]++; in[L]++;
		}
		int pos = 0;
		for(int i=1 ; i <= n ; ++i)
			if(in[i] == 0) pos = i;
		dfs(pos);
		int ans = max(dp[pos][1],dp[pos][0]);
		printf("%d\n", ans);
	}
	return 0;
}

//D
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 200005;
const int N = 1001;

bool map[N][N];
double dp[2][N];
int main(){
	int n,m,k;
	while( scanf("%d%d",&m,&n) == 2 ){
		memset( map, 0, sizeof( map ) );
		memset( dp, 0, sizeof( dp ) );
		scanf("%d", &k);
		int a,b;
		while(k--){
			scanf("%d%d", &a, &b);
			map[b][a] = 1;
		}
		for(int i=1 ; i <= m ; ++i)
			dp[0][i] = i;
		for(int i=1 ; i <= n ; ++i){
			int t = i&1;
			dp[t][0] = i;
			for(int j=1 ; j <= m ; ++j){
				if( map[i][j] == 1 )
					dp[t][j] = min(dp[t^1][j-1]+sqrt(2.0),min(dp[t^1][j]+1,dp[t][j-1]+1));
				else
					dp[t][j] = min(dp[t^1][j]+1,dp[t][j-1]+1);
			}
		}
		printf("%.0lf\n", 100*dp[n&1][m]);
	}
	return 0;
}

//H
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
const int M = 20005;
const int N = 10005;

struct Edge{
	int v,next;
}e[M];
int heade[N],k,n,num;
int fa[N],in[N];
int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
void Union(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fy != fx){
       fa[fx] = fy;
	   num--;
	}
}
void add( int u, int v ){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
int stack[N],top,a[M],b[M];
char ch[M];
void topsort(){
	int i,j;
	top = 0;
	for( i=0 ; i < n ; ++i ){
		if( in[i] == 0 && i == find(i) )
			 stack[top++] = i;
	}
	bool f = false;
	while( top ){
		if( top > 1 ) f = true;
		int u = stack[--top];
		num--;
		for( j=heade[u] ; j!=-1 ; j=e[j].next ){
			if( --in[e[j].v] == 0 )
				stack[top++] = e[j].v;
		}
	}
	if( num > 0 ) printf("CONFLICT\n");
	else if( f ) printf("UNCERTAIN\n");
	else printf("OK\n");
}
void init(){
	for(int i=0 ; i <= n ; ++i) fa[i] = i;
	memset( in, 0, sizeof( in ) );
	memset( heade, -1, sizeof( heade ) );
	k = 0;
	num = n;
}
int main(){
	int m;
	while( scanf("%d%d", &n, &m) != EOF ){
		init();
		bool f = false;
		for(int i=0 ; i < m ; ++i){
			scanf("%d %c %d", &a[i], &ch[i], &b[i]);
			if( ch[i]=='=' )
				Union( a[i], b[i] );
		}
		for(int i=0 ; i < m ; ++i){
			if( ch[i] == '=' ) continue;
			int x = find(a[i]);
			int y = find(b[i]);
			if( x == y ) f = true;
			if( ch[i]=='>' ){
				add( x, y );
				in[y]++;
			}
			else if( ch[i]=='<' ){
				add( y, x );
				in[x]++;
			}
		}
		if( f ) printf("CONFLICT\n");
		else topsort();
	}
	return 0;
}