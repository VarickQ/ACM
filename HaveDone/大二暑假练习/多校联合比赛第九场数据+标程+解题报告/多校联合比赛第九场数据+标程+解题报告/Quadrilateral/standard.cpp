#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int edge[4];

int main() {
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
	
	int T, t, i;
	double p, ans;
	scanf("%d", &T);
	for(t=1; t<=T; t++) {
		for(i=0; i<4; i++) scanf("%d", &edge[i]);
		sort(edge, edge + 4);
		int ss = 0;
		for(i=0; i<3; i++) ss += edge[i];
		if(ss <= edge[3]) {
			printf("Case %d: -1\n", t);
			continue;
		}
		p = 0.0;
		for(i=0; i<4; i++) p += (double)edge[i];
		p /= 2.0;
		ans = 1.0;
		for(i=0; i<4; i++) ans *= p - (double)edge[i];
		ans = sqrt(ans);
		printf("Case %d: %.6lf\n", t, ans);
	}
	return 0;
}
	
