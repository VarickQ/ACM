/*    计算几何学   */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double INF   = 1e10;     // 无穷大
const double PI = 3.1415926535897932384626433832795;
const double EPS        = 1e-9;    // 计算精度
const int LEFT          = 0;        // 点在直线左边
const int RIGHT         = 1;        // 点在直线右边
const int ONLINE        = 2;        // 点在直线上
const int CROSS         = 0;        // 两直线相交
const int COLINE        = 1;        // 两直线共线
const int PARALLEL      = 2;        // 两直线平行
const int NOTCOPLANAR   = 3;        // 两直线不共面
const int INSIDE        = 1;        // 点在图形内部
const int OUTSIDE       = 2;        // 点在图形外部
const int BORDER        = 3;        // 点在图形边界


///////////////////////////////////////////////////////////////////

struct Point {              // 二维点或矢量
    double x, y;
    double angle, dis;
    Point() {}
    Point(double x0, double y0): x(x0), y(y0) {}
};

struct Point3D {            //三维点或矢量
    double x, y, z;
    Point3D() {}
    Point3D(double x0, double y0, double z0): x(x0), y(y0), z(z0) {}
};

struct Line {               // 二维的直线或线段
    Point p1, p2;
    Line() {}
    Line(Point p10, Point p20): p1(p10), p2(p20) {}
};

struct Line3D {             // 三维的直线或线段
    Point3D p1, p2;
    Line3D() {}
    Line3D(Point3D p10, Point3D p20): p1(p10), p2(p20) {}
};

typedef vector<Point> Polygon;      // 二维多边形	
typedef vector<Point> Points;       // 二维点集
typedef vector<Point3D> Points3D;   // 三维点集

///////////////////////////////////////////////////////////////////

inline double max(double x,double y)
{
	return x > y ? x : y;
}

inline double min(double x, double y)
{
	return x > y ? y : x;
}

inline bool ZERO(double x)              // x == 0
{
    return (fabs(x) < EPS);
}


inline bool ZERO(Point p)               // p == 0
{
    return (ZERO(p.x) && ZERO(p.y));
}

inline bool ZERO(Point3D p)              // p == 0
{
    return (ZERO(p.x) && ZERO(p.y) && ZERO(p.z));
}

inline bool EQ(double x, double y)      // eqaul, x == y
{
    return (fabs(x - y) < EPS);
}
inline bool EQ(Point &p, Point &q )
{
	return (fabs(p.x - q.x) < EPS)&&(fabs(p.y - q.y) < EPS);
}
inline bool NEQ(double x, double y)     // not equal, x != y
{
    return (fabs(x - y) >= EPS);
}

inline bool LT(double x, double y)     // less than, x < y
{
    return ( NEQ(x, y) && (x < y) );
}

inline bool GT(double x, double y)     // greater than, x > y
{
    return ( NEQ(x, y) && (x > y) );
}

inline bool LEQ(double x, double y)     // less equal, x <= y
{
    return ( EQ(x, y) || (x < y) );
}

inline bool GEQ(double x, double y)     // greater equal, x >= y
{
    return ( EQ(x, y) || (x > y) );
}

// 注意！！！   如果是一个很小的负的浮点数 
// 保留有效位数输出的时候会出现-0.000这样的形式，
// 前面多了一个负号
// 这就会导致错误！！！！！！
// 因此在输出浮点数之前，一定要调用次函数进行修正！
inline double FIX(double x)
{
    return (fabs(x) < EPS) ? 0 : x;
}

//////////////////////////////////////////////////////////////////////////////////////
/*    二维矢量运算    */

bool operator==(Point p1, Point p2) 
{
    return ( EQ(p1.x, p2.x) &&  EQ(p1.y, p2.y) );
}


bool operator!=(Point p1, Point p2) 
{
    return ( NEQ(p1.x, p2.x) ||  NEQ(p1.y, p2.y) );
}





bool operator<(Point p1, Point p2)
{
    if (NEQ(p1.x, p2.x)) 
        return (p1.x < p2.x);
    else
        return (p1.y < p2.y);
}

