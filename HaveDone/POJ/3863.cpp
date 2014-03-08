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
const int N   = 200005;

int main(){
	int n,m,u,d,ans,Max;
	while( scanf("%d%d", &n, &m) == 2 ){
		ans = inf;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &u, &d);
			int x = (int)ceil((double)d*n/(u+d));
			Max = u*x-d*(n-x);
			if( Max == 0 ){
				x++;
				Max = u*x-d*(n-x);
			}
			if( ans > Max ) ans = Max;
		}
		printf("%d\n", ans);
	}
	return 0;
}