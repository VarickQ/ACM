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
const int inf = 1000000000;
const int N   = 5005;
const double eps = 1e-8;

struct point{
	double x,y;
}ul,lr,toy;
struct line{
	point a,b;
}l[N];
int n,m,num[N];
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int same_side(point p1,point p2,line l){
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
int main(){
	while( scanf("%d", &n) && n ){
		memset( num, 0, sizeof( num ) );
		scanf("%d%lf%lf%lf%lf",&m,&ul.x,&ul.y,&lr.x,&lr.y);
		for(int i=1 ; i <= n ; ++i){
			double x1,x2;
			scanf("%lf%lf", &x1, &x2);
			l[i].a.x = x1; l[i].a.y = ul.y;
			l[i].b.x = x2; l[i].b.y = lr.y;
		}
		for(int i=0 ; i < m ; ++i){
			scanf("%lf%lf", &toy.x, &toy.y);
			for(int j=1 ; j <= n ; ++j){
				if( same_side(toy,ul,l[j]) ){
					num[j-1]++; break;
				} else {
					if( j == n ) num[n]++;
				}
			}
		}
		for(int i=0 ; i <= n ; ++i)
			printf("%d: %d\n", i, num[i]);
		printf("\n");
	}
	return 0;
}