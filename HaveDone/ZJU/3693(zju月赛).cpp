/*
保留小数点后2位。
trick:小数点后第三位有值要向上取整，小数点后第四位的全部舍去
*/
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
const LL MOD = 1000000007;
const int N = 105;

int main(){
	int n, k;
	double w;
	while( scanf("%d%lf%d", &n, &w, &k) != EOF ){
		int t = n+2-(n+2)/k;
		int m = (int)floor(w * 1000 + 0.5);
		if( m%10 ) m = m/10+1;
		else m = m/10;
		int ans = (t * m + 1) / 2;
		printf("%d.%02d\n", ans/100, ans%100);
	}
	return 0;
}