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
const int M = 55;
const int N = 510;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point3{double x,y,z;};
point3 s[N],te,t[M];
double phi[M];
bool vis[N];
point3 subt(point3 u,point3 v){
	point3 ret;
	ret.x=u.x-v.x;
	ret.y=u.y-v.y;
	ret.z=u.z-v.z;
	return ret;
}
double dmult(point3 u,point3 v){
	return u.x*v.x+u.y*v.y+u.z*v.z;
}
double vlen(point3 p){
	return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}
double angle_cos(point3 u1,point3 u2,point3 v1,point3 v2){
	return dmult(subt(u1,u2),subt(v1,v2))/vlen(subt(u1,u2))/vlen(subt(v1,v2));
}
int main(){
	int n,m,i,j;
	while(scanf("%d",&n) && n){
		memset(vis,0,sizeof(vis));
		te.x = te.y = te.z = 0;
		for(i=0 ; i < n ; ++i)
			scanf("%lf%lf%lf",&s[i].x,&s[i].y,&s[i].z);
		scanf("%d",&m);
		for(i=0 ; i < m ; ++i)
			scanf("%lf%lf%lf%lf",&t[i].x,&t[i].y,&t[i].z,&phi[i]);
		int ans = 0;
		for(i=0 ; i < m ; ++i)
			for(j=0 ; j < n ; ++j)
				if(!vis[j] && acos(angle_cos(te,t[i],te,s[j])) < phi[i]){
					ans++; vis[j] = true;
				}
		printf("%d\n",ans);
	}
	return 0;
}