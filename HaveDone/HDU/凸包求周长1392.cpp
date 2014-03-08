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
const int N = 105;

struct point{
	double x,y;
}p[N],ch[N];
bool cmp(const point &a,const point &b){
	if( a.x == b.x ) return a.y < b.y;
	return a.x < b.x;
}
double xmult(const point &a,const point &b,const point &c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int gao(int n){
	sort( p, p+n, cmp );
	int m = 0;
	for(int i=0 ; i < n ; ++i){
		while( m>=2 && xmult(ch[m-2],ch[m-1],p[i]) <= 0 )m--;
		ch[m++] = p[i];
	}
	for(int i=n-2,t=m+1 ; i >= 0 ; --i){
		while( m>=t && xmult(ch[m-2],ch[m-1],p[i]) <= 0 )m--;
		ch[m++] = p[i];
	}
	m--;
	return m;
}
double dis(const point &a,const point &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	int n;
	while( scanf("%d", &n) && n ){
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		if( n == 1 ) puts("0.00");
		else if( n == 2 )
			printf("%.2lf\n", dis(p[0],p[1]));
		else {
			int g = gao(n);
			double ans = 0;
			for(int i=0 ; i < g ; ++i){
				ans += dis(ch[i],ch[(i+1)%g]);
			}
			//if( g == 2 ) ans /= 2;
			printf("%.2lf\n", ans);
		}
	}
	return 0;
}