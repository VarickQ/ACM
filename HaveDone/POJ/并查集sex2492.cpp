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
typedef __int64 ll;
const int inf = 2000000000;
const int N   = 2005;

int fa[N],rank[N];

int find( int x ){
	if(x == fa[x]) return x;
	else {
		int temp = fa[x];
		fa[x] = find( fa[x] );
		rank[x] = (rank[temp]+rank[x])%2;
		return fa[x];
	}
}

int main(){
	int T,n,m,a,b,cs=1;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=0 ; i <= n ; ++i){
			fa[i] = i;
			rank[i] = 0;
		}
		bool f = false;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &a, &b);
			if( !f ){
				int rx = find( a );
				int ry = find( b );
				if( rx == ry ){
					if( (rank[a]+rank[b])%2 != 1 )
						f = true;
				} else {
					fa[rx] = ry;
					rank[rx] = (rank[b]-rank[a]+1+2)%2;
				}
			}
		}
		if( f ){
			printf("Scenario #%d:\nSuspicious bugs found!\n\n", cs++);
		} else {
			printf("Scenario #%d:\nNo suspicious bugs found!\n\n", cs++);
		}
	}
	return 0;
}