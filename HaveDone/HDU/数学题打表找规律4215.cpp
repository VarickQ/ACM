#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-10;
const int inf = 3;
const int M = 6050000;
const int N = 10000;

//int gcd(int a,int b){
//	return b?gcd(b,a%b):a;
//}
//int sf[N],se[N];
//int F(int x){
//	int cnt = 0;
//	for(int i=1 ; i <= x ; ++i)
//		if( gcd(x,i) == 1 )
//			cnt++;
//	return cnt;
//}
//int E(int x){
//	int cnt = 0;
//	for(int i=1 ; i <= x ; ++i)
//		if( x%i == 0 )
//			cnt++;
//	return cnt;
//}
int res[30]={1,1,2,2,4,5,5,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,9,9,9,9,9,9};
int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	/*for(int i=1 ; i <= 100 ; ++i){
		sf[i] = sf[i-1]+F(i);
		se[i] = se[i-1]+E(i);
	}
	for(int n=1 ; n <= 100 ; ++n){
		int cnt = 0;
		for(int i=1 ; i <= n ; ++i)
			for(int j=i ; j <= n ; ++j)
				if( sf[j]-sf[i-1] == se[j]-se[i-1] )
					cnt++;
		printf("%d,",cnt);
	}*/
	int T, cs = 0,n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("Case %d: ", ++cs);
		if( n>=30 ) puts("10");
		else printf("%d\n",res[n-1]);
	}
	return 0;
}