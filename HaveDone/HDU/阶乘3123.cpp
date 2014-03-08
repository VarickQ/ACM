#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 1000000;

char str[120];
__int64 a[N];
int main(){
	int T,l;
	__int64 n,m,temp;
	scanf("%d",&T);
	while(T--){
		scanf("%s%I64d",str,&m);
		int len = strlen(str);
		l = 0;
		temp = m;
		while(temp){
			temp /= 10;
			l++;
		}
		if(l >= len){
			sscanf(str,"%I64d",&n);
			if(n >= m) n = m-1;
		} else n = m-1;
		__int64 ans = 0;
		a[0] = 1;
		for(__int64 i=1 ; i <= n ; ++i){
			a[i] = (a[i-1]*i)%m;
			ans = (ans+a[i])%m;
		}
		printf("%I64d\n",(ans+1)%m);
	}
	return 0;
}