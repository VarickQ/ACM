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
typedef __int64 ll;
const int inf = 2000000000;
const int N   = 270;

int s[N],a[N];
void search( int n, int x, int k ){
	if( n == 1 ) return ;
	for(int i=1 ; i <= x ; ++i){
		a[2*i-1] = (s[i]+s[i+k])/2;
		a[2*i] = (s[i]-s[i+k])/2;
	}
	for(int i=1 ; i <= x ; ++i){
		s[2*i-1] = a[2*i-1];
		s[2*i] = a[2*i];
	}
	search( n/2, x*2, k*2 );
}
int main(){
	//freopen( "in.txt", "r", stdin );

	int n;
	while( scanf("%d", &n) == 1){
		if(n == 0) break;
		memset( a, 0, sizeof( a ) );
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &s[i]);
		search( n, 1, 1 );
		for(int i=1 ; i < n ; ++i)
			printf("%d ", s[i]);
		printf("%d\n",s[n]);
	}
	return 0;
}