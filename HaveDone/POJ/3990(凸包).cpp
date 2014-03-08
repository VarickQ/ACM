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
typedef long long LL;

struct Point{
    double x, y;
    Point() {}
    Point(double x, double y) {
        this->x = x; this->y = y;
    }
    Point operator - (const Point &a) const {
        return Point(x-a.x, y-a.y);
    }
    friend bool operator < (const Point& a, const Point& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
}a[5],b[5];
//********************͹��ģ��
// cross product of p0p1 x p0p2
double xmult(const Point &p0, const Point &p1, const Point &p2){
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
int convex_hull(Point *P, Point *CH, int n){
    // �������c�������˴�С����
    sort( P, P+n );
    int m = 0;  // m ��͹����c��Ŀ
    // ���°벿
    for (int i=0; i<n; ++i){
        while (m >= 2 && xmult(CH[m-2], CH[m-1], P[i]) <= 0) m--;
        CH[m++] = P[i];
    }
    // ���ϰ벿�������ٰ��뷽�Ű��^�ĽK�c�������ٰ�һ�����c
    for (int i=n-2, t=m+1; i>=0; --i){
        while (m >= t && xmult(CH[m-2], CH[m-1], P[i]) <= 0) m--;
        CH[m++] = P[i];
    }
    m--;    // ����һ���c�����}���F�ɴε����c����Ҫ�pһ��
    return m;
}
double getDis( Point a, Point b ){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main() {
	while( scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a[0].x,&a[0].y,&a[1].x,&a[1].y,&a[2].x,&a[2].y,&a[3].x,&a[3].y) == 8 ){
		if(a[0].x==-1&&a[0].y==-1&&a[1].x==-1&&a[1].y==-1&&a[2].x==-1&&a[2].y==-1&&a[3].x==-1&&a[3].y==-1)
			break;
		int g = convex_hull( a, b, 4 );
		double dis, ans = 1e200;
		if( g == 4 ) ans = getDis(b[0],b[2])+getDis(b[1],b[3]);
		else {
			for(int i=0 ; i < 4 ; ++i){
				dis = 0.0;
				for(int j=0 ; j < 4 ; ++j)
					dis += getDis( a[i], a[j] );
				if( dis < ans ) ans = dis;
			}
		}
		printf("%.4lf\n", ans);
	}
	return 0;
}