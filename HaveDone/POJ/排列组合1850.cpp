#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 1000000000;
const int N = 1000001;

int com(int n, int r)
{	// return C(n, r)
	int i, j, s = 1;
	if(n-r>r) r=n-r; // C(n, r) = C(n, n-r)
	for(i=0,j=1;i<r;++i){
		s *= (n-i);
		for( ; j <= r && s%j == 0; ++j ) s /= j;
	}
	return s;
}

int main(){
	int i;
	ll ans;
	char str[12];
	while(scanf("%s",str) != EOF){
		int len = strlen(str);
		bool f = false;
		for(i=0 ; i < len-1 ; ++i)
			if(str[i] >= str[i+1])
				f = true;
		if(f) printf("0\n");
		else {
			ans = 0;
			for(i=1 ; i <= len ; ++i)
				ans += com(26,i);
			for(i=0 ; i < len ; ++i)
				ans -= com(26-(str[i]-'a'+1),len-i);
			printf("%I64d\n",ans);
		}
	}
	return 0;
}