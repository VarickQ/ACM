#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000000000;

int a[1900];
int main(){
	int n,i;
	a[1] = 1;
	a[2] = 4;
	for(i=3 ; i <= 1850 ; ++i)
		a[i] = a[i-1]+(1+i)*i/2;
	while(scanf("%d",&n) == 1)
	{
		for(i=1 ; i <= 1850 ; ++i)
			if(a[i] >= n) break;
		int temp = a[i]-n;
		i = 1;
		while(temp-i >= 0){
			temp -= i;
			i++;
		}
		printf("%d\n",i);
	}
	return 0;
}