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
const int inf = 1000000000;
const int N = 105;
const int MOD = 1000000007;
typedef long long ll;
/*
*题意：n个制造商，每个制造商有m个商品，
*每个商品有 带宽b 和 价值p
*你要在每个制造商那里选一个商品
*使得你所选取的n样商品中的 最小带宽b/价值总和p 最大

*思路：找出每个制造商最小商品的最小带宽，和最大带宽的最小值
*最为区间，枚举其中的 带宽band 贪心使得p的和最小
*/
struct Node{
	int b,p;
}a[N][N];
bool cmp(const Node &a, const Node &b){
	return a.b < b.b;
}
int main(){
	int T,n,Min_b,Max_b,m[N];
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		Min_b = inf;
		Max_b = inf;
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &m[i]);
			for(int j=0 ; j < m[i] ; ++j)
				scanf("%d%d", &a[i][j].b, &a[i][j].p);
			sort( a[i], a[i]+m[i], cmp );
			if( a[i][0].b < Min_b ) Min_b = a[i][0].b;
			if( a[i][m[i]-1].b < Max_b ) Max_b = a[i][m[i]-1].b;
		}
		double ans=0;
		int band;
		for(int b=Min_b ; b <= Max_b ; ++b){
			int price = 0;
			band = inf;
			for(int i=0 ; i < n ; ++i)
			{
				int v = 0;
				//寻找区间内的 最小band
				for(int j=0 ; j < m[i] ; ++j)
					if( a[i][j].b >= b ){
						v = j; break;
					}
				//寻找比这个band大的，但是价值更小的p
				for(int j=v ; j < m[i] ; ++j)
					if( a[i][j].p < a[i][v].p )
						v = j;
				price += a[i][v].p;
				band = min( band, a[i][v].b );
			}
			ans = max(ans,(band+0.0)/price);
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}