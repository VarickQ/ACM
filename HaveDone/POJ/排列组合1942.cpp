#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>
#include <string.h>

double com(double n,double m){
	double i,ans=1;
	for(i=m ; i >= m-n+1 ; i--)
		ans *= i/(i-m+n);
	return ans;
}
int main()
{
	double n,m;
	while(scanf("%lf%lf",&n,&m) == 2)
	{
		if(n==0 && m==0) break;
		double k = n<m?n:m;
		printf("%.0lf\n",com(k,n+m));
	}
	return 0;
}