#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <time.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 65;
typedef __int64 LL;

int a[N];
int main(){
	LL n;
	int T, cs = 1, l, r;
	scanf("%d", &T);
	while( T-- ){
		for(int i=0 ; i < 52 ; ++i)
			scanf("%d", &a[i]);
		scanf("%I64d%d%d", &n, &l, &r);
		printf("Case #%d:", cs++);
		n = n*(l-1);
		n %= r;
		for(int i=n ; i < r ; ++i)
			printf(" %d", a[i]);
		for(int i=0 ; i < n ; ++i)
			printf(" %d", a[i]);
		for(int i=r ; i < 52 ; ++i)
			printf(" %d", a[i]);
		printf("\n");
	}
	return 0;
}