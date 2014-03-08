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
const int inf = 1000000000;
const int N = 100005;
typedef long long ll;

ll num[N],d[N],n;
int main(){
	int T,cs=1;
	scanf("%d", &T);
	while( T-- ){
		scanf("%lld", &n);
		ll a, x, len = 0;
		CLR( num, 0 );
		CLR( d, 0 );
		for(ll i=0 ; i < n ; ++i){
			scanf("%lld%lld", &a, &x);
			num[a] += x;
			len = max(a,len);
		}
		for(ll i=0 ; i < len ; ++i){
			if( num[i] >= 2 ){
				num[i+1] += num[i]/2;
				num[i] %= 2;
				d[i+1] = 1;//第i+1个位置有水分
			}
		}
		ll pos = 0;
		for(ll i=len ; i >= 0 ; --i){
			if( num[i]%2 == 0 ){
				num[i] = 0; continue;//为偶数时平分
			}
			if( d[i] == 0 ){//无水分
				num[i] = 1;
				pos = i; break;
			} else {
				num[i-1] += 2; //有水分，分到下面一份，其余平分
				num[i] = 0;
			}
		}
		printf("Case #%d: ", cs++);
		if( pos == 0 ) printf("%lld\n", num[0]%2);
		else {
			ll st;
			for(ll i=0 ; i <= pos ; ++i)
				if( num[i] != 0 ) {
					st = i; break;
				}
			if( pos > st ){
				num[pos] = 0;
				for(ll i=pos-1 ; i >= st ; --i){
					if( num[i] == 0 ) num[i] = 1;
					else {
						num[i] = 0;
						if( i == st ) num[i] = 1;
					}
				}
			}
			for(ll i=pos ; i >= 0 ; --i)
				if( num[i] != 0 ){
					st = i; break;
				}
			for(ll i=st ; i >= 0 ; --i )
				printf("%lld", num[i]);
			printf("\n");
		}
	}
	return 0;
}