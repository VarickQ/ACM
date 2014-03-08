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
const int N = 1005;
typedef long long LL;

//http://en.wikipedia.org/wiki/Harmonic_number
int main(){
	int n;
	double ans;
	while( scanf("%d", &n) != EOF ){
		ans = 0;
		if( n <= 1000 )
			for(int i=1 ; i <= n ; ++i)
				ans += 1.0/i;
		else 
			ans = log(n+0.0)+0.577215664901532860606512090082402431042159335+1.0/2/n-1.0/12/n/n+1.0/120/n/n/n/n;
		printf("%.8lf\n", ans);
	}
	return 0;
}