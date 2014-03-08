#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int inf = 2000000000;
const int M = 2000100;
const int N = 10010;

struct point{double x,y;};
struct line{point a,b;};

point intersection(line u,line v){
	point ret=u.a;
	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
			/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x+=(u.b.x-u.a.x)*t;
	ret.y+=(u.b.y-u.a.y)*t;
	return ret;
}
//´¹ÐÄ
point perpencenter(point a,point b,point c){
	line u,v;
	u.a=c;
	u.b.x=u.a.x-a.y+b.y;
	u.b.y=u.a.y+a.x-b.x;
	v.a=b;
	v.b.x=v.a.x-a.y+c.y;
	v.b.y=v.a.y+a.x-c.x;
	return intersection(u,v);
}

int main(){
	point a[4],res;
	int n;
	scanf("%d",&n);
	while(n--){
		memset(a,0,sizeof(a));
		for(int i=0 ; i < 3 ; ++i)
			scanf("%lf %lf",&a[i].x,&a[i].y);
		res = perpencenter(a[0],a[1],a[2]);
		printf("%.4lf %.4lf\n",res.x,res.y);
	}
	return 0;
}