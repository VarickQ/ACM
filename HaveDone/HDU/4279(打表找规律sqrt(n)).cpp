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

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int f[110];
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\Qian\\Desktop\\in.txt","r",stdin);
	freopen("C:\\Users\\Qian\\Desktop\\out.txt","w",stdout);
#endif
////////////////////////////////////////
	for(int n=1 ; n <= 100 ; ++n){
		int cnt = 0;
		for(int i=1 ; i <= n ; ++i)
			if( n%i && gcd(n,i)!=1 )
				cnt++;
		f[n] = cnt;
	}
	for(int n=1 ; n <= 100 ; ++n){
		int cnt = 0;
		for(int i=1 ; i <= n ; ++i)
			if( f[i]&1 ) cnt++;
		printf("%d:\t%d\n", n, cnt);
	}
	return 0;
}

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

LL gao(LL n){
	if( n < 6 ) return 0;
	LL tmp = (LL)sqrt(n*1.0);
	if( tmp&1 ) return (n-4)/2+1;
	else return (n-4)/2;
}
int main(){
	int T;
	LL x, y;
	scanf("%d", &T);
	while( T-- ){
		scanf("%I64d%I64d", &x, &y);
		printf("%I64d\n", gao(y)-gao(x-1));
	}
	return 0;
}