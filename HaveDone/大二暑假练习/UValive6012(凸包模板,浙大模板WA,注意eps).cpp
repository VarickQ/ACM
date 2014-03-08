#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
typedef long long LL;
const int N   = 505;
const int M   = 300000;
const LL inf = 1000000000;
const double PI = acos(-1.0);

int cnt;
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
};

struct Circle{
	Point P;
	double r;
}c[N];

Point P[M],CH[M];

//ʸ��V��PΪ������ʱ����תangle���Ŵ�scale��
Point rotate(Point v,Point p,double angle,double scale){
	Point ret=p;
	v.x-=p.x,v.y-=p.y;
	p.x=scale*cos(angle);
	p.y=scale*sin(angle);
	ret.x+=v.x*p.x-v.y*p.y;
	ret.y+=v.x*p.y+v.y*p.x;
	return ret;
}
//********************͹��ģ��
// cross product of p0p1 x p0p2
double xmult(const Point &p0, const Point &p1, const Point &p2){
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
int Andrew_monotone_chain(Point *P, Point *CH, int n){
    // �������c�������˴�С����
    sort(P, P+n, less<Point>());
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


double dis(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void work(int i,int j){
	Point tmp;
	double d, r, pha;
	d = dis(c[i].P,c[j].P);
	r = fabs(c[i].r-c[j].r);
	pha = acos( r/d );
	
	if( c[i].r > c[j].r ){
		tmp = rotate(c[j].P,c[i].P,pha,c[i].r/d);
		tmp.id = i;
		P[cnt++] = tmp;
		tmp = rotate(c[j].P,c[i].P,-pha,c[i].r/d);
		tmp.id = i;
		P[cnt++] = tmp;

		tmp = rotate(c[i].P,c[j].P,PI-pha,c[j].r/d);
		tmp.id = j;
		P[cnt++] = tmp;
		tmp = rotate(c[i].P,c[j].P,PI+pha,c[j].r/d);
		tmp.id = j;
		P[cnt++] = tmp;
	} else {
		tmp = rotate(c[i].P,c[j].P,pha,c[j].r/d);
		tmp.id = j;
		P[cnt++] = tmp;
		tmp = rotate(c[i].P,c[j].P,-pha,c[j].r/d);
		tmp.id = j;
		P[cnt++] = tmp;

		tmp = rotate(c[j].P,c[i].P,PI-pha,c[i].r/d);
		tmp.id = i;
		P[cnt++] = tmp;
		tmp = rotate(c[j].P,c[i].P,PI+pha,c[i].r/d);
		tmp.id = i;
		P[cnt++] = tmp;
	}

}
int main(){
	int T, n, g;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i){
			scanf("%lf%lf%lf",&c[i].P.x,&c[i].P.y,&c[i].r);
			c[i].P.id = i;
		}
		if( n == 1 ){
			printf("%.5lf\n", 2*PI*c[0].r);
			continue;
		}
		cnt = 0;
		for(int i=0 ; i < n ; ++i)
			for(int j=i+1 ; j < n ; ++j)
				work( i, j );
		int g = Andrew_monotone_chain(P,CH,cnt);
		CH[g] = CH[0];
		double ans = 0;
		for(int i=0 ; i < g ; ++i){
			if( CH[i].id == CH[i+1].id ){
				Point tmp = c[CH[i].id].P;
				double pha1 = atan2(CH[i].y-tmp.y,CH[i].x-tmp.x);
				double pha2 = atan2(CH[i+1].y-tmp.y,CH[i+1].x-tmp.x);
				double pha = pha2-pha1;
				while( pha < 0 ) pha+=2*PI;
				while( pha > 2*PI ) pha-=2*PI;
				ans += pha*c[CH[i].id].r;
			}
			else ans += dis(CH[i],CH[i+1]);
		}
		printf("%.5lf\n", ans);
	}
    return 0;
}
