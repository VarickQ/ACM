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
const int N   = 30005;

//由左向右求i左边2的个数n2[i]，
//自右向左求i右边1的个数n1[i]。
//最后找到min(n2[i]+n1[i])-1就是结果。
int a[N],n2[N],n1[N];
int main(){
	int n;
	while( scanf("%d", &n) == 1 ){
		memset( n1, 0, sizeof( n1 ) );
		memset( n2, 0, sizeof( n2 ) );
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &a[i]);
		for(int i=1 ; i <= n ; ++i)
			if( a[i] == 2 )
				n2[i] = n2[i-1]+1;
			else n2[i] = n2[i-1];
		for(int i=n ; i >= 1 ; --i)
			if( a[i] == 1 )
				n1[i] = n1[i+1]+1;
			else n1[i] = n1[i+1];

		int ans = inf;
		for(int i=1 ; i <= n ; ++i)
			if(ans > n1[i]+n2[i]-1 )
				ans = n1[i]+n2[i]-1;
		printf("%d\n", ans);
	}
	return 0;
}