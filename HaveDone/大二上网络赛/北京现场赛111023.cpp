#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-10
#define zero(x) (((x)>0?(x):-(x))<eps)
const int M = 1000;
const int N = 20;
struct point{double x,y;}a[N];
struct A{
	double a,b,c;
}b[M];
bool mark[M][M];
double dis(point a,point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool fun(A a,A b){
	double aa[3],bb[3];
	aa[0]=a.a; aa[1]=a.b; aa[2]=a.c;
	bb[0]=b.a; bb[1]=b.b; bb[2]=b.c;
	sort(aa,aa+3);
	sort(bb,bb+3);
	if(aa[0]*bb[1]==aa[1]*bb[0]	&& aa[0]*bb[2]==aa[2]*bb[0]	&& aa[1]*bb[2]==aa[2]*bb[1])
		return true;
	return false;
}
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}
int main(){
	int n,p;
	int x,y;
	while(scanf("%d",&n) && n){
		memset(mark,0,sizeof(mark));
		p = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%d%d",&x,&y);
			if(!mark[x+200][y+200]){
				mark[x+200][y+200] = true;
				++p;
				a[p].x = 1.0*x;
				a[p].y = 1.0*y;
			}
		}
		int cnt = 0;
		for(int i=1 ; i <= p ; ++i){
			for(int j=i+1 ; j <= p ; ++j){
				for(int k=j+1 ; k <= p ; ++k){
					if(dots_inline(a[i],a[j],a[k])) continue;
					++cnt;
					b[cnt].a = dis(a[i],a[j]);
					b[cnt].b = dis(a[j],a[k]);
					b[cnt].c = dis(a[k],a[i]);
				}
			}
		}
		int ans = 0;
		for(int i=1 ; i <= cnt ; ++i){
			int count = 1;
			for(int j=i+1 ; j <= cnt ; ++j)
				if(fun(b[i],b[j]))
					count++;
			if(count > ans) ans = count;
		}
		printf("%d\n",ans);
	}
	return 0;
}