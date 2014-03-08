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

int main(){
	int n, m, ans, f[12];
	f[0] = 1;
	for(int i=1 ; i <= 10 ; ++i)
		f[i] = f[i-1]*8;
	while( scanf("%d", &n) && n ){
		ans = 0;
		int i = 0;
		m = n;
		while( m ){
			int tmp = m%10;
			if( tmp > 3 && tmp < 8 ) tmp--;
			else if( tmp > 8 ) tmp -= 2;
			ans += tmp*f[i];
			m /= 10;
			i++;
		}
		printf("%d: %d\n", n, ans);
	}
	return 0;
}