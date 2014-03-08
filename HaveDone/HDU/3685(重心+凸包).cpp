#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const int N = 50010;
const int inf = 1000000000;
#define eps 1e-8

class point
{
public:
    double x, y;
    point() {}
    point(double x, double y) {
        this->x = x; this->y = y;
    }
    point operator - (const point &a) const {
        return point(x-a.x, y-a.y);
    }
    friend bool operator < (const point& a, const point& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
}a[N],b[N],p;
struct line{point a,b;};
//********************凸包模板
// cross product of p0p1 x p0p2
double xmult(const point &p0, const point &p1, const point &p2){
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
int Andrew_monotone_chain(point *P, point *CH, int n){
    // 將所有點依照座標大小排序
    sort(P, P+n, less<point>());
    int m = 0;  // m 為凸包頂點數目
    // 包下半部
    for (int i=0; i<n; ++i){
        while (m >= 2 && xmult(CH[m-2], CH[m-1], P[i]) <= 0) m--;
        CH[m++] = P[i];
    }
    // 包上半部，不用再包入方才包過的終點，但會再包一次起點
    for (int i=n-2, t=m+1; i>=0; --i){
        while (m >= t && xmult(CH[m-2], CH[m-1], P[i]) <= 0) m--;
        CH[m++] = P[i];
    }
    m--;    // 最後一個點是重複出現兩次的起點，故要減一。
    return m;
}
point intersection(line u,line v){
	point ret=u.a;
	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
			/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x+=(u.b.x-u.a.x)*t;
	ret.y+=(u.b.y-u.a.y)*t;
	return ret;
}
point barycenter(point a,point b,point c){
	line u,v;
	u.a.x=(a.x+b.x)/2;
	u.a.y=(a.y+b.y)/2;
	u.b=c;
	v.a.x=(a.x+c.x)/2;
	v.a.y=(a.y+c.y)/2;
	v.b=b;
	return intersection(u,v);
}
//多边形重心
point barycenter(int n,point* p){
	point ret,t;
	double t1=0,t2;
	int i;
	ret.x=ret.y=0;
	for (i=1;i<n-1;i++)
		if (fabs(t2=xmult(p[0],p[i],p[i+1]))>eps){
			t=barycenter(p[0],p[i],p[i+1]);
			ret.x+=t.x*t2;
			ret.y+=t.y*t2;
			t1+=t2;
		}
	if (fabs(t1)>eps)
		ret.x/=t1,ret.y/=t1;
	return ret;
}
double dis(point a,point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool ok(int i,int j){
	double d1 = dis( b[i], p );
	double d2 = dis( b[j], p );
	double d3 = dis( b[i], b[j] );
	if( d1+d3-d2 <= eps || d2+d3-d1 <= eps) return false;
	return true;
}
int main(){
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf", &a[i].x, &a[i].y);
		p = barycenter(n,a);
		int g = Andrew_monotone_chain(a,b,n);
		b[g] = b[0];
		int ans = 0;
		for(int i=0 ; i < g ; ++i)
			if( ok(i,i+1) ) ans++;
		printf("%d\n", ans);
	}
	return 0;
}