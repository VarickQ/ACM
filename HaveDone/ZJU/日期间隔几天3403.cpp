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
const double eps = 1e-8;
const int inf = 50000000;
const int M   = 10005;
const int N   = 505;
typedef long long LL;

LL s[15], f[15], d[15];
LL solve(LL y,LL b,LL c){
	LL ret = f[b-1] + c;
	if( y > 0 ){
		ret += (y - 1) / 12 * s[12];
		ret += s[(y-1)%12+1];
	}
	ret += y / 11 + (y % 11 != 0);
	if( y%11 == 0 && b > 1 ) ret++;
	return ret;
}
int main(){
	for(int i=1 ; i <= 12 ; ++i){
		d[i] = i * i * i;
		f[i] = f[i-1] + d[i];
		s[i] = s[i-1] + f[i];
	}
	LL m1, d1, y1, m2, d2, y2;
	while( scanf("%lld-%lld-%lld", &m1, &d1, &y1) != EOF ){
		scanf("%lld-%lld-%lld", &m2, &d2, &y2);
		LL a = solve( y1, m1, d1 );
		LL b = solve( y2, m2, d2 );
		if( a > b ) printf("%lld\n", a - b + 1);
		else printf("%lld\n", b - a + 1);
	}
	return 0;
}