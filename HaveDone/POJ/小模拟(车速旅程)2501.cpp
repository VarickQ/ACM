#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 1005;
typedef long long LL;

char str[N];
int main(){
	int h,m,s,t=0,v=0,pre=0,pv=0;
	double dis = 0;
	while( gets(str) ){
		bool f = false;
		for(int i=0 ; str[i] ; ++i)
			if( str[i] == ' ' ){
				f = true; break;
			}
		if( f ){
			pv = v;
			sscanf(str,"%d:%d:%d %d",&h,&m,&s,&v);
		}
		else sscanf(str,"%d:%d:%d",&h,&m,&s);
		t = h*3600+m*60+s-pre;
		if( f )	dis += pv*t/3600.0;
		else dis += v*t/3600.0;
		if( !f ) printf("%02d:%02d:%02d %.2lf km\n",h,m,s,dis);
		pre += t;
	}
	return 0;
}