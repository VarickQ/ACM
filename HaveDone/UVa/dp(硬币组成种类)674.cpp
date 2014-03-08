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
const int inf = 1000000000;
const int M   = 100000;
const int N   = 7500;
//typedef long long ll;

int d[N][5],c[5]={1,5,10,25,50};
int dp( int n,int x ){
	if( d[n][x] >= 0 ) return d[n][x];
	d[n][x] = 0;
	for(int i=x ; i<5 && n>=c[i] ; ++i)
		d[n][x] += dp(n-c[i],i);
	return d[n][x];
}
int main(){
	int n;
	memset( d, -1, sizeof( d ) );
	for(int i=0 ; i <= 4 ; ++i)
		d[0][i] = 1;
	while( scanf("%d", &n) == 1 ){
		printf("%d\n", dp(n,0));
	}
	return 0;
}