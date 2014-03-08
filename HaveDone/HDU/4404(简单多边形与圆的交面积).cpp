#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double PI  = acos(-1.0);
const double eps = 1e-10;

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
point p[150];
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
int main (){
    double ans,x0,y0,v0,tha,t,g,x,y;
    int n;
    while( scanf("%lf%lf%lf%lf%lf%lf%lf",&x0,&y0,&v0,&tha,&t,&g,&r) != EOF ){
        if(x0==0&&y0==0&&v0==0&&tha==0&&t==0&&g==0&&r==0) break;
        tha = tha/180.0*PI;
        double vx = v0*cos(tha);
        double vy = v0*sin(tha);
        double t1 = vy/g;
        double h1 = 0.5*g*t1*t1+y0;
        double h2 = 0.5*g*(t-t1)*(t-t1);
        double dy = h1-h2;
        double dx = vx*t+x0;
        scanf("%d", &n);
        for(int i=0 ; i < n ; ++i){
            scanf("%lf%lf", &x, &y);
            x -= dx;
            y -= dy;
            p[i] = point( x, y );
        }
        ans = 0;
        for(int i=0 ; i < n ; ++i)
            ans += kuras_area( p[i], p[(i+1)%n] );
        printf("%.2lf\n", fabs(ans));
    }
    return 0;
}