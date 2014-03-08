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
const int N   = 35;
//typedef long long ll;

int a[N][15],d[N],n,res[N];
bool mat[N][N];

int dp( int i ){
	if( d[i] > 0 ) return d[i];
	d[i] = 1;
	for(int j=0 ; j < n ; ++j){
		if( mat[i][j] ){
			int temp = dp(j)+1;
			d[i] = d[i]<temp?temp:d[i];
		}
	}
	return d[i];
}
int s;
void getAns( int i ){
	res[s++] = i+1;
	for(int j=0 ; j < n ; ++j)
		if( mat[i][j] && d[i]==d[j]+1){
			getAns( j ); break;
		}
}
int main(){
	int m;
	while( scanf("%d%d", &n, &m) == 2 ){

		for(int i=0 ; i < n ; ++i){
			for(int j=0 ; j < m ; ++j)
				scanf("%d", &a[i][j]);
			sort( a[i], a[i]+m );
		}

		memset( mat, false, sizeof( mat ) );
		for(int i=0 ; i < n ; ++i){
			for(int j=0 ; j < n ; ++j){
				bool f = false;
				for(int k=0 ; k < m ; ++k)
					if( a[i][k] >= a[j][k] ){
						f = true; break;
					}
				if( !f ) mat[j][i] = true;
			}
		}

		memset( d, 0, sizeof( d ) );
		for(int i=0 ; i < n ; ++i)
			dp(i);

		int ans = 0,pos = -1;
		for(int i=0 ; i < n ; ++i){
			if( d[i] > ans ){
				ans = d[i];
				pos = i;
			}
		}
		printf("%d\n", ans);
		s = 0;
		getAns( pos );
		for(int i=s-1 ; i > 0 ; --i)
			printf("%d ", res[i]);
		printf("%d\n", res[0]);
	}
	return 0;
}