/*
双dfs强连通模板，求入度为0的联通块数量。
*/
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
const int inf = 1000000000;
const int M   = 200010;
const int N   = 100010;
typedef long long LL;

int n, m;
vector<int> va[N],vb[N];
int s[N], cn;
int belong[N], mark, in[N];
bool used[N];

void dfs1(int x){
	used[x] = true;
	int i;
	for( i=0 ; i < va[x].size() ; i++ ){
		if(!used[va[x][i]])
			dfs1(va[x][i]);
	}
	s[cn++] = x;
}
void dfs2(int x){
	belong[x] = mark;
	used[x] = true;
	int i;
	for( i=0 ; i < vb[x].size() ; i++ ){
		if(!used[vb[x][i]])
			dfs2(vb[x][i]);
	}
}

int main(){
	int T, u, v;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=0 ; i <= n ; ++i){
			va[i].clear();
			vb[i].clear();
		}
		cn = mark = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &u, &v);
			va[u].push_back( v );
			vb[v].push_back( u );
		}
		memset(used,false,sizeof(used));
		for(int i=1 ; i <= n ; i++ ){
			if( !used[i] ) dfs1(i);
		}
		memset(used,false,sizeof(used));
		for(int i=cn-1 ; i >= 0  ; i-- ){
			if( !used[s[i]] ){
				dfs2(s[i]);
				mark++;
			}
		}
		memset( in, 0, sizeof( in ) );
		for(int i=1 ; i <= n ; ++i)
			for(int j=0 ; j < va[i].size() ; ++j)
				if( belong[i] != belong[va[i][j]] )
					in[belong[va[i][j]]]++;
		int ans = 0;
		//printf("%d\n", mark);
		for(int i=0 ; i < mark ; ++i)
			if( in[i] == 0 ) ans++;
		printf("%d\n", ans);
	}
	return 0;
}