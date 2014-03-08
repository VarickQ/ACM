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
const int N = 105;

struct Enemy{
	double x,y,si,ri,di,t;
}a[N];
double dis(Enemy a){
	return sqrt((a.x-100)*(a.x-100)+a.y*a.y);
}
bool cmp( Enemy a, Enemy b ){
	return a.t < b.t;
}
bool mark[N];
int main(){
	int n;
	double hp,t;
	while( scanf("%d", &n) == 1 ){
		memset( mark, 0, sizeof( mark ) );
		for(int i=0 ; i < n ; ++i){
			scanf("%lf%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].si,&a[i].ri,&a[i].di);
			a[i].t = dis(a[i])-a[i].ri;
		}
		sort( a, a+n, cmp );
		scanf("%lf", &hp);
		t = 100;
		for(int i=0 ; i < n ; ++i)
			if( t >= a[i].t && !mark[i] ){
				mark[i] = true;
				hp -= a[i].di;
				t += a[i].si;
				i = 0;
			}
		if( hp > 0 ) printf("Safe!\n");
		else printf("Danger!\n");
	}
	return 0;
}