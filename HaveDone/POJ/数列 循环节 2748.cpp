#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf=2000000000;
const int N = 750000;
const int M = 100000;
//很容易推出f(i) = [3 * f(i - 1) - f(i - 2)] mod 100000。
//通过程序测试一下，可以发现f(i)以750000为循环节，
//因此f(i) = f(i mod 750000)。
int a[N+5];
int main()
{
	int T,n;
	a[0] = 1;
	a[1] = 1;
	a[2] = 2;
	a[3] = 5;
	for(int i=4 ; i <= N ; ++i)
		a[i] = (3*a[i-1]%M-a[i-2]%M+M)%M;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",a[n%N]);
	}
	return 0;
}