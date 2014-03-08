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
const double EPS = 1e-8;
const int N = 305;

struct point{double x,y;}s,t;
struct line{point p1,p2;}l;
point Sympoint(point p, line L)  // 求二维平面上点p关于直线L的对称点
{
    point result;
    double a = L.p2.x - L.p1.x;
    double b = L.p2.y - L.p1.y;
    double t = ( (p.x - L.p1.x) * a + (p.y - L.p1.y) * b ) / (a*a + b*b);
    result.x = 2 * L.p1.x + 2 * a * t - p.x;
    result.y = 2 * L.p1.y + 2 * b * t - p.y;
    return result;
}
inline bool EQ(double x, double y)      // eqaul, x == y
{
    return (fabs(x - y) < EPS);
}
// 计算两条二维直线的交点，结果在参数P中返回
// 返回值说明了两条直线的位置关系
// COLINE   -- 共线
// PARALLEL -- 平行
// CROSS    -- 相交
int CalCrossPoint(line L1, line L2, point& P)
{
    double A1, B1, C1, A2, B2, C2;

    A1 = L1.p2.y - L1.p1.y;
    B1 = L1.p1.x - L1.p2.x;
    C1 = L1.p2.x * L1.p1.y - L1.p1.x * L1.p2.y;

    A2 = L2.p2.y - L2.p1.y;
    B2 = L2.p1.x - L2.p2.x;
    C2 = L2.p2.x * L2.p1.y - L2.p1.x * L2.p2.y;

    if (EQ(A1 * B2, B1 * A2)) 
	{
        if (EQ( (A1 + B1) * C2, (A2 + B2) * C1 )) 
            return 0;
        else 
            return 0;
    }
	else {
        P.x = (B2 * C1 - B1 * C2) / (A2 * B1 - A1 * B2);
        P.y = (A1 * C2 - A2 * C1) / (A2 * B1 - A1 * B2);
        return 1;
    }
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&l.p1.x,&l.p1.y,&l.p2.x,&l.p2.y,&s.x,&s.y,&t.x,&t.y);
		point tmp = Sympoint(s,l);
		line l2;
		l2.p1 = tmp;
		l2.p2 = t;
		point ans;
		CalCrossPoint(l,l2,ans);
		printf("%.3lf %.3lf\n", ans.x, ans.y);
	}
	return 0;
}