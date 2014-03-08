#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const double inf = 10000000.0;

int main()
{
	double v,t,min;
	int i,n;
	while(scanf("%d", &n) && n)
	{
		min = inf;
		for(i =0; i < n ;i ++){
			scanf("%lf%lf",&v,&t);
			if(t >= 0){
				t += 4.5/(v/3600.0);
				if(min > t)
					min = t;
				min = ceil(min);
			}
		}
		printf("%d\n",(int)min);
	}
	return 0;
}