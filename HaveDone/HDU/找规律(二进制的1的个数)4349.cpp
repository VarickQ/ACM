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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 1005;
typedef __int64 LL;
const LL MOD   = 1000000009;

LL tmp[60];
LL Tento(LL n,LL a){
	LL i=0;
	while(n){
		tmp[i++]=n%a;
		n/=a;
	}
	return i;
}
int main(){
	LL n;
	while( scanf("%I64d", &n) != EOF ){
		memset( tmp, 0, sizeof( tmp ) );
		LL len = Tento(n,2);
		LL num = 0;
		for(LL i=0 ; i < len ; ++i)
			if( tmp[i] ) num++;
		printf("%I64d\n", (1LL<<num));
	}
	return 0;
}