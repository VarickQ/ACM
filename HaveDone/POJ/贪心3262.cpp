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
typedef long long LL;
const int inf = 100000000;
const int N = 100010;

struct Node{
	int D,T;
}a[N],sum[N];
bool cmp(const Node &a,const Node &b){
	return a.D*b.T > a.T*b.D;
}
int main(){
	int n;
	while( scanf("%d", &n) != EOF ){
		memset( sum, 0, sizeof( sum ) );
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d", &a[i].D, &a[i].T);
		sort( a, a+n, cmp );
		sum[0] = a[0];
		for(int i=1 ; i < n ; ++i){
			sum[i].D = sum[i-1].D+a[i].D;
			sum[i].T = sum[i-1].T+a[i].T;
		}
		LL ans = 0;
		for(int i=0 ; i < n ; ++i)
			ans += (sum[n-1].D-sum[i].D)*a[i].T*2;
		printf("%lld\n", ans);
	}
	return 0;
}