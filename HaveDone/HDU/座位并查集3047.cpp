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
const int N   = 50005;

int fa[N],wei[N];
int find(int x){
	if( fa[x] == x ) return x;
	else {
		int temp = fa[x];
		fa[x] = find( fa[x] );
		wei[x] = (wei[temp]+wei[x])%300;
		return fa[x];

	}
}
void Union( int x, int y, int num ){
    int fx = find(x);
    int fy = find(y);
    if(fy != fx)
       fa[fx] = fy;
	wei[fx] = (wei[y]-wei[x]+300+num)%300;
}
int main(){
	int n,m,a,b,x;
	while( scanf("%d%d", &n, &m) == 2 ){
		for(int i=0 ; i <= n ; ++i){
			fa[i] = i;
			wei[i] = 0;
		}
		int ans = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &x);
			if( find(a) == find(b) ){
				if( abs(wei[a]-wei[b]+300)%300 != x )
					ans++;
			} else {
				Union( a, b, x );
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}