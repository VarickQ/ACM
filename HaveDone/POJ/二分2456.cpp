#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
typedef long long LL;
const int N   = 100005;
const int M   = 2500005;
const int inf = 1000000000;

int a[N], n, c;
bool ok(int len){
	int now = a[0]+len, cnt = 1;
	for(int i=1 ; i < n ; ++i)
		if( a[i] >= now ){
			now = a[i]+len;
			cnt++;
		}
	if( cnt >= c ) return true;
	return false;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	while( scanf("%d%d", &n, &c) != EOF ){
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &a[i]);
		sort( a, a+n );
		int l = 0, r = a[n-1]-a[0], mid, ans = 0;
		while( l <= r ){
			mid = (l+r)>>1;
			if( ok(mid) ){
				ans = mid;
				l = mid+1;
			}
			else r = mid-1;
		}
		printf("%d\n", ans);
	}
    return 0;
}