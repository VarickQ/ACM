#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const int N = 3500;
const int inf = 1000000000;

struct A{
	int x,y;
}a[N];
bool cmp( A a, A b ){
	if( a.x == b.x ) return a.y < b.y;
	return a.x < b.x;
}
int c[60][205];
int main(){
	int n, m;
	while( scanf("%d%d", &n, &m) && (n+m) ){
		for(int i=0 ; i < n*n ; ++i)
			scanf("%d%d", &a[i].x, &a[i].y);
		sort( a, a+n*n, cmp );
		for(int i=0 ; i < n ; ++i)
			for(int j=0 ; j < n ; ++j)
				c[i][j] = a[i*n+j].y;
		int ans = inf;
		for(int i=1 ; i <= m ; ++i){
			int num = 0;
			for(int j=0 ; j < n ; ++j)
				for(int k=0 ; k < n ; ++k)
					num += abs(c[j][k]-i-k);
			if( num < ans ) ans = num;
		}
		printf("%d\n", ans);
	}
	return 0;
}