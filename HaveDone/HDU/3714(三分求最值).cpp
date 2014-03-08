#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-10
const int inf = 1000000000;
const int N = 10010;
const int M = 10010;

int a[N],b[N],c[N],n;
double gao(double x){
	double ans = -200000000000000.0;
	for(int i=0 ; i < n ; ++i){
		double tmp = a[i]*x*x+b[i]*x+c[i];
		if( tmp > ans ) ans = tmp;
	}
	return ans;
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		double l=0,r=1000.0;
		while( fabs(r-l) > eps ){
			double mid = (l+r)/2.0;
			double mmid = (mid+r)/2.0;
			if( gao(mid) < gao(mmid) )
				r = mmid;
			else l = mid;
		}
		printf("%.4lf\n", gao(l));
	}
	return 0;
}