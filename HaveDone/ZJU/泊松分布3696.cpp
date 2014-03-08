/*
The 13th Zhejiang University Programming Contest

随机分布：泊松分布
https://zh.wikipedia.org/wiki/%E6%B3%8A%E6%9D%BE%E5%88%86%E4%BD%88
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
const int inf = 1000000000;
const int M   = 100005;
const int N   = 120;
typedef long long LL;
#define E  2.71828182845904523536

double f[N];
int main(){
	int T, n;
	f[0] = 1;
	for (int i = 1; i <= 100; ++i)
		f[i] = f[i - 1] * i;
	double l;
	scanf("%d", &T);
	while (T--){
		scanf("%d%lf", &n, &l);
		double el = pow(E, -l);
		double ans = 0;
		for (int  i = 0; i <= n; ++i) {
			double tmp = el * pow(l, i) / f[i];
			ans += tmp;
			//printf("%.3lf\n", tmp);
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}