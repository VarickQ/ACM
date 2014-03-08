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
const int inf = 2000000000;
const int M   = 1000000000;
const int N   = 100000;

ll f[N],n,d[N];
int main()
{
	int T,i;
	f[0] = 0;
	for(i=1 ; i <= 9 ; ++i)
		f[i] = f[i-1]+1;
	for(i=10 ; i <= 99 ; ++i)
		f[i] = f[i-1]+2;
	for(i=100 ; i <= 999 ; ++i)
		f[i] = f[i-1]+3;
	for(i=1000 ; i <= 9999 ; ++i)
		f[i] = f[i-1]+4;
	for(i=10000 ; i <= 99999 ; ++i)
		f[i] = f[i-1]+5;
	d[1] = f[1];
	for(i=2 ; d[i-1] <= 2147483647 ; ++i)
		d[i] = d[i-1]+f[i];
	int k = i;
	char str[10];
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		for(i=1 ; i <= k ; ++i)
			if(d[i] >= n) break;
		n -= d[i-1];
		int temp=0;
		if(n-f[99999]>0) temp = 5;
		else if(n-f[9999]>0) temp = 4;
		else if(n-f[999]>0) temp = 3;
		else if(n-f[99]>0) temp = 2;
		else if(n-f[9]>0) temp = 1;
		if(temp==0){
			for(i=1 ; i <= 9 ; ++i)
				if(n <= f[i]) break;
		} else if(temp==1) {
			for(i=10 ; i <= 99 ; ++i)
				if(n <= f[i]) break;
		} else if(temp==2) {
			for(i=100 ; i <= 999 ; ++i)
				if(n <= f[i]) break;
		} else if(temp==3) {
			for(i=1000 ; i <= 9999 ; ++i)
				if(n <= f[i]) break;
		} else if(temp==4) {
			for(i=10000 ; i <= 99999 ; ++i)
				if(n <= f[i]) break;
		}
		n -= f[i-1];
		sprintf(str,"%d",i);
		printf("%c\n",str[n-1]);
	}
	return 0;
}