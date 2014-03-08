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

int a[10];
int get(int sum){
	int ret = 0;
	for(int i=0 ; i < 5 ; ++i)
		for(int j=i+1 ; j < 5 ; ++j)
			for(int k=j+1 ; k < 5 ; ++k){
				if( (a[i]+a[j]+a[k])%1024 == 0 ){
					int tmp = sum-(a[i]+a[j]+a[k]);
					if( tmp%1024==0 && tmp>0 ) tmp = 1024;
					else tmp %= 1024;
					if( tmp > ret ) ret = tmp;
				}
			}
	return ret;
}
int main(){
	int n, sum, ans;
	while( scanf("%d", &n) != EOF ){
		memset( a, 0, sizeof( a ) );
		sum = ans = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &a[i]);
			if( a[i] > 2012 ) a[i] = 2012;
			sum += a[i];
		}
		if( n < 4 ){
			printf("1024\n");
			continue;
		}
		int res;
		if( n == 4 ){
			for(int x=0 ; x <= 2012 ; ++x){
				sum -= a[4];
				a[4] = x;
				sum += a[4];
				res = get( sum );
				if( res > ans ) ans = res;
			}
		} else {
			res = get( sum );
			if( res > ans ) ans = res;
		}
		printf("%d\n", ans );
	}
	return 0;
}
