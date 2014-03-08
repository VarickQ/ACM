#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const ll inf = (1LL<<63-1);
const ll M = 1000000007;
const int N = 3030000;

ll f1(ll n){
	return n*(n+1)*(n+2);
}
ll f2(ll n){
	return n*(n+1);
}
int main(){
	int T;
	ll s,i,n,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d",&s);
		n = (__int64)pow(6.0*s,1.0/3.0);
		while(f1(n) < 6*s)//n*(n+1)*(n+2)/6
			n++;
		
		s -= f1(n-1)/6;
		printf("%I64d ",n);

		n = (__int64)pow(2.0*s,1.0/2.0);
		while(f2(n) < 2*s)
			n++;
		s -= f2(n-1)/2;
		printf("%I64d %I64d\n",n,s);
	}
	return 0;
}