#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define Lowbit(x) ((x)&(-x))
const double eps = 1e-10;
const int inf = 1000000000;
const int M   = 200100;
const int N   = 25;
typedef long long LL;

int a[N], n, sum;
bool vis[N], f;
void dfs(int s,int num,int pre){
	if( pre > sum/4 ) return ;
	if( num == 4 ){
		f = true;
		return ;
	}
	for(int i=s ; i < n ; ++i){
		if( !vis[i] ){
			vis[i] = true;
			if( pre+a[i] == sum/4 )
				dfs( 0, num+1, 0 );
			else
				dfs( i+1, num, pre+a[i] );
			if( f ) return ;
			vis[i] = false;
		}
	}
	return ;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		sum = 0;
		f = false;
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if( sum%4 != 0 ){
			puts("no"); continue;
		}
		CLR( vis, 0 );
		dfs(0,0,0);
		if( f ) puts("yes");
		else puts("no");
	}
	return 0;
}