#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
const int N = 205;
typedef __int64 LL;

LL a[N], b[N*N], c[N*N];
int main(){
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);

		for(int i=0 ; i < n ; ++i)
			scanf("%I64d", &a[i]);
		LL in;
		int cnt1 = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%I64d", &in);
			for(int j=0 ; j < n ; ++j)
				b[cnt1++] = in + a[j];
		}
		sort( b, b+cnt1 );
		cnt1 = unique( b, b+cnt1 ) - b;
		
		for(int i=0 ; i < n ; ++i)
			scanf("%I64d", &a[i]);
		int cnt2 = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%I64d", &in);
			for(int j=0 ; j < n ; ++j)
				c[cnt2++] = in + a[j];
		}
		sort( c, c+cnt2 );
		cnt2 = unique( c, c+cnt2 ) - c;

		for(int i=0 ; i < n ; ++i)
			scanf("%I64d", &a[i]);
		bool f = false;
		for(int i=0 ; i < n ; ++i){
			int j = 0, k = cnt2-1;
			while( j < cnt1 && k >= 0 ){
				LL tmp = b[j]+c[k]+a[i];
				if( tmp == 0 ){
					f = true; break;
				}
				if( tmp > 0 ) k--;
				if( tmp < 0 ) j++;
			}
			if( f ) break;
		}
		if( f ) puts("Yes");
		else puts("No");
	}
	return 0;
}