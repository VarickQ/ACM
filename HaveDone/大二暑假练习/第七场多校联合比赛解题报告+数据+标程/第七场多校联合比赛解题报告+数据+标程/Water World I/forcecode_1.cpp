#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define EPS 1e-10
#define N 2200
struct TPoint{
	double x;
	double y;
};
struct Segment{
	TPoint s;
	TPoint e;
	void reset(){if(s.y>e.y)swap(s,e);}
	double getx(double h){
		double dx=e.x-s.x,dy=e.y-s.y;
		return (h-s.y)*dx/dy+s.x;
	}
	double count(Segment &b){
		double lh=s.y,hh=e.y,ans;
		if(lh<b.s.y)lh=b.s.y;
		if(hh>b.e.y)hh=b.e.y;
		if(fabs(hh-lh)<EPS)ans=0;
		else ans=(hh-lh)*(getx(lh)-b.getx(lh)+getx(hh)-b.getx(hh))/2.0;
		s.x=getx(hh);
		s.y=hh;
		b.s.x=b.getx(hh);
		b.s.y=hh;
		return fabs(ans);
	}
};
Segment s[N],seg;
const double PI=acos(-1.0);
TPoint rotate( TPoint p,double alpha)
{
	TPoint tmp;
	tmp.x = p.x * cos(alpha) - p.y * sin(alpha);
	tmp.y = p.y * cos(alpha) + p.x * sin(alpha);
	return tmp;
}
int main(){
// 	freopen("data.in", "r", stdin);
//     freopen("data2.out", "w", stdout);
	freopen("data.in", "r", stdin);
    freopen("forcedata_1.out", "w", stdout);
	int n,i,lh,nh,s_end;
	double ans,a;
	while(scanf("%d%lf",&n,&a)!=EOF){
		a=a/180*PI;
		s_end=lh=0;
		ans=0;
		for(i=0;i<n;i++){
			scanf("%d",&nh);
			seg.e.x=seg.s.x=i;
			seg.s.y=lh;
			seg.e.y=nh;
			seg.s=rotate(seg.s,a);
			seg.e=rotate(seg.e,a);
			seg.reset();
			while(s_end>0 && s[s_end-1].s.y-seg.e.y<-EPS){
				if(seg.e.y-s[s_end-1].e.y>-EPS && fabs(seg.e.x-s[s_end-1].e.x)<EPS ){s_end--;continue;}
				ans+=seg.count(s[s_end-1]);
				if(s[s_end-1].s.y-seg.e.y<-EPS)s_end--;
				else break;
			}
			s[s_end++]=seg;
			lh=nh;
			seg.e.x=i+1;
			seg.s.x=i;
			seg.s.y=seg.e.y=nh;
			seg.s=rotate(seg.s,a);
			seg.e=rotate(seg.e,a);
			seg.reset();
			while(s_end>0 && s[s_end-1].s.y-seg.e.y<-EPS){
				if(seg.e.y-s[s_end-1].e.y>-EPS && fabs(seg.e.x-s[s_end-1].e.x)<EPS ){s_end--;continue;}
				ans+=seg.count(s[s_end-1]);
				if(s[s_end-1].s.y-seg.e.y<-EPS)s_end--;
				else break;
			}
			s[s_end++]=seg;
		}
		printf("%0.2lf\n",ans);
	}
	return 0;
}
