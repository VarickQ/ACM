#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <complex>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long LL;
const int inf = 1000000000;
const int maxn = 555;
double a[maxn];
int main () {
	int t;
	scanf ("%d", &t);
	while (t --) {
		int n;
		scanf ("%d", &n);
		for (int i = 0; i < n; ++ i) scanf ("%lf", &a[i]);
		sort (a, a + n);
		if (n % 2 == 0) printf ("%.3lf\n", (a[n/2] + a[n/2-1]) / 2);
		else printf ("%.3lf\n", a[n/2]);
	}
	return 0;
}