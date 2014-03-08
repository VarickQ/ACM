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
const int N   = 50010;
const int M   = 50010;
typedef __int64 LL;
const LL inf = 1LL<<62;

int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\Qian\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\Qian\\Desktop\\out.txt","w",stdout);
#endif
////////////////////////////////////////
	LL n,L,A,B,mod,x,ans,mx,mm;
	while( scanf("%I64d%I64d%I64d%I64d%I64d",&n,&L,&A,&B,&mod)!=EOF ){
		ans = mx = 0;
		mm = inf;
		for(int i=1 ; i <= n ; ++i){
			x = (A*i+B)%mod;
			if( x <= L/2 ){
				ans++;
				mx = max( x, mx );
			}
			else if( x <= L )
				mm = min( x, mm );
		}
		if( mm != inf && mm+mx <= L ) ans++;
		printf("%I64d\n", ans);
	}
	return 0;
}