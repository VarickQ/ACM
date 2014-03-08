#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 1000000000;
const int M = 100000;
const int N = 1501;

double f[N];
int main(){
	int T,cs=0,n;
	f[0]=0;
	f[1]=1;
	f[2]=1.5;
	for(int i=3 ; i <= 1500 ; ++i){
		if(i&1) f[i] = f[i-1]*2-f[i-2];
		else f[i] = f[i-1]*(2.0*i-1.0)/i-f[i-2]*(i-1.0)/i*1.0;
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("Case %d: %.6lf\n",++cs,f[n]);
	}
	return 0;
}
