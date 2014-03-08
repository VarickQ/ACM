/*输入n个二元组(xi,yi)，统计有多少个二元组(xk,yk)满足：
*对于任意xi < xk的二元组，yi > yk；
*对于任意yi < yk的二元组, xi > xk
*( n<= 10000，ai<= 10000)
*排序，然后统计。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll __int64
const int inf = 2000000000;
const int N = 10100;

struct A{
	int d,c;
}a[N];
bool cmp(const A &a,const A &b){
	if(a.d != b.d) return a.d < b.d;
	return a.c < b.c;
}
int main()
{
	int n,m;
	while(scanf("%d",&n) && n){
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d",&a[i].d,&a[i].c);
		sort(a,a+n,cmp);
		m = 0;
		int min = inf;
		for(int i=0 ; i < n ; ++i)
			if(a[i].c < min)
				min = a[i].c,m++;
		printf("%d\n",m);
	}
	return 0;
}