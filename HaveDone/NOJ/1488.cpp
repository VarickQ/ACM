#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll __int64
const int inf = 2000000000;
const int N = 1005;

int a[N];
int main(){
	int n;
	while(scanf("%d",&n) == 1)
	{
		for(int i=0 ; i < n ; ++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d\n",a[n-1]+a[n-2]+a[n-3]);
	}
	return 0;
}