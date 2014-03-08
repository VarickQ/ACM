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
const int inf = 1000000000;
const int M   = 100000;
const int N   = 55;
//typedef long long ll;

int c[N],d[N][N],l,m;
bool vis[N][N];
int dp( int st, int ed ){
	if( vis[st][ed] ) return d[st][ed];
	else if( st == ed-1 ){
		vis[st][ed] = true;
		return 0;
	} else {
		d[st][ed] = inf;
		for(int i=st+1 ; i < ed ; ++i)
		{
			int temp = dp(st,i)+dp(i,ed)+c[ed]-c[st];
			d[st][ed]= min( d[st][ed], temp );
		}
	}
	vis[st][ed] = true;//+ AC, no+ TLE
	return d[st][ed];
}
int main(){
	while( scanf("%d", &l) && l ){
		scanf("%d", &m);

		c[0] = 0;
		for(int i=1 ; i <= m ; ++i)
			scanf("%d", &c[i]);
		c[++m] = l;

		memset( d, 0, sizeof( d ) );
		memset( vis, false, sizeof( vis ) );
		printf("The minimum cutting is %d.\n", dp( 0, m ));
	}
	return 0;
}