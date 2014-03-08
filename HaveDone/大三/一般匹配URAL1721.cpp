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
const int N = 1010;

struct Node{
	int v, nxt;
}e[N*N];
int w[N], ne, ra[N], mch[N];
char s[N][50], x[N][50];
bool vis[N];
void add( int u, int v ){
	e[ne].v = v;
	e[ne].nxt = w[u];
	w[u] = ne++;
}
bool find(int u){
	for(int i=w[u] ; i!=-1 ; i=e[i].nxt){
		int v = e[i].v;
		if( !vis[v] ){
			vis[v] = true;
			if( mch[v]==0 || find(mch[v]) ){
				mch[v] = u;
				return true;
			}
		}
	}
	return false;
}
void gao( int i, int j ){
	if( (x[i][0]=='a'||x[j][0]=='a') )
		add( i, j );
	else if( (x[i][0]=='s'&&x[j][0]=='t')||
		(x[i][0]=='t'&&x[j][0]=='s') )
		add( i, j );
}
int main(){
	int n;
	while( scanf("%d", &n) != EOF ){
		ne = 0;
		memset( w, -1, sizeof( w ) );
		for(int i=1 ; i <= n ; ++i)
			scanf("%s %s %d", s[i], x[i], &ra[i]);
		for(int i=1 ; i <= n ; ++i){
			if( ra[i]%4 >= 2 ) continue;
			for(int j=1 ; j <= n ; ++j){
				if( ra[j]%4 < 2 ) continue;
				if( abs(ra[i] - ra[j]) == 2 )
					gao( i, j );
			}
		}
		int ans = 0;
		memset( mch, 0, sizeof( mch ) );
		for(int i=1 ; i <= n ; ++i){
			memset( vis, 0, sizeof( vis ) );
			if( find(i) ) ans++;
		}
		printf("%d\n", ans);
		memset( vis, 0, sizeof( vis ) );
		for(int i=1 ; i <= n ; ++i){
			if( mch[i] && !vis[i] && !vis[mch[i]] ){
				vis[i] = vis[mch[i]] = true;
				if( x[i][0]=='s' || x[mch[i]][0]=='t' )
					printf("%s %s\n", s[i], s[mch[i]]);
				else
					printf("%s %s\n", s[mch[i]], s[i]);
			}
		}
	}
	return 0;
}
