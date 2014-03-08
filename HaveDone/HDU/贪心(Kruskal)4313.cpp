#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
typedef __int64 LL;
const int N   = 100010;
const int M   = 300000;
const LL inf = (1LL<<60);

struct edge{
	int x, y;
	LL val;
}a[N];
int fa[N],n,k;
bool mark[N];
bool cmp(edge a,edge b){
	return a.val > b.val;
}
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void Kruskal(){
	LL ans = 0;
	for(int i=0 ; i <= n ; ++i) fa[i] = i;
	sort( a, a+n-1, cmp );
	for(int i=0 ; i < n-1 ; ++i){
		int x = find(a[i].x);
		int y = find(a[i].y);
		if(x != y){
			if( mark[x] && mark[y] )
				ans += a[i].val;
			else if( mark[x] || mark[y] )
				mark[x] = mark[y] = true;
			fa[x] = y;
		}
	}
	printf("%I64d\n",ans);
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		CLR( mark, 0 );
		scanf("%d%d", &n, &k);
		for(int i=0 ; i < n-1 ; ++i)
			scanf("%d%d%I64d", &a[i].x, &a[i].y, &a[i].val);
		int x;
		for(int i=0 ; i < k ; ++i){
			scanf("%d", &x);
			mark[x] = true;
		}
		Kruskal();
	}
    return 0;
}