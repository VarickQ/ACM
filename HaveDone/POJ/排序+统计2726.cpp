/*����n����Ԫ��(xi,yi)��ͳ���ж��ٸ���Ԫ��(xk,yk)���㣺
*��������xi < xk�Ķ�Ԫ�飬yi > yk��
*��������yi < yk�Ķ�Ԫ��, xi > xk
*( n<= 10000��ai<= 10000)
*����Ȼ��ͳ�ơ�
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