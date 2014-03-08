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
const int N   = 10005;

struct A{
	int p,d;
}a[N];
bool cmp( A a, A b ){
	return a.p > b.p;
}
int fa[N];
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void Union(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fy != fx)
       fa[fx] = fy;
}
int main(){
	int n,maxd;
	while( scanf("%d", &n) == 1 ){
		maxd = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%d %d", &a[i].p, &a[i].d);
			maxd = maxd>a[i].d?maxd:a[i].d;
		}
		sort( a, a+n, cmp );
		for(int i=0 ; i <= maxd ; ++i) fa[i] = i;
		int dl,ans = 0;
		for(int i=0 ; i < n ; ++i){
			dl = find( a[i].d );
			if( dl != 0 ){
				fa[dl] = dl-1;
				ans += a[i].p;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}