Point operator+(Point p1, Point p2) 
{
    return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator-(Point p1, Point p2) 
{
    return Point(p1.x - p2.x, p1.y - p2.y);
}

double operator*(Point p1, Point p2)   // 计算叉乘 p1 × p2
{
    return (p1.x * p2.y - p2.x * p1.y);
}


double operator&(Point p1, Point p2)   // 计算点积 p1·p2
{
    return (p1.x * p2.x + p1.y * p2.y);
}

double Norm(Point p)   // 计算矢量p的模
{
    return sqrt(p.x * p.x + p.y * p.y);
}

// 把矢量p旋转角度angle (弧度表示)
// angle > 0表示逆时针旋转
// angle < 0表示顺时针旋转
Point Rotate(Point p, double angle)
{
    Point result;
    result.x = p.x * cos(angle) - p.y * sin(angle);
    result.y = p.x * sin(angle) + p.y * cos(angle);
    return result;
}

//////////////////////////////////////////////////////////////////////////////////////

/*  三维矢量运算  */

bool operator==(Point3D p1, Point3D p2) 
{
    return ( EQ(p1.x, p2.x) && EQ(p1.y, p2.y) && EQ(p1.z, p2.z) );
}
bool operator<(Point3D p1, Point3D p2)
{
    if (NEQ(p1.x, p2.x)) {
        return (p1.x < p2.x);
    } else if (NEQ(p1.y, p2.y)) {
        return (p1.y < p2.y);
    } else {
        return (p1.z < p2.z);
    }
}

Point3D operator+(Point3D p1, Point3D p2) 
{
    return Point3D(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
}



Point3D operator-(Point3D p1, Point3D p2) 
{
    return Point3D(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}


Point3D operator*(Point3D p1, Point3D p2)  // 计算叉乘 p1 x p2
{
    return Point3D(p1.y * p2.z - p1.z * p2.y,
        p1.z * p2.x - p1.x * p2.z,
        p1.x * p2.y - p1.y * p2.x );        
}

// 计算点积 p1·p2
double operator&(Point3D p1, Point3D p2) {
    return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}


double Norm(Point3D p)   // 计算矢量p的模
{
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

//////////////////////////////////////////////////////////////////////////////////////

// 根据三个顶点坐标计算三角形面积
// 面积的正负按照右手旋规则确定
double Area(Point A, Point B, Point C)
{
    return ((B-A)*(C-A) / 2.0);
}   


double Area(double a, double b, double c) // 根据三条边长计算三角形面积
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// 计算多边形面积
double Area(const Polygon& poly)   // 面积的正负按照右手旋规则确定
{
    double res = 0;
    int n = poly.size();
    if (n < 3) return 0;
    for(int i = 0; i < n; i++) {
        res += poly[i].x * poly[(i+1)%n].y;
        res -= poly[i].y * poly[(i+1)%n].x;
    }
    return (res / 2.0);
}

double Distance(Point p, Line L)   // 求二维平面上点到直线的距离
{
    return ( fabs((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1) );
}

double Distance(Point3D p, Line3D L)  // 求三维空间中点到直线的距离
{
    return ( Norm((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1) );
}

bool OnLine(Point p, Line L)    // 判断二维平面上点p是否在直线L上
{
    return ZERO( (p - L.p1) * (L.p2 - L.p1) );
}

bool OnLine(Point3D p, Line3D L)  // 判断三维空间中点p是否在直线L上
{
    return ZERO( (p - L.p1) * (L.p2 - L.p1) );
}

int Relation(Point p, Line L)   // 计算点p与直线L的相对关系
{
    double res = (L.p2 - L.p1) * (p - L.p1);
    if (EQ(res, 0)) 
        return ONLINE;
    else if (res > 0)
        return LEFT;
   else 
        return RIGHT;
}

bool SameSide(Point p1, Point p2, Line L)  // 判断点p1, p2是否在直线L的同侧
{
    double m1 = (p1 - L.p1) * (L.p2 - L.p1);
    double m2 = (p2 - L.p1) * (L.p2 - L.p1);
    return GT(m1 * m2, 0);
}

bool OnLineSeg(Point p, Line L)  // 判断二维平面上点p是否在线段l上
{
    return ( ZERO( (L.p1 - p) * (L.p2 - p) ) &&
        LEQ((p.x - L.p1.x)*(p.x - L.p2.x), 0) &&
        LEQ((p.y - L.p1.y)*(p.y - L.p2.y), 0) );
}

bool OnLineSeg(Point3D p, Line3D L)  // 判断三维空间中点p是否在线段l上
{
    return ( ZERO((L.p1 - p) * (L.p2 - p)) &&
        EQ( Norm(p - L.p1) + Norm(p - L.p2), Norm(L.p2 - L.p1)) );
}

Point SymPoint(Point p, Line L)  // 求二维平面上点p关于直线L的对称点
{
    Point result;
    double a = L.p2.x - L.p1.x;
    double b = L.p2.y - L.p1.y;
    double t = ( (p.x - L.p1.x) * a + (p.y - L.p1.y) * b ) / (a*a + b*b);
    result.x = 2 * L.p1.x + 2 * a * t - p.x;
    result.y = 2 * L.p1.y + 2 * b * t - p.y;
    return result;
}

bool Coplanar(Points3D points)  // 判断一个点集中的点是否全部共面
{
    int i;
    Point3D p;
    if (points.size() < 4) return true;
    p = (points[2] - points[0]) * (points[1] - points[0]);
    for (i = 3; i < points.size(); i++) {
        if (! ZERO(p & points[i]) ) return false;
    }
    return true;
}

bool LineIntersect(Line L1, Line L2)  // 判断二维的两直线是否相交
{
    return (! ZERO((L1.p1 - L1.p2)*(L2.p1 - L2.p2)) );  // 是否平行
}

bool LineIntersect(Line3D L1, Line3D L2)  // 判断三维的两直线是否相交
{
    Point3D p1 = L1.p1 - L1.p2;
    Point3D p2 = L2.p1 - L2.p2;
    Point3D p  = p1 * p2;
    if (ZERO(p)) return false;      // 是否平行
    p = (L2.p1 - L1.p2) * (L1.p1 - L1.p2);
    return ZERO(p & L2.p2);         // 是否共面
}

bool LineSegIntersect(Line L1, Line L2) // 判断二维的两条线段是否相交
{
    return ( GEQ( max(L1.p1.x, L1.p2.x), min(L2.p1.x, L2.p2.x) ) &&
        GEQ( max(L2.p1.x, L2.p2.x), min(L1.p1.x, L1.p2.x) ) &&
        GEQ( max(L1.p1.y, L1.p2.y), min(L2.p1.y, L2.p2.y) ) &&
        GEQ( max(L2.p1.y, L2.p2.y), min(L1.p1.y, L1.p2.y) ) &&
        LEQ( ((L2.p1 - L1.p1) * (L1.p2 - L1.p1)) * ((L2.p2 -  L1.p1) * (L1.p2 - L1.p1)), 0 ) &&
        LEQ( ((L1.p1 - L2.p1) * (L2.p2 - L2.p1)) * ((L1.p2 -  L2.p1) * (L2.p2 - L2.p1)), 0 ) );             
}

// 计算两条二维直线的交点，结果在参数P中返回
// 返回值说明了两条直线的位置关系
// COLINE   -- 共线
// PARALLEL -- 平行
// CROSS    -- 相交
int CalCrossPoint(Line L1, Line L2, Point& P)
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
            return COLINE;
        else 
            return PARALLEL;
    }
	else {
        P.x = (B2 * C1 - B1 * C2) / (A2 * B1 - A1 * B2);
        P.y = (A1 * C2 - A2 * C1) / (A2 * B1 - A1 * B2);
        return CROSS;
    }
}

// 判断点p是否在凸多边形poly内
// poly的顶点数目要大于等于3
// 返回值为：
// INSIDE  -- 点在poly内
// BORDER  -- 点在poly边界上
// OUTSIDE -- 点在poly外
int InsideConvex(Point p, const Polygon& poly)
{
    Point q(0, 0);
    Line side;
    int i, n = poly.size();

    for (i = 0; i < n; i++) {
        q.x += poly[i].x;
        q.y += poly[i].y;
    }
    q.x /= n;
    q.y /= n;
    for (i = 0; i < n; i++) {
        side.p1 = poly[i];
        side.p2 = poly[(i+1)%n];
        if (OnLineSeg(p, side)) {
            return BORDER;
        } else if (!SameSide(p, q, side)) {
            return OUTSIDE;
        }
    }
    return INSIDE;
}

// 求二维两直线的夹角， 返回值是0~Pi之间的弧度
double Inclination(Line L1, Line L2)
{
    Point u = L1.p2 - L1.p1;
    Point v = L2.p2 - L2.p1;
    return acos( (u & v) / (Norm(u)*Norm(v)) );
}

// 求三维两直线的夹角， 返回值是0~Pi之间的弧度
double Inclination(Line3D L1, Line3D L2)
{
    Point3D u = L1.p2 - L1.p1;
    Point3D v = L2.p2 - L2.p1;
    return acos( (u & v) / (Norm(u)*Norm(v)) );
}

bool IsConvex(const Polygon& poly)  // 判断多边形poly是否是凸的
{
    int i, n, rel;
    Line side;

    n = poly.size();
    if (n < 3) return false;
    side.p1 = poly[0];
    side.p2 = poly[1];
    rel = Relation(poly[2], side);
    for (i = 1; i < n; i++) {
        side.p1 = poly[i];
        side.p2 = poly[(i+1)%n];
        if (Relation(poly[(i+2)%n], side) != rel) return false;
    }
    return true;
}

// 判断点p是否在简单多边形poly内, 多边形可以是凸的或凹的
// poly的顶点数目要大于等于3
// 返回值为：
// INSIDE  -- 点在poly内
// BORDER  -- 点在poly边界上
// OUTSIDE -- 点在poly外
int InsidePolygon(const Polygon& poly, Point p)
{
    int i, n, count = 0;
    Line ray, side;
    
    n = poly.size();
    ray.p1    = p;
    ray.p2.y  = p.y;
    ray.p2.x  = - INF;

    for (i = 0; i < n; i++) {                
        side.p1 = poly[i];
        side.p2 = poly[(i+1)%n];

        if( OnLineSeg(p, side) )
            return BORDER;   
        if ( EQ(side.p1.y, side.p2.y) )  // 如果side平行x轴则不作考虑
            continue;
        if (OnLineSeg(side.p1, ray)) {
            if (GT(side.p1.y, side.p2.y)) count++;
        } else if (OnLineSeg(side.p2, ray)) {
            if ( GT(side.p2.y, side.p1.y)) count++;
        } else if (LineSegIntersect(ray, side)) {
            count++;
        }
    }   
    return ((count % 2 == 1) ? INSIDE : OUTSIDE);
}

// 求多边形的重心，适用于凸的或凹的简单多边形
Point CenterOfPolygon(const Polygon& poly)  // 该算法可以一边读入多边性的顶点一边计算重心
{
    Point p, p0, p1, p2, p3;
    double m, m0;

    p1 = poly[0];
    p2 = poly[1];
    p.x = p.y = m = 0;
    for (int i = 2; i < poly.size(); i++) {
        p3 = poly[i];
        p0.x = (p1.x + p2.x + p3.x) / 3.0;
        p0.y = (p1.y + p2.y + p3.y) / 3.0;
        m0 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
        if (ZERO(m + m0)) {
            m0 += EPS;  // 为了防止除0溢出，对m0做一点点修正
        }
        p.x = (m * p.x + m0 * p0.x) / (m + m0);
        p.y = (m * p.y + m0 * p0.y) / (m + m0);
        m = m + m0;
        p2 = p3;
    }
    return p;
}

Point NearestPointToLine(Point P, Line L)   // 计算点P到直线L的最近点
{
    Point result;
    double a, b, t;

    a = L.p2.x - L.p1.x;
    b = L.p2.y - L.p1.y;
    t = ( (P.x - L.p1.x) * a + (P.y - L.p1.y) * b ) / (a * a + b * b);

    result.x = L.p1.x + a * t;
    result.y = L.p1.y + b * t;
    return result;
}

Point NearestPointToLineSeg(Point P, Line L)   // 计算点P到线段L的最近点
{
    Point result;
    double a, b, t;

    a = L.p2.x - L.p1.x;
    b = L.p2.y - L.p1.y;
    t = ( (P.x - L.p1.x) * a + (P.y - L.p1.y) * b ) / (a * a + b * b);

    if ( GEQ(t, 0) && LEQ(t, 1) ) {
        result.x = L.p1.x + a * t;
        result.y = L.p1.y + b * t;
    } else {
        if ( Norm(P - L.p1) < Norm(P - L.p2) ) {
            result = L.p1;
        } else {
            result = L.p2;
        }
    }
    return result;
}

double MinDistance(Line L1, Line L2) // 计算线段L1到线段L2的最短距离
{
    double d1, d2, d3, d4;
    if (LineSegIntersect(L1, L2)) 
		return 0;

    d1 = Norm( NearestPointToLineSeg(L1.p1, L2) - L1.p1 );
    d2 = Norm( NearestPointToLineSeg(L1.p2, L2) - L1.p2 );
    d3 = Norm( NearestPointToLineSeg(L2.p1, L1) - L2.p1 );
    d4 = Norm( NearestPointToLineSeg(L2.p2, L1) - L2.p2 );
    return min( min(d1, d2), min(d3, d4) );
}
// 判断线段是否在多边形内  // 多边形可以是任意简单多边形
bool InsidePolygon(const Polygon& poly, Line L)
{   
    bool result;
    int n, i;
    Points points;
    Point p;
    Line side;

    result = ( (InsidePolygon(poly, L.p1) != OUTSIDE) && (InsidePolygon(poly, L.p2) != OUTSIDE) );

    if (!result) return false;

    n = poly.size();    
    for (i = 0; i < n; i++) {
        side.p1 = poly[i];
        side.p2 = poly[(i+1)%n];

        if ( OnLineSeg(L.p1, side) ) {
            points.push_back(L.p1);
        } else if ( OnLineSeg(L.p2, side) ) {
            points.push_back(L.p2);
        } else if ( OnLineSeg(side.p1, L) ) {
            points.push_back(side.p1);
        } else if ( OnLineSeg(side.p2, L) ) {
            points.push_back(side.p2);
        } else if( LineSegIntersect(side, L) ) {
            return false;
        }
    }

    // 对交点进行排序
    sort(points.begin(), points.end());

    for (i = 1; i < points.size(); i++) {
        if (points[i-1] != points[i]) {
            p.x = (points[i-1].x + points[i].x) / 2.0;
            p.y = (points[i-1].y + points[i].y) / 2.0;
            if ( InsidePolygon(poly, p) == OUTSIDE ) {
                return false;
            }
        }
    }
    return true;  
}

// 寻找凸包 graham 扫描法 // 生成的多边形顶点按逆时针方向排列
bool GrahamComp(const Point& left, const Point& right)
{
    if (EQ(left.angle, right.angle)) {
        return (left.dis < right.dis);
    } else {
        return (left.angle < right.angle);
    }
}

void GrahamScan(Points& points, Polygon& result)
{
    int i, k, n;
    Point p;

    n = points.size();
    result.clear();

    if (n < 3) return;

    // 选取points中y坐标最小的点points[k]，
    // 如果这样的点有多个，则取最左边的一个
    k = 0;
    for (i = 1; i < n; i++ ) {
        if (EQ(points[i].y, points[k].y)) {
            if (points[i].x <= points[k].x) k = i;
        } else if (points[i].y < points[k].y) {
            k = i;
        }       
    }
    swap(points[0], points[k]);

    // 现在points中y坐标最小的点在points[0]
    // 计算每个点相对于points[0]的极角和距离
    for (i = 1; i < n; i++) {
        points[i].angle = atan2(points[i].y - points[0].y, points[i].x - points[0].x);
        points[i].dis   = Norm(points[i] - points[0]);
    }

    // 对顶点按照相对points[0]的极角从小到大进行排序
    // 对于极角相同的按照距points[0]的距离从小到大排序
    sort(points.begin() + 1, points.end(), GrahamComp);

    // 下面计算凸包
    result.push_back(points[0]);
    for (i = 1; i < n; i++) {
        // 如果有极角相同的点，只取相对于points[0]最远的一个
        if ((i + 1 < n) && EQ(points[i].angle, points[i+1].angle)) continue;
        if (result.size() >= 3) {
            p = result[result.size() - 2];
            while ( GEQ((points[i] - p)*(result.back() - p), 0) )
            {
                result.pop_back();
                p = result[result.size() - 2];
            }
        }
        result.push_back( points[i] );      
    }
}


// 用有向直线line切割凸多边形，
// result[LEFT]和result[RIGHT]分别保存被切割后line的左边和右边部分
// result[ONLINE]没有用到，只是用来作为辅助空间
// 返回值是切割多边形的切口的长度，
// 如果返回值是0 则说明未作切割。
// 当未作切割时，如果多边形在该直线的右侧，则result[RIGHT]等于该多边形，否则result[LEFT]等于该多边形
// 注意：被切割的多边形一定要是凸多边形，顶点按照逆时针排列
// 可利用这个函数来求多边形的核，初始的核设为一个很大的矩形，然后依次用多边形的每条边去割
double CutConvex(const Polygon& poly, const Line& line, Polygon result[3])
{
    vector<Point> points;
    Line side;
    Point p;
    int i,n, cur, pre;
    
    result[LEFT].clear();
    result[RIGHT].clear();
    result[ONLINE].clear();
    n = poly.size();
    if (n == 0) return 0;
    pre = cur = Relation(poly[0], line);    

    for (i = 0; i < n; i++) {
        cur = Relation(poly[(i+1)%n], line);
        if (cur == pre) {
            result[cur].push_back(poly[(i+1)%n]);
        } else {
            side.p1 = poly[i];
            side.p2 = poly[(i+1)%n];
            CalCrossPoint(side, line, p);           
            points.push_back(p);
            result[pre].push_back(p);
            result[cur].push_back(p);
            result[cur].push_back(poly[(i+1)%n]);
            pre = cur;
        }
    }

    sort(points.begin(), points.end());

    if (points.size() < 2) {
        return 0;
    } else {        
        return Norm(points.front() - points.back());
    }
}


//求解最近点对
inline double Distance(Point a,Point b)
{
	return ((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) );
}

// xset为按X排序, yset为按y排序, z为辅助数组, start 在调用时为0, end 在调用时为n-1
double closepoints(Point xset[],Point yset[],Point zset[],int start,int end)
{
	if(start==end)
		return INF;
	double tmin,temp;
	int i,j,f,l,mid=(start+end)>>1;
	f=start;	l=mid+1;
	for(i=start;i<=end;i++)
	{
		if(yset[i].x<xset[mid].x ||	yset[i].x==xset[mid].x && yset[i].y<=xset[mid].y)
			zset[f++]=yset[i];
		else
			zset[l++]=yset[i];
	}
	tmin=closepoints( xset,zset,yset,start,mid);
	temp=closepoints( xset,zset,yset, mid+1,end);
	tmin=tmin<temp?tmin:temp;
	result=result<tmin?result:tmin;
	i=l=start; j=mid+1;

	while(i<=mid && j<=end)
	{
		if(zset[i].y<zset[j].y)
			yset[l++]=zset[i++];
		else
			yset[l++]=zset[j++];
	}
	while(i<=mid)
		yset[l++]=zset[i++];
	while(j<=end)
		yset[l++]=zset[j++];
	l=start;
	for(i=start;i<=end; i++)
	{
		if( (yset[i].x-xset[mid].x)*(yset[i].x-xset[mid].x)<result)
			zset[l++]=yset[i];
	}
	for(i=start;i<l;i++)
	{
		for(j=i+1;j<l&&(zset[i].y-zset[j].y)*(zset[i].y-zset[j].y)<result ;j++)
		{
			temp=Distance(zset[i],zset[j]);
			if(temp<result)
				result=temp;
		}
	}
	return result;
}




/*  以下的函数尚未验证  */

// 表示矩形，左下角坐标是(xl, yl)，右上角坐标是(xh, yh)
struct Rect_2 {
    double xl, yl, xh, yh;
};

// 判断两个矩形是否相交   // 如果相邻不算相交
bool Intersect(Rect_2 r1, Rect_2 r2)
{
    return ( max(r1.xl, r2.xl) < min(r1.xh, r2.xh) &&
             max(r1.yl, r2.yl) < min(r1.yh, r2.yh) );
}

// 用长宽表示矩形的方法   // w, h分别表示宽度和高度
struct Rect {
    double w, h;
};

// 判断矩形r2是否可以放置在矩形r1内    // r2可以任意地旋转
bool IsContain(Rect r1, Rect r2)
{
    double t1, t2;

    if ( min(r2.w, r2.h) <= min(r1.w, r1.h) &&
         max(r2.w, r2.h) <= max(r1.w, r1.h) )
    {
        return true;
    }
    t1 = asin( r1.w / sqrt(r2.w * r2.w + r2.h * r2.h) ) - asin(r2.w / r2.h);
    if (t1 <= 0 || 2.0*t1 >= PI) return false;
    if ( LEQ(r2.w * sin(t1) + r2.h * cos(t1), r1.h) ) {
        return true;
    }
    t2 = asin( r1.h / sqrt(r2.w * r2.w + r2.h * r2.h) ) - asin(r2.h / r2.w);
    if (t2 <= 0 || 2.0*t2 >= PI) return false;
    if ( LEQ(r2.w * cos(t2) + r2.h * sin(t2), r1.w) ) {
        return true;
    }
    return false;
}