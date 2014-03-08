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
const int N = 35000;
typedef long long LL;

int a[N],b[N],c[N],m;
int gao(int *a, int x,int d){
	int cnt = 0;
	for(int i=0 ; i < (1<<x) ; ++i){
		int sum = 0;
		for(int j=0 ; j < x ; ++j)
			if( i&(1<<j) ) sum += c[j+d];
		if( sum <= m ) a[cnt++] = sum;
	}
	return cnt;
}
int main(){
	int n;
	while( scanf("%d%d", &n, &m) != EOF ){
		CLR( a, 0 );
		CLR( b, 0 );
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &c[i]);
		int l = n / 2;
		int r = n - l;
		int len1 = gao( a, l, 0 );
		int len2 = gao( b, r, l );
		sort( a, a+len1 );
		sort( b, b+len2 );
		int i = 0, j=len2-1, ans = 0;
		bool f = false;
		for( ; i < len1 ; ++i ){
			ans = max( ans, a[i] );
			for( ; j >= 0 ; --j ){
				ans = max( ans, b[j] );
				if( a[i]+b[j] <= m ){
					ans = max( ans, a[i]+b[j] );
					if( a[i]+b[j] == m ) f = true;
					break;
				}
			}
			if( f ) break;
		}
		printf("%d\n", ans);
	}
    return 0;
}