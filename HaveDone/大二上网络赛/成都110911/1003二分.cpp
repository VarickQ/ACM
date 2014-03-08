#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define eps 1e-8
#define PI 3.1415926535897932384626433832795
const double inf = 1000000000.0;
const int N = 110;

int n;
double a[N];
double GetS(double x){
	return n*x*x/(4.0*tan(PI/double(n)));
}
double Gets(double x){
	double p,s = 0;
	for(int i=1 ; i < n ; ++i){
		p = 0.5*(a[i-1]+a[i]+x);
		s += sqrt(p*(p-a[i-1])*(p-a[i])*(p-x));
	}
	p = 0.5*(a[n-1]+a[0]+x);
	s += sqrt(p*(p-a[n-1])*(p-a[0])*(p-x));
	return s;
}
int main()
{
	int T,i,cs=0;
	double l,r,mid,up,down;
	scanf("%d",&T);
	while(T--)
	{
		r = inf;
		l = 0;
		scanf("%d",&n);
		scanf("%lf",&a[0]);
		for(i=1 ; i < n ; ++i){
			scanf("%lf",&a[i]);
			if(a[i]+a[i-1] < r)
				r = a[i]+a[i-1];
			if(fabs(a[i]-a[i-1]) > l)
				l = fabs(a[i]-a[i-1]);
		}
		if(a[n-1]+a[0] < r)
			r = a[n-1]+a[0];
		if(fabs(a[n-1]-a[0]) > l)
			l = fabs(a[n-1]-a[0]);
		up = r;
		down = l;
		printf("Case %d: ",++cs);
		if(r-l < eps){
			printf("impossible\n");
			continue;
		}
		while(r-l > eps){
			mid = (l+r)/2;
			if(GetS(mid) < Gets(mid))
				l = mid;
			else r = mid;
		}
		if(fabs(mid-down)<eps || fabs(mid-up)<eps)
			printf("impossible\n");
		else printf("%.3lf\n",mid);
	}
    return 0;
}