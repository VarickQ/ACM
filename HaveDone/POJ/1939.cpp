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
typedef long long ll;
const int M = 10100;
const int N = 10000;

struct point{
	ll x,y;
}a[N];
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		printf("%d ",n);
		scanf("%lld%lld",&a[0].x,&a[0].y);
		for(int i=1 ; i < n ; ++i){
			scanf("%lld%lld",&a[i].x,&a[i].y);
			printf("%lf %lf ",(a[i-1].x+a[i].x)/2.0,(a[i-1].y+a[i].y)/2.0);
		}
		printf("%lf %lf\n",(a[0].x+a[n-1].x)/2.0,(a[0].y+a[n-1].y)/2.0);
	}
	return 0;
}