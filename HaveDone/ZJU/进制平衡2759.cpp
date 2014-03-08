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
const int inf = 1000000000;
const int M   = 400010;
const int N   = 4000;
typedef long long LL;

LL f[N];
int num[N], b[N], ans[N];
int main(){
	int n, cnt;
	f[0] = 1;
	for(int i=1 ; i <= 30 ; ++i)
		f[i] = f[i-1]*3;
	while( scanf("%d", &n) != EOF ){
		memset( num, 0, sizeof( num ) );
		memset( b, 0, sizeof( b ) );
		cnt = 0;
		while( n ) {
			num[cnt++] = n%3;
			n /= 3;
		}
		cnt += 2;
		for(int i=0 ; i < cnt ; ++i){
			if( num[i] == 2 ){
				num[i] = 0;
				num[i+1] ++;
				b[i] = 1;
			}
			else if( num[i] == 3 ){
				num[i] = 0;
				num[i+1] ++;
			}
		}
		int cc = 0;
		for(int i=0 ; i < cnt ; ++i)
			if( b[i] ) cc++;
		if( cc == 0 ) puts("-1");
		else {
			int p=0;
			for(int i=0 ; i < cnt ; ++i)
				if( b[i] == 1 ) ans[p++] = i;
			for(int i=0 ; i < p-1 ; ++i)
				printf("%lld ", f[ans[i]]);
			printf("%lld\n", f[ans[p-1]]);
		}
		cc = 0;
		for(int i=0 ; i < cnt ; ++i)
			if( num[i] ) cc++;
		if( cc == 0 ) puts("-1");
		else {
			int p=0;
			for(int i=0 ; i < cnt ; ++i)
				if( num[i] == 1 ) ans[p++] = i;
			for(int i=0 ; i < p-1 ; ++i)
				printf("%lld ", f[ans[i]]);
			printf("%lld\n", f[ans[p-1]]);
		}
		puts("");
	}
	return 0;
}