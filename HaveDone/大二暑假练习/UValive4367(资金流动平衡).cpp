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
const int N   = 1001;
const int M   = 1100000;
const int inf = 2000000000;
typedef long long LL;

int a,b[N];
int main(){
	int n, cs = 1;
	while( scanf("%d", &n) && n ){
		memset( b, 0, sizeof( b ) );
		int sum = 0;
		for(int i=0 ; i < n ; ++i)
			for(int j=0 ; j < n ; ++j){
				scanf("%d", &a);
				sum += a;
				b[i] += a;
				b[j] -= a;
			}
		printf("%d. %d ", cs++, sum);
		int ans = 0;
		for(int i=0 ; i < n ; ++i)
			if( b[i] > 0 ) ans += b[i];
		printf("%d\n", ans);
	}
	return 0;
}