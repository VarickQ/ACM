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
const int N   = 100005;

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
	int T,n,m,a,b;
	char ch[2];
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=0 ; i <= n ; ++i){
			fa[i] = i;
			rank[i] = 0;
		}
		for(int i=0 ; i < m ; ++i){
			scanf("%s%d%d", ch, &a, &b);
			int rx = find( a );
			int ry = find( b );
			if( ch[0] == 'A' ){
				if( rx != ry )
					printf("Not sure yet.\n");
				else if( rank[a] == rank[b] )
					printf("In the same gang.\n");
				else printf("In different gangs.\n");
			} else {
				fa[rx] = ry;
				rank[rx] = (rank[b]-rank[a]+1+2)%2;
			}
		}
	}
	return 0;
}