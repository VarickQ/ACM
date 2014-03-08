#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-8;
const int inf = 1000000000;
const int M = 6050000;
const int N = 1005;

struct Node{
	double x,y;
}a[5],s;
bool cmp(const Node &a,const Node &b){
	if( a.x == b.x ) return a.y < b.y;
	return a.x < b.x;
}
int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	while( scanf("%lf%lf", &a[0].x, &a[0].y) != EOF ){
		for(int i=1 ; i < 4 ; ++i)
			scanf("%lf%lf", &a[i].x, &a[i].y);
		sort( a, a+4, cmp );
		int pos;
		for(int i=0 ; i < 3 ; ++i)
			if( a[i].x==a[i+1].x && a[i].y==a[i+1].y )
				s = a[i];
		double x = 0,y = 0;
		for(int i=0 ; i < 4 ; ++i){
			x += a[i].x - s.x;
			y += a[i].y - s.y;
		}
		printf("%.3lf %.3lf\n", s.x+x, s.y+y);
	}
    return 0;
}