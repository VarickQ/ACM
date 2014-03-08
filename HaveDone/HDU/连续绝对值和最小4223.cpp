#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-8;
const int inf = 1000000000;
const int M = 6050000;
const int N = 1005;

int n,a[N];
int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
    int T, cs = 0;
    scanf("%d", &T);
    while (T--) {
		scanf("%d", &n);
		a[0] = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &a[i]);
			a[i] += a[i-1];
		}
		int ans = inf;
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= i ; ++j)
				ans = min( ans, abs(a[i] - a[j-1]) );
		printf("Case %d: %d\n", ++cs, ans);
    }
    return 0;
}