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
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
typedef __int64 LL;
const int N   = 100010;
const int M   = 300000;
const LL inf = (1LL<<60);

struct Point{
	LL x, y;
	int id;
}a[N];
bool cmp1(Point a,Point b){
	return a.x < b.x;
}
bool cmp2(Point a,Point b){
	return a.y < b.y;
}
LL lx[N],rx[N],ly[N],ry[N],sumx[N],sumy[N];
int main(){
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		CLR( lx, 0 );
		CLR( rx, 0 );
		CLR( ly, 0 );
		CLR( ry, 0 );
		CLR( sumx, 0 );
		CLR( sumy, 0 );
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i){
			scanf("%I64d%I64d", &a[i].x, &a[i].y);
			a[i].id = i+1;
		}
		sort( a, a+n, cmp1 );
		int rrx = a[n-1].id;
		for(int i=0 ; i < n ; ++i){
			if( !i ) sumx[a[0].id] = a[0].x;
			else sumx[a[i].id] = sumx[a[i-1].id]+a[i].x;
			lx[a[i].id] = i+1;
			rx[a[i].id] = n-i;
		}
		sort( a, a+n, cmp2 );
		int rry = a[n-1].id;
		for(int i=0 ; i < n ; ++i){
			if( !i ) sumy[a[0].id] = a[0].y;
			else sumy[a[i].id] = sumy[a[i-1].id]+a[i].y;
			ly[a[i].id] = i+1;
			ry[a[i].id] = n-i;
		}
		LL tmp,sx,mx,sy,my,ans = inf;
		for(int i=0 ; i < n ; ++i){
			sx = lx[a[i].id]*a[i].x-sumx[a[i].id];
			mx = sumx[rrx]-sumx[a[i].id]-(rx[a[i].id]-1)*a[i].x;
			sy = ly[a[i].id]*a[i].y-sumy[a[i].id];
			my = sumy[rry]-sumy[a[i].id]-(ry[a[i].id]-1)*a[i].y;
			tmp = sx+mx+sy+my;
			ans = min( ans, tmp );
		}
		printf("%I64d\n", ans);
	}
    return 0;
}