#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 1000000000;
const int M = 100000;
const int N = 1005;

double a[N];
int main(){
	int T,n,cs=0;
	double sum;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		sum = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%lf",&a[i]);
			sum += a[i];
		}
		printf("Case %d: %.6lf\n",++cs,a[0]/sum);
	}
	return 0;
}