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
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 50;
typedef long long LL;

int a[N],b[N],ans[N];
bool cmp(int a,int b){
	if( a%10 != b%10 ) return a%10 < b%10;
	return a < b;
}
bool cmpp(int a,int b){
	return a > b;
}
int main(){
	int T,n1,n2;
	scanf("%d", &T);
	while( T-- ){
		memset( a, 0, sizeof( a ) );
		memset( b, 0, sizeof( b ) );
		scanf("%d%d", &n1, &n2);

		for(int i=0 ; i < n1 ; ++i) scanf("%d", &a[i]);
		sort( a, a+n1, cmpp );
		n1 = unique( a, a+n1 ) - a;

		for(int i=0 ; i < n2 ; ++i) scanf("%d", &b[i]);
		sort( b, b+n2, cmpp );
		n2 = unique( b, b+n2 ) - b;

		int pos = -1, mx = 0;
		for(int i=0 ; i < n1 ; ++i){
			for(int j=0 ; j < n2 ; ++j){
				int len = 0;
				for(int k=0 ; i+k<n1 && j+k<n2; ++k){
					if( a[i+k] == b[j+k] )
						len++;
					else break;
				}
				if( len > mx ){
					mx = len;
					pos = i;
				}
			}
		}
		if( pos == -1 ){
			printf("NONE\n"); continue;
		}
		int cnt = 0;
		for(int i=pos ; i < pos+mx ; ++i)
			ans[cnt++] = a[i];
		sort( ans, ans+cnt, cmpp );
		for(int i=0 ; i < cnt-1 ; ++i) printf("%d ", ans[i]);
		printf("%d\n", ans[cnt-1]);

		sort( ans, ans+cnt, cmp);
		for(int i=0 ; i < cnt-1 ; ++i) printf("%d ", ans[i]);
		printf("%d\n", ans[cnt-1]);
	}
	return 0;
}