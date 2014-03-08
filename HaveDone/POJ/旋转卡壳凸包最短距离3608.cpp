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
#define eps 1e-8
#define zero(a) abs(a)<eps
const int N = 10005;

int n, m;
struct point{
	double x,y;
}p1[N],p2[N],a[N],b[N];
bool cmp(const point &a,const point &b){
	if( a.x == b.x ) return a.y < b.y;
	return a.x < b.x;
}
double xmult(const point &a,const point &b,const point &c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int graham(int n,point *p,point *ch){
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
double dist(point p1,point p2){ 
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)); 
}
//得到向量a1b1和a2b2的位置关系 
double Get_angle(point a1,point b1,point a2,point b2){ 
    point t; 
    t.x=a2.x-(b2.x-a1.x); 
    t.y=a2.y-(b2.y-a1.y); 
    return xmult(a1,b1,t); 
}
double Dist_point_Seg(point p,point a,point b){ 
    point t=p; 
    t.x+=a.y-b.y;t.y+=b.x-a.x; 
    if(xmult(a,t,p)*xmult(b,t,p)>eps) 
        return dist(p,a)+eps<dist(p,b)?dist(p,a):dist(p,b); 
    else 
        return fabs(xmult(p,a,b))/dist(a,b); 
} 
double Min_Dist_Two_Polygons(point *s1,point *s2,int na,int nb){
    int lp=0,lq=0; 
    for(int i=1;i<na;i++)
        if(s1[i].y<s1[lp].y||(zero(s1[i].y-s1[lp].y)&&s1[i].x<s1[lp].x)) 
           lp=i; 
    for(int i=1;i<nb;i++)
        if(s2[i].y>s2[lq].y||(zero(s2[i].y-s2[lq].y)&&s2[i].x>s2[lq].x)) 
           lq=i;
	s1[na] = s1[0];
	s2[nb] = s2[0];
    double ans=dist(s1[lp],s2[lq]); 
    int tp=lp,tq=lq; 
    do{ 
        double angle=Get_angle(s1[tp],s1[tp+1],s2[tq],s2[tq+1]); 
        //和两个凸包的边都重合 
        if(zero(angle)){ 
            ans=min(ans,Dist_point_Seg(s1[tp],s2[tq],s2[tq+1])); 
            ans=min(ans,Dist_point_Seg(s1[tp+1],s2[tq],s2[tq+1])); 
            ans=min(ans,Dist_point_Seg(s2[tq],s1[tp],s1[tp+1])); 
            ans=min(ans,Dist_point_Seg(s2[tq+1],s1[tp],s1[tp+1])); 
            tp=(tp+1)%na;tq=(tq+1)%nb; 
        } 
        else{ 
            //和第二个凸包的边重合 
            if(angle<-eps){ 
                ans=min(ans,Dist_point_Seg(s1[tp],s2[tq],s2[tq+1])); 
                tq=(tq+1)%nb; 
            } 
            //和第一个凸包的边重合 
            else{ 
                ans=min(ans,Dist_point_Seg(s2[tq],s1[tp],s1[tp+1])); 
                tp=(tp+1)%na; 
            } 
        } 
    }while(!(lp==tp&&lq==tq)); 
    return ans; 
} 
int main(){
	while( scanf("%d%d", &n, &m) != EOF ){
		if( n==0 && m==0 ) break;
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf", &p1[i].x, &p1[i].y);
		n = graham(n,p1,a);
		for(int i=0 ; i < m ; ++i)
			scanf("%lf%lf", &p2[i].x, &p2[i].y);
		m = graham(m,p2,b);
		printf("%lf\n", Min_Dist_Two_Polygons(a,b,n,m));
	}
	return 0;
}