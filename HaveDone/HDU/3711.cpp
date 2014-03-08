#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-10
const int inf = 1000000000;
const int N = 105;

int a[N], b[N];
int gao(int n){
	int cnt = 0;
	while( n ){
		if( n%2 ) cnt++;
		n /= 2;
	}
	return cnt;
}
int main(){
	int T, m, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &m, &n);
		for(int i=0 ; i < m ; ++i)
			scanf("%d", &a[i]);
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &b[i]);
		sort( a, a+m );
		for(int i=0 ; i < n ; ++i){
			int ans = -1, Max = inf;
			for(int j=0 ; j < m ; ++j){
				int tmp = gao( a[j]^b[i] );
				if( tmp < Max ){
					Max = tmp;
					ans = a[j];
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}