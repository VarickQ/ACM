#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 ll;
const int inf = 2000000000;
const int M = 100000;
const int N = 105;

struct Point{
	double x,y;
}a[N];
inline double pt_distance(Point a, Point b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double fermat_point(Point pt[], int n, Point& ptres){
	Point u, v;
	double step = 0.0, curlen, explen, minlen;
	int i, j, k, idx;
	bool flag;
	u.x = u.y = v.x = v.y = 0.0;
	for(i = 0; i < n; ++i){
		step += fabs(pt[i].x) + fabs(pt[i].y);
		u.x += pt[i].x;
		u.y += pt[i].y;
	}
	u.x /= n;
	u.y /= n;
	flag = 0;
	while(step > 1e-10){
		for(k = 0; k < 10; step /= 2, ++k)
			for(i = -1; i <= 1; ++i)
				for(j = -1; j <= 1; ++j){
					v.x = u.x + step*i;
					v.y = u.y + step*j;
					curlen = explen = 0.0;
					for(idx = 0; idx < n; ++idx){
						curlen += pt_distance(u, pt[idx]);
						explen += pt_distance(v, pt[idx]);
					}
					if(curlen > explen){
						u = v;
						minlen = explen;
						flag = 1;
					}
				}
	}
	ptres = u;
	return flag ? minlen : curlen;
}

int main(){
	int n;
	Point ptrs;
	double ans;
	while(scanf("%d",&n) == 1){
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		ans = fermat_point(a,n,ptrs);
		printf("%d\n",int(ans+0.5));
	}
	return 0;
}