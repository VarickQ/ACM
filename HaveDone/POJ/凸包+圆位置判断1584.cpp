/*���⣺��֪һ������ε�n���������꣬Ȼ���ٸ�һ�����ӣ��������ӵİ뾶��Բ�����꣬�����ж϶�����Ƿ�Ϊ͹����Σ���Ϊ͹����Σ����ж϶����Ƿ���Էŵ�͹������ڲ���
 
˼·���ܺõļ��㼸�Ρ�
1.���ڶ��������˳�����Ϊ��ʱ���˳ʱ�룬�������ж��Ƿ�Ϊ͹�߱��Σ����ò�������ʣ�ÿ��������ɨ�迴�Ƿ�˳��ͬһ�ķ���ת����
2.�ж�Բ(����)�Ƿ��ڶ�����ڲ�����һ���ж�Բ���Ƿ���͹������ڲ�����Բ��Ϊ����ɨ��һ�ܣ����ڶ������ж�Բ�ĵ�ĳһ�ߵ���̾��룬������ĳ��̾������Բ�ģ���Բ���ܷ���͹����ڡ�*/
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
    for (int i=0; i<n; ++i){//���㹱��Ҳ����͹������
        while (m >= 2 && xmult(CH[m-2], CH[m-1], P[i]) < 0) m--;
        CH[m++] = P[i];
    }
    // ���ϰ벿�������ٰ��뷽�Ű��^�ĽK�c�������ٰ�һ�����c
    for (int i=n-2, t=m+1; i>=0; --i){
        while (m >= t && xmult(CH[m-2], CH[m-1], P[i]) < 0) m--;
        CH[m++] = P[i];
    }
    m--;    // ����һ���c�����}���F�ɴε����c����Ҫ�pһ��
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