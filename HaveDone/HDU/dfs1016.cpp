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
const int N   = 20;

int a[22],n,vis[22];
bool su(int n){
	int i;
	for(i=2 ; i*i <= n ; ++i)
		if( n%i == 0 ) break;
	if( i*i > n ) return true;
	return false;
}
void dfs( int c ){
	if( c==n && su(a[0]+a[n-1]) ){
		for(int i=0 ; i < n-1 ; ++i)
			printf("%d ", a[i]);
		printf("%d\n", a[n-1]);
	} else {
		for(int i=2 ; i <= n ; ++i)
			if( !vis[i] && su(a[c-1]+i)){
				a[c] = i;
				vis[i] = 1;
				dfs( c+1 );
				vis[i] = 0;
			}
	}
}
int main(){
	int cs=1;
	while(scanf("%d", &n) == 1){
		printf("Case %d:\n", cs++);
		a[0] = 1;
		memset( vis, 0, sizeof( vis ) );
		dfs( 1 );
		printf("\n");
	}
	return 0;
}