//B Èý·Ö·¨
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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-10;//1e-8 WA
const int inf = 1000000000;
const int M   = 100000;
const int N   = 105;
typedef long long ll;

double H,h,D;
double getLen( double x ){
	return (x*H+h*D-H*D)/x+(D-x);
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%lf%lf%lf", &H, &h, &D);
		double l = D*(H-h)/H,r = D;
		while( fabs(r-l) >= eps ){
			double mid = (l+r)/2;
			double mmid = (mid+r)/2;
			if( getLen(mid) > getLen(mmid) )
				r = mmid;
			else l = mid;
		}
		printf("%.3lf\n", getLen(l));
	}
	return 0;
}