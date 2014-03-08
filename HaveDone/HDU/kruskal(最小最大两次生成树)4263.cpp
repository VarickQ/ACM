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
const int N   = 1010;
const int M   = 1100000;
const int inf = 2000000000;
typedef __int64 LL;

struct Edge{
	int x, y, val;
}e[M];
int fa[N],n,m,k;
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
bool cmp1(Edge a, Edge b){return a.val < b.val;}
bool cmp2(Edge a, Edge b){return a.val > b.val;}
int kruskal(int id){
	int ans = 0;
	for(int i=0 ; i <= n ; ++i) fa[i] = i;
	if(id==1) sort( e, e+m, cmp1 );
	else sort( e, e+m, cmp2 );
	for(int i=0 ; i < m ; ++i){
		int x = find( e[i].x );
		int y = find( e[i].y );
		if( x != y ){
			ans += e[i].val;
			fa[x] = y;
		}
	}
	return ans;
}
int main(){
	int a,b;
	char s[3];
	while( scanf("%d%d%d", &n, &m, &k) && (n+m+k) ){
		for(int i=0 ; i < m ; ++i){
			scanf("%s%d%d", s, &a, &b);
			e[i].x = a; e[i].y = b;
			if( s[0] == 'B' ) e[i].val = 1;
			else e[i].val = 0;
		}
		int Max = kruskal(0);
		int Min = kruskal(1);
		if( Min<=k && k<=Max ) printf("1\n");
		else printf("0\n");
	}
	return 0;
}