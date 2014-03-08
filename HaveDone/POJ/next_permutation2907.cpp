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
const int N   = 100050;

struct point{
	int x,y;
}s,a[12],t;
int main(){
	//freopen( "in.txt", "r", stdin );

	int T,x,y,n;
	char c[12];
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &x, &y);
		scanf("%d%d", &s.x, &s.y);
		scanf("%d", &n);
		int k = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%d%d", &a[i].x, &a[i].y);
			c[ k++ ] = i + '0';
		}
		c[k] = '\0';
		int ans = inf;
		do{
			int count = 0;
			t = s;
			for(int i=0 ; i < k ; ++i){
				count += abs(t.x-a[c[i]-'0'].x)+abs(t.y-a[c[i]-'0'].y);
				t = a[c[i]-'0'];
			}
			count += abs(t.x-s.x)+abs(t.y-s.y);;
			if( ans > count ) ans = count;
		} while( next_permutation( c, c+k ) );
		printf("The shortest path has length %d\n", ans);
	}
	return 0;
}