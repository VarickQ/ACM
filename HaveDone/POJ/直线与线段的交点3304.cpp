#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define PI acos(-1.0)
typedef long long LL;
#define EPS 1e-10
#define zero(x) (((x)>0?(x):-(x))<eps)
const int N = 105;

int n;
struct Point {
    double x, y;
    Point() {}
    Point(double x0, double y0): x(x0), y(y0) {}
};
struct Line {
    Point p1, p2;
    Line() {}
    Line(Point p10, Point p20): p1(p10), p2(p20) {}
}l[N];
double xmult(Point p1,Point p2,Point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//判两点在线段同侧,点在线段上返回0
int same_side(Point p1,Point p2,Line l)
{
	return xmult(l.p1,p1,l.p2)*xmult(l.p1,p2,l.p2)>EPS;
}
bool check(Point a,Point b){
	if( fabs(a.x-b.x)<EPS && fabs(a.y-b.y)<EPS ) return false;
	Line ll = Line(a,b);
	for(int i=0 ; i < n ; ++i){
		if( same_side(l[i].p1,l[i].p2,ll) )
			return false;
	}
	return true;
}
int main(){
	int T;
	bool f = false;
	scanf("%d", &T);
	while( T-- ){
		f = false;
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf%lf%lf",&l[i].p1.x,&l[i].p1.y,&l[i].p2.x,&l[i].p2.y);
		if( n == 1 ) f = true;
		for(int i=0 ; i < n ; ++i){
			if( f ) break;
			int cnt = 0;
			for(int j=i+1 ; j < n ; ++j){
				if( check(l[i].p1,l[j].p1)||check(l[i].p1,l[j].p2)||check(l[j].p2,l[i].p1)||check(l[i].p2,l[j].p2) ){
					f = true;
					break;
				}
			}
		}
		if( f ) puts("Yes!");
		else puts("No!");
	}
	return 0;
}