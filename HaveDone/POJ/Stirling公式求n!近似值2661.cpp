#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define PI 3.1415926535897932384626433832795
#define E  2.718281828

int c[25];
int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int n,i;
	c[0] = 1;
	for( i=1 ; i <= 23 ; ++i )
		c[i] = (1<<i);
	while( scanf("%d", &n) && n ){
		n = (n-1960)/10+2;
		for( i=3 ; ; ++i ){
			double log2n = 0.5*log(2*PI*i)+i*log(i/E);
			log2n = log2n/log(2.0);
			if( log2n > c[n]+0.0 )
				break;
		}
		printf("%d\n", i-1);
	}
    return 0;
}