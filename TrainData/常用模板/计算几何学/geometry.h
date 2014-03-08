/*    ���㼸��ѧ   */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double INF   = 1e10;     // �����
const double PI = 3.1415926535897932384626433832795;
const double EPS        = 1e-9;    // ���㾫��
const int LEFT          = 0;        // ����ֱ�����
const int RIGHT         = 1;        // ����ֱ���ұ�
const int ONLINE        = 2;        // ����ֱ����
const int CROSS         = 0;        // ��ֱ���ཻ
const int COLINE        = 1;        // ��ֱ�߹���
const int PARALLEL      = 2;        // ��ֱ��ƽ��
const int NOTCOPLANAR   = 3;        // ��ֱ�߲�����
const int INSIDE        = 1;        // ����ͼ���ڲ�
const int OUTSIDE       = 2;        // ����ͼ���ⲿ
const int BORDER        = 3;        // ����ͼ�α߽�


///////////////////////////////////////////////////////////////////

struct Point {              // ��ά���ʸ��
    double x, y;
    double angle, dis;
    Point() {}
    Point(double x0, double y0): x(x0), y(y0) {}
};

struct Point3D {            //��ά���ʸ��
    double x, y, z;
    Point3D() {}
    Point3D(double x0, double y0, double z0): x(x0), y(y0), z(z0) {}
};

struct Line {               // ��ά��ֱ�߻��߶�
    Point p1, p2;
    Line() {}
    Line(Point p10, Point p20): p1(p10), p2(p20) {}
};

struct Line3D {             // ��ά��ֱ�߻��߶�
    Point3D p1, p2;
    Line3D() {}
    Line3D(Point3D p10, Point3D p20): p1(p10), p2(p20) {}
};

typedef vector<Point> Polygon;      // ��ά�����	
typedef vector<Point> Points;       // ��ά�㼯
typedef vector<Point3D> Points3D;   // ��ά�㼯

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

// ע�⣡����   �����һ����С�ĸ��ĸ����� 
// ������Чλ�������ʱ������-0.000��������ʽ��
// ǰ�����һ������
// ��ͻᵼ�´��󣡣���������
// ��������������֮ǰ��һ��Ҫ���ôκ�������������
inline double FIX(double x)
{
    return (fabs(x) < EPS) ? 0 : x;
}

//////////////////////////////////////////////////////////////////////////////////////
/*    ��άʸ������    */

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

double operator*(Point p1, Point p2)   // ������ p1 �� p2
{
    return (p1.x * p2.y - p2.x * p1.y);
}


double operator&(Point p1, Point p2)   // ������ p1��p2
{
    return (p1.x * p2.x + p1.y * p2.y);
}

double Norm(Point p)   // ����ʸ��p��ģ
{
    return sqrt(p.x * p.x + p.y * p.y);
}

// ��ʸ��p��ת�Ƕ�angle (���ȱ�ʾ)
// angle > 0��ʾ��ʱ����ת
// angle < 0��ʾ˳ʱ����ת
Point Rotate(Point p, double angle)
{
    Point result;
    result.x = p.x * cos(angle) - p.y * sin(angle);
    result.y = p.x * sin(angle) + p.y * cos(angle);
    return result;
}

//////////////////////////////////////////////////////////////////////////////////////

/*  ��άʸ������  */

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


Point3D operator*(Point3D p1, Point3D p2)  // ������ p1 x p2
{
    return Point3D(p1.y * p2.z - p1.z * p2.y,
        p1.z * p2.x - p1.x * p2.z,
        p1.x * p2.y - p1.y * p2.x );        
}

// ������ p1��p2
double operator&(Point3D p1, Point3D p2) {
    return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}


double Norm(Point3D p)   // ����ʸ��p��ģ
{
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

//////////////////////////////////////////////////////////////////////////////////////

// ����������������������������
// �����������������������ȷ��
double Area(Point A, Point B, Point C)
{
    return ((B-A)*(C-A) / 2.0);
}   


double Area(double a, double b, double c) // ���������߳��������������
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// �����������
double Area(const Polygon& poly)   // �����������������������ȷ��
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

double Distance(Point p, Line L)   // ���άƽ���ϵ㵽ֱ�ߵľ���
{
    return ( fabs((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1) );
}

double Distance(Point3D p, Line3D L)  // ����ά�ռ��е㵽ֱ�ߵľ���
{
    return ( Norm((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1) );
}

bool OnLine(Point p, Line L)    // �ж϶�άƽ���ϵ�p�Ƿ���ֱ��L��
{
    return ZERO( (p - L.p1) * (L.p2 - L.p1) );
}

bool OnLine(Point3D p, Line3D L)  // �ж���ά�ռ��е�p�Ƿ���ֱ��L��
{
    return ZERO( (p - L.p1) * (L.p2 - L.p1) );
}

int Relation(Point p, Line L)   // �����p��ֱ��L����Թ�ϵ
{
    double res = (L.p2 - L.p1) * (p - L.p1);
    if (EQ(res, 0)) 
        return ONLINE;
    else if (res > 0)
        return LEFT;
   else 
        return RIGHT;
}

bool SameSide(Point p1, Point p2, Line L)  // �жϵ�p1, p2�Ƿ���ֱ��L��ͬ��
{
    double m1 = (p1 - L.p1) * (L.p2 - L.p1);
    double m2 = (p2 - L.p1) * (L.p2 - L.p1);
    return GT(m1 * m2, 0);
}

bool OnLineSeg(Point p, Line L)  // �ж϶�άƽ���ϵ�p�Ƿ����߶�l��
{
    return ( ZERO( (L.p1 - p) * (L.p2 - p) ) &&
        LEQ((p.x - L.p1.x)*(p.x - L.p2.x), 0) &&
        LEQ((p.y - L.p1.y)*(p.y - L.p2.y), 0) );
}

bool OnLineSeg(Point3D p, Line3D L)  // �ж���ά�ռ��е�p�Ƿ����߶�l��
{
    return ( ZERO((L.p1 - p) * (L.p2 - p)) &&
        EQ( Norm(p - L.p1) + Norm(p - L.p2), Norm(L.p2 - L.p1)) );
}

Point SymPoint(Point p, Line L)  // ���άƽ���ϵ�p����ֱ��L�ĶԳƵ�
{
    Point result;
    double a = L.p2.x - L.p1.x;
    double b = L.p2.y - L.p1.y;
    double t = ( (p.x - L.p1.x) * a + (p.y - L.p1.y) * b ) / (a*a + b*b);
    result.x = 2 * L.p1.x + 2 * a * t - p.x;
    result.y = 2 * L.p1.y + 2 * b * t - p.y;
    return result;
}

bool Coplanar(Points3D points)  // �ж�һ���㼯�еĵ��Ƿ�ȫ������
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

bool LineIntersect(Line L1, Line L2)  // �ж϶�ά����ֱ���Ƿ��ཻ
{
    return (! ZERO((L1.p1 - L1.p2)*(L2.p1 - L2.p2)) );  // �Ƿ�ƽ��
}

bool LineIntersect(Line3D L1, Line3D L2)  // �ж���ά����ֱ���Ƿ��ཻ
{
    Point3D p1 = L1.p1 - L1.p2;
    Point3D p2 = L2.p1 - L2.p2;
    Point3D p  = p1 * p2;
    if (ZERO(p)) return false;      // �Ƿ�ƽ��
    p = (L2.p1 - L1.p2) * (L1.p1 - L1.p2);
    return ZERO(p & L2.p2);         // �Ƿ���
}

bool LineSegIntersect(Line L1, Line L2) // �ж϶�ά�������߶��Ƿ��ཻ
{
    return ( GEQ( max(L1.p1.x, L1.p2.x), min(L2.p1.x, L2.p2.x) ) &&
        GEQ( max(L2.p1.x, L2.p2.x), min(L1.p1.x, L1.p2.x) ) &&
        GEQ( max(L1.p1.y, L1.p2.y), min(L2.p1.y, L2.p2.y) ) &&
        GEQ( max(L2.p1.y, L2.p2.y), min(L1.p1.y, L1.p2.y) ) &&
        LEQ( ((L2.p1 - L1.p1) * (L1.p2 - L1.p1)) * ((L2.p2 -  L1.p1) * (L1.p2 - L1.p1)), 0 ) &&
        LEQ( ((L1.p1 - L2.p1) * (L2.p2 - L2.p1)) * ((L1.p2 -  L2.p1) * (L2.p2 - L2.p1)), 0 ) );             
}

// ����������άֱ�ߵĽ��㣬����ڲ���P�з���
// ����ֵ˵��������ֱ�ߵ�λ�ù�ϵ
// COLINE   -- ����
// PARALLEL -- ƽ��
// CROSS    -- �ཻ
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

// �жϵ�p�Ƿ���͹�����poly��
// poly�Ķ�����ĿҪ���ڵ���3
// ����ֵΪ��
// INSIDE  -- ����poly��
// BORDER  -- ����poly�߽���
// OUTSIDE -- ����poly��
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

// ���ά��ֱ�ߵļнǣ� ����ֵ��0~Pi֮��Ļ���
double Inclination(Line L1, Line L2)
{
    Point u = L1.p2 - L1.p1;
    Point v = L2.p2 - L2.p1;
    return acos( (u & v) / (Norm(u)*Norm(v)) );
}

// ����ά��ֱ�ߵļнǣ� ����ֵ��0~Pi֮��Ļ���
double Inclination(Line3D L1, Line3D L2)
{
    Point3D u = L1.p2 - L1.p1;
    Point3D v = L2.p2 - L2.p1;
    return acos( (u & v) / (Norm(u)*Norm(v)) );
}

bool IsConvex(const Polygon& poly)  // �ж϶����poly�Ƿ���͹��
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

// �жϵ�p�Ƿ��ڼ򵥶����poly��, ����ο�����͹�Ļ򰼵�
// poly�Ķ�����ĿҪ���ڵ���3
// ����ֵΪ��
// INSIDE  -- ����poly��
// BORDER  -- ����poly�߽���
// OUTSIDE -- ����poly��
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
        if ( EQ(side.p1.y, side.p2.y) )  // ���sideƽ��x����������
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

// �����ε����ģ�������͹�Ļ򰼵ļ򵥶����
Point CenterOfPolygon(const Polygon& poly)  // ���㷨����һ�߶������ԵĶ���һ�߼�������
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
            m0 += EPS;  // Ϊ�˷�ֹ��0�������m0��һ�������
        }
        p.x = (m * p.x + m0 * p0.x) / (m + m0);
        p.y = (m * p.y + m0 * p0.y) / (m + m0);
        m = m + m0;
        p2 = p3;
    }
    return p;
}

Point NearestPointToLine(Point P, Line L)   // �����P��ֱ��L�������
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

Point NearestPointToLineSeg(Point P, Line L)   // �����P���߶�L�������
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

double MinDistance(Line L1, Line L2) // �����߶�L1���߶�L2����̾���
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
// �ж��߶��Ƿ��ڶ������  // ����ο���������򵥶����
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

    // �Խ����������
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

// Ѱ��͹�� graham ɨ�跨 // ���ɵĶ���ζ��㰴��ʱ�뷽������
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

    // ѡȡpoints��y������С�ĵ�points[k]��
    // ��������ĵ��ж������ȡ����ߵ�һ��
    k = 0;
    for (i = 1; i < n; i++ ) {
        if (EQ(points[i].y, points[k].y)) {
            if (points[i].x <= points[k].x) k = i;
        } else if (points[i].y < points[k].y) {
            k = i;
        }       
    }
    swap(points[0], points[k]);

    // ����points��y������С�ĵ���points[0]
    // ����ÿ���������points[0]�ļ��Ǻ;���
    for (i = 1; i < n; i++) {
        points[i].angle = atan2(points[i].y - points[0].y, points[i].x - points[0].x);
        points[i].dis   = Norm(points[i] - points[0]);
    }

    // �Զ��㰴�����points[0]�ļ��Ǵ�С�����������
    // ���ڼ�����ͬ�İ��վ�points[0]�ľ����С��������
    sort(points.begin() + 1, points.end(), GrahamComp);

    // �������͹��
    result.push_back(points[0]);
    for (i = 1; i < n; i++) {
        // ����м�����ͬ�ĵ㣬ֻȡ�����points[0]��Զ��һ��
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


// ������ֱ��line�и�͹����Σ�
// result[LEFT]��result[RIGHT]�ֱ𱣴汻�и��line����ߺ��ұ߲���
// result[ONLINE]û���õ���ֻ��������Ϊ�����ռ�
// ����ֵ���и����ε��пڵĳ��ȣ�
// �������ֵ��0 ��˵��δ���и
// ��δ���и�ʱ�����������ڸ�ֱ�ߵ��Ҳ࣬��result[RIGHT]���ڸö���Σ�����result[LEFT]���ڸö����
// ע�⣺���и�Ķ����һ��Ҫ��͹����Σ����㰴����ʱ������
// ��������������������εĺˣ���ʼ�ĺ���Ϊһ���ܴ�ľ��Σ�Ȼ�������ö���ε�ÿ����ȥ��
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


//���������
inline double Distance(Point a,Point b)
{
	return ((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) );
}

// xsetΪ��X����, ysetΪ��y����, zΪ��������, start �ڵ���ʱΪ0, end �ڵ���ʱΪn-1
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




/*  ���µĺ�����δ��֤  */

// ��ʾ���Σ����½�������(xl, yl)�����Ͻ�������(xh, yh)
struct Rect_2 {
    double xl, yl, xh, yh;
};

// �ж����������Ƿ��ཻ   // ������ڲ����ཻ
bool Intersect(Rect_2 r1, Rect_2 r2)
{
    return ( max(r1.xl, r2.xl) < min(r1.xh, r2.xh) &&
             max(r1.yl, r2.yl) < min(r1.yh, r2.yh) );
}

// �ó����ʾ���εķ���   // w, h�ֱ��ʾ��Ⱥ͸߶�
struct Rect {
    double w, h;
};

// �жϾ���r2�Ƿ���Է����ھ���r1��    // r2�����������ת
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