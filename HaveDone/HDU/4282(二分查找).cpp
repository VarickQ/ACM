#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef __int64 LL;

LL p[50005][35];
int main(){
	for(int i=1 ; i <= 50000 ; ++i){
		p[i][1] = i;
		for(int j=2 ; j <= 31 ; ++j){
			p[i][j] = p[i][j-1]*i;
			if( p[i][j] > (1LL<<31) ) break;
		}
	}
	int k, a;
	while( scanf("%d", &k) && k ){
		int ans = 0;
		for(int x=1 ; x<=50000 && x<=k ; ++x){
			for(int z=2 ; z <= 31 ; ++z){
				if( p[x][z] == 0 ) break;
				int l = x+1, r = 50000, mid;
				while( l <= r ){
					mid = l+r>>1;
					if( p[mid][z] == 0 ){
						r = mid-1; continue;
					}
					LL tmp = p[x][z]+p[mid][z]+x*mid*z;
					if( tmp == k ){
						ans++; break;
					}
					if( tmp > k ) r = mid-1;
					else l = mid+1;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}