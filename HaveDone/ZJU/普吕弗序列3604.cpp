#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 1100;
const int N   = 200100;
typedef long long LL;

//http://zh.wikipedia.org/wiki/%E6%99%AE%E5%90%95%E5%BC%97%E5%BA%8F%E5%88%97
int main(){
	int T, n, s;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &s);
		if (s >= n) {
			puts("1"); continue;
		}
		LL ans = s;
		for (int i = 0; i < n-1-s; ++i)
			ans = (ans * n) % 1000000007;
		printf("%lld\n", ans);
	}
	return 0;
}