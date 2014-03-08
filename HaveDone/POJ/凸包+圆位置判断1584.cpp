/*题意：已知一个多边形的n个顶点坐标，然后再给一个钉子，给定钉子的半径和圆心坐标，首先判断多边形是否为凸多边形，若为凸多边形，再判断钉子是否可以放到凸多边形内部。
 
思路：很好的计算几何。
1.由于顶点给出的顺序可能为逆时针或顺时针，所以在判断是否为凸边变形，利用叉积的性质，每个点依次扫描看是否都顺着同一的方向转动。
2.判断圆(钉子)是否在多边形内部，第一步判断圆心是否在凸多边形内部（以圆心为定点扫描一周），第二步再判断圆心到某一边的最短距离，若存在某最短距离大于圆心，则圆不能放在凸多边内。*/
/*
4 0.1 2 1
0 0
2 2
3 0
2 0
4 0.1 10 10
0 0
2 2
3 0
2 0
5 1.5 1.5 2.0
1.0 1.0
2.0 2.0
1.75 2.0
1.0 3.0
0.0 2.0
5 1.5 1.5 2.0
1.0 1.0
2.0 2.0
1.75 2.5
1.0 3.0
0.0 2.0
1
*/
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
const double eps = 1e-10;
const int N = 205;

class Point
{
public:
    double x, y, r;
    int id;

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
}p[N],ch[N];
//********************凸包模板
// cross product of p0p1 x p0p2
double xmult(const Point &p0, const Point &p1, const Point &p2){
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
int Andrew_monotone_chain(Point *P, Point *CH, int n){
    // 將所有點依照座標大小排序
    sort(P, P+n, less<Point>());
    int m = 0;  // m 為凸包頂點數目
    // 包下半部
    for (int i=0; i<n; ++i){//三点贡献也算在凸包里面
        while (m >= 2 && xmult(CH[m-2], CH[m-1], P[i]) < 0) m--;
        CH[m++] = P[i];
    }
    // 包上半部，不用再包入方才包過的終點，但會再包一次起點
    for (int i=n-2, t=m+1; i>=0; --i){
        while (m >= t && xmult(CH[m-2], CH[m-1], P[i]) < 0) m--;
        CH[m++] = P[i];
    }
    m--;    // 最後一個點是重複出現兩次的起點，故要減一。
    return m;
}
double dis(Point p1,Point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double disptoseg(Point p,Point l1,Point l2){
	Point t=p;
	t.x+=l1.y-l2.y,t.y+=l2.x-l1.x;
	if (xmult(l1,t,p)*xmult(l2,t,p)>eps)
		return dis(p,l1)<dis(p,l2)?dis(p,l1):dis(p,l2);
	return fabs(xmult(p,l1,l2))/dis(l1,l2);
}
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
int inside_convex_v2(Point q,int n,Point* p){
	int i,s[3]={1,1,1};
	for (i=0;i<n&&s[0]&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
	return s[0]&&s[1]|s[2];
}
int main(){
	int n;
	double r;
	Point a;
	while( scanf("%d", &n) && n>2 ){
		scanf("%lf%lf%lf",&r,&a.x,&a.y);
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		int g = Andrew_monotone_chain(p,ch,n);
		//printf("%d %d", n, g);
		if( n != g )
			puts("HOLE IS ILL-FORMED");
		else {
			if( inside_convex_v2(a,g,ch) ){
				double res = 999999999.0;
				for(int i=0 ; i < g ; ++i){
					double tmp = disptoseg(a,ch[i],ch[(i+1)%g]);
					if(tmp < res) res = tmp;
				}
				if( res < r ) puts("PEG WILL NOT FIT");
				else puts("PEG WILL FIT");
			}
			else puts("PEG WILL NOT FIT");
		}
	}
	return 0;
}