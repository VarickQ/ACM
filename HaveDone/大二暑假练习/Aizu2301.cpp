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
const int N = 25;
typedef long long LL;

int k;
double ans,r,l,p,e,t;
void dfs(double l,double r,int c,double pp){
	if( l>t+e || r<t-e ) return ;
	if( l>=t-e && r<=t+e ){
		ans+=pp; return ;
	}
	double mid = (l+r)/2;
	if( c > k ){
		if( fabs(mid-t) <= e ) ans+=pp;
		return;
	}
	if( mid < t ){
		dfs(mid,r,c+1,pp*(1-p));
		dfs(l,mid,c+1,pp*p);
	} else {
		dfs(l,mid,c+1,pp*(1-p));
		dfs(mid,r,c+1,pp*p);
	}
}
int main(){
	while( scanf("%d%lf%lf", &k, &l, &r) != EOF ){
		scanf("%lf%lf%lf", &p, &e, &t);
		ans = 0;
		dfs(l,r,1,1);
		printf("%.12lf\n", ans);
	}
	return 0;
}