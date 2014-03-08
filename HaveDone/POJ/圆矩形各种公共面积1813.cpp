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
const double eps = 1e-10;
const int N = 1000005;

inline int fi (double a) {
    if (a > eps) return 1;
    else if (a >= -eps) return 0;
    else return -1;
}
class Vec
{
public:
    double x, y;
    Vec (void) {}
    Vec (double x0, double y0) : x(x0), y(y0) {}
    double operator * (const Vec& a) const { return x * a.y - y * a.x; }
    double operator % (const Vec& a) const { return x * a.x + y * a.y; }
    Vec verti (void) const { return Vec(-y, x); }
    double length (void) const { return sqrt(x * x + y * y); }
    Vec adjust (double len)
    {
        double ol = len / length();
        return Vec(x * ol, y * ol);
    }
    Vec oppose (void) { return Vec(-x, -y); }
};
class point
{
public:
    double x, y;
    point (void) {}
    point (double x0, double y0) : x(x0), y(y0) {}
    Vec operator - (const point& a) const { return Vec(x - a.x, y - a.y); }
    point operator + (const Vec& a) const { return point(x + a.x, y + a.y); }
};
class segment
{
public:
    point a, b;
    segment (void) {}
    segment (point a0, point b0) : a(a0), b(b0) {}
    point intersect (const segment& s) const
    {
        Vec v1 = s.a - a, v2 = s.b - a, v3 = s.b - b, v4 = s.a - b;
        double s1 = v1 * v2, s2 = v3 * v4;
        double se = s1 + s2;
        s1 /= se, s2 /= se;
        return point(a.x * s2 + b.x * s1, a.y * s2 + b.y * s1);
    }
    point pverti (const point& p) const
    {
        Vec t = (b - a).verti();
        segment uv(p, p + t);
        return intersect(uv);
    }
    bool on_segment (const point& p) const
    {
        if (fi(min(a.x, b.x) - p.x) <= 0 && fi(p.x - max(a.x, b.x)) <= 0 &&
            fi(min(a.y, b.y) - p.y) <= 0 && fi(p.y - max(a.y, b.y)) <= 0) return true;
        else return false;
    }
};
double r;
point p[10];
double kuras_area (point a, point b)
{
    point ori(0, 0);
    int sgn = fi((b - ori) * (a - ori));
    double da = (a - ori).length(), db = (b - ori).length();
    int ra = fi(da - r), rb = fi(db - r);
    double angle = acos(((b - ori) % (a - ori)) / (da * db));
    segment t(a, b); point h, u; Vec seg;
    double ans, dlt, mov, tangle;
    
    if (fi(da) == 0 || fi(db) == 0) return 0;
    else if (sgn == 0) return 0;
    else if (ra <= 0 && rb <= 0) return fabs((b - ori) * (a - ori)) / 2 * sgn;
    else if (ra >= 0 && rb >= 0)
    {
        h = t.pverti(ori);
        dlt = (h - ori).length();
        if (!t.on_segment(h) || fi(dlt - r) >= 0)
            return r * r * (angle / 2) * sgn;
        else
        {
            ans = r * r * (angle / 2);
            tangle = acos(dlt / r);
            ans -= r * r * tangle;
            ans += r * sin(tangle) * dlt;
            return ans * sgn;
        }
    }
    else
    {
        h = t.pverti(ori);
        dlt = (h - ori).length();
        seg = b - a;
        mov = sqrt(r * r - dlt * dlt);
        seg = seg.adjust(mov);
        if (t.on_segment(h + seg)) u = h + seg;
        else u = h + seg.oppose();
        if (ra == 1) swap(a, b);
        ans = fabs((a - ori) * (u - ori)) / 2;
        tangle = acos(((u - ori) % (b - ori)) / ((u - ori).length() * (b - ori).length()));
        ans += r * r * (tangle / 2);
        return ans * sgn;
    }
}
double comarea(point a,point b,double r1,double r2){
	double d = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	if( r1 > r2 ) swap(r1,r2);
	if( r1+r2 <= d ) return 0;
	else if( r2-r1 >= d )
		return PI*r1*r1;
	else {
		double a1=acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
		double a2=acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));
		return (a1*r1*r1+a2*r2*r2-r1*d*sin(a1));
	}
}
int main(){
	int T, vis[11][11];
	char s[3];
	double r1,r2;
	point a[2],b[2],c[2];
	scanf("%d", &T);
	while( T-- ){
		scanf("%s", s);
		if( s[0] == 'R' )
			scanf("%lf%lf%lf%lf",&a[0].x,&a[0].y,&a[1].x,&a[1].y);
		else if( s[0] == 'C' )
			scanf("%lf%lf%lf", &c[0].x,&c[0].y,&r1);
		scanf("%s", s+1);
		if( s[1] == 'R' )
			scanf("%lf%lf%lf%lf",&b[0].x,&b[0].y,&b[1].x,&b[1].y);
		else if( s[1] == 'C' )
			scanf("%lf%lf%lf", &c[1].x,&c[1].y,&r2);
		if( strcmp(s,"RR") == 0 ){
			memset( vis, 0, sizeof( vis ) );
			for(int i=a[0].x ; i < a[1].x ; ++i)
				for(int j=a[0].y ; j < a[1].y ; ++j)
					vis[i][j]++;
			for(int i=b[0].x ; i < b[1].x ; ++i)
				for(int j=b[0].y ; j < b[1].y ; ++j)
					vis[i][j]++;
			int ans = 0;
			for(int i=0 ; i <= 10 ; ++i)
				for(int j=0 ; j <= 10 ; ++j)
					if( vis[i][j] == 2 ) ans++;
			printf("%d\n", ans);
		}
		else if( strcmp(s,"CC") == 0 ){
			printf("%d\n",(int)(comarea(c[0],c[1],r1,r2)+0.5));
		}
		else if( strcmp(s,"RC") == 0 ){
			r = r2;
			p[0] = point(a[0].x-c[1].x,a[0].y-c[1].y);
			p[1] = point(a[1].x-c[1].x,a[0].y-c[1].y);
			p[2] = point(a[1].x-c[1].x,a[1].y-c[1].y);
			p[3] = point(a[0].x-c[1].x,a[1].y-c[1].y);
			double ans = 0;
			for(int i=0 ; i < 4 ; ++i)
				ans += kuras_area(p[i],p[(i+1)%4]);
			printf("%d\n", int(fabs(ans)+0.5));
		}
		else if( strcmp(s,"CR") == 0 ){
			r = r1;
			p[0] = point(b[0].x-c[0].x,b[0].y-c[0].y);
			p[1] = point(b[1].x-c[0].x,b[0].y-c[0].y);
			p[2] = point(b[1].x-c[0].x,b[1].y-c[0].y);
			p[3] = point(b[0].x-c[0].x,b[1].y-c[0].y);
			double ans = 0;
			for(int i=0 ; i < 4 ; ++i)
				ans += kuras_area(p[i],p[(i+1)%4]);
			printf("%d\n", int(fabs(ans)+0.5));
		}

	}
	return 0;
}