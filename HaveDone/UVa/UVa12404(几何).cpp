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
#define Lowbit(x) ((x)&(-x))
const int N = 150005;
typedef long long LL;

struct point{double x,y;}A,B,C,D;
double b,c,d,lenab;
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	int T, cs = 1;
	scanf("%d", &T);
	while( T-- ){
		scanf("%lf%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&b,&c,&d);
		printf("Case %d:\n", cs++);
		lenab = dis(A,B);
		double cosf = (B.x-A.x)/lenab;
		double sinf = (B.y-A.y)/lenab;
		double t = lenab - c;
		double y = (t*t-d*d+b*b)/(2.0*t);
		double x = lenab-c-y;
		double h = sqrt(d*d-x*x);
		C.x = x*cosf-h*sinf+A.x;
		C.y = x*sinf+h*cosf+A.y;
		D.x = (x+c)*cosf-h*sinf+A.x;
		D.y = (x+c)*sinf+h*cosf+A.y;
		printf("%.8lf %.8lf %.8lf %.8lf\n", D.x, D.y, C.x, C.y);
	}
	return 0;
}