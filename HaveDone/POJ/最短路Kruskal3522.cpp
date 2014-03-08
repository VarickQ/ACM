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
const int inf = 2000000000;
const int N   = 105;

struct edge{
	int x,y,value;
}a[5000];
int n,m,ans,fa[N];
bool mark[5000];
bool cmp( edge a, edge b ){
	return a.value < b.value;
}
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
int Kruskal( int x ){
	int Max = 0,s = 0;
	for(int i=0 ; i <= n ; ++i) fa[i] = i;
	for(int i=x ; i < m ; ++i){
		int x = find( a[i].x );
		int y = find( a[i].y );
		if( x != y ){
			Max = a[i].value;
			fa[x] = y;
			s++;
			if(s == n-1) break;
		}
	}
	if( s < n-1 ) return -1;
	else return Max;
}
int main(){
	int mm;
	while( scanf("%d%d", &n, &m) && (n+m) ){
		for(int i=0 ; i < m ; ++i)
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].value);
		ans = inf;
		mm = -1;
		sort( a, a+m, cmp );
		for(int i=0 ; i<m && m-i>=n-1 ; ++i){
			mm = Kruskal( i );
			if( mm == -1 ) continue;
			if( ans > mm-a[i].value )
				ans = mm-a[i].value;
			if( ans == 0 ) break;
		}
		if( ans != inf ) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}