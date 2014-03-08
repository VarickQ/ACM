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
const int inf = 1000000000;
const int N   = 55;
const double eps = 1e-8;

struct point{
	int id;
	double x,y;
}a[N],temp;
bool cmp( const point a, const point b ){
	if( a.y == b.y ) return a.x < b.x;
	return a.y < b.y;
}
double xmult( point p1, point p2, point p0 ){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double dis( point a, point b ){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmpAngle( point a, point b ){
	double x = xmult( a, b, temp );
	if( fabs(x) < eps )
		return dis(a,temp) < dis(b,temp);
	return x > 0;
}
int ans[N];
int main(){
	int T,n;
	scanf("%d", &T);
	while( T-- ){
		memset( ans, 0, sizeof( ans ) );
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%d%lf%lf", &a[i].id, &a[i].x, &a[i].y);
		sort( a, a+n, cmp );
		ans[0] = a[0].id;
		for(int i=1 ; i < n ; ++i){
			temp = a[i-1];
			sort( a+i, a+n, cmpAngle );
			ans[i] = a[i].id;
		}
		printf("%d", n);
		for(int i=0 ; i < n ; ++i)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}