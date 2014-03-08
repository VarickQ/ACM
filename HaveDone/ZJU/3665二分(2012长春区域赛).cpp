#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
const int N = 510;
typedef long long LL;

LL myPow(LL x,LL n){
	LL ret = 1;
	for(LL i=0 ; i < n ; ++i)
		ret *= x;
	return ret;
}
int main(){
	LL n;
	while( scanf("%lld", &n) != EOF ){
		LL l, r, mid, ansl=1, ansk=n-1, Max = n-1;
		for(int i=1 ; i <= 40 ; ++i){
			l = 2, r = (LL)pow(n+1.0,1.0/i);
			while( l <= r ){
				mid = (l+r)/2;
				LL tmp = (1-myPow(mid,i))/(1-mid)*mid;
				if( tmp == n || tmp == n-1 ){
					//cout << i << mid << endl;
					if( mid*i < Max ){
						ansl = i; ansk = mid;
						Max = mid*i;
					}
				}
				if( tmp > n ) r = mid-1;
				else l = mid+1;
			}
		}
		printf("%lld %lld\n", ansl, ansk);
	}
	return 0;
}