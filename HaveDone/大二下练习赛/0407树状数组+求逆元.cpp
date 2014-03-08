#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 100000;
const int N   = 100005;
typedef long long ll;

ll B,P,l,n;
ll c[N],b[N],nb[N];
ll exGcd( ll a, ll b, ll &x, ll &y ){
	if( b == 0 ){
		x = 1;
		y = 0;
		return a;
	}
	ll d = exGcd( b, a%b, x, y );
	ll temp = x;
	x = y;
	y = temp-(a/b)*y;
	return d;
}
//ll sPow(int x,int n,ll M){
//	ll sum=1;
//	while(n){
//		if(n&1)sum = (sum%M)*(x%M)%M;
//		x = (x%M)*(x%M)%M;
//		n >>= 1;
//	}
//	return sum%M;
//}
ll Lowbit( ll t ){
	return t & (-t);
}
void update( int pos, int num ){
	while( pos <= l ) {
		c[pos] += num;
		pos += Lowbit(pos);
	}
}
ll Sum( int end ){
	ll sum = 0;
	while( end > 0 ){
		sum += c[end];
		end -= Lowbit(end);
	}
	return sum;
}

int main(){
	char ch[2];
	while( scanf("%lld%lld%lld%lld",&B,&P,&l,&n)&&(B+P+l+n)){
		CLR( c, 0 );
		b[l] = 1;
		for(int i=l-1 ; i >= 0 ; --i)
			b[i] = (b[i+1]*B)%P;
		for(int i=0 ; i <= l ; ++i){
			ll x,y;
			//nb[i] = sPow(b[i],P-2,P);//求b[i]的逆元
			exGcd(b[i],P,x,y);//x为b[i]的逆元
			x = (x%P+P)%P;
			nb[i] = x;
		}
		for(int i=0 ; i < n ; ++i){
			scanf("%s", ch);
			ll u, v;
			if( ch[0] == 'E' ){
				scanf("%lld%lld", &u,&v);
				v = (b[u]*v)%P-(Sum(u)-Sum(u-1));
				v = (v+P)%P;
				update( u, v );
			} else {
				scanf("%lld%lld", &u,&v);
				ll ans = (Sum(v)-Sum(u-1))%P;
				ans = (ans+P)%P;
				printf("%lld\n", (ans*nb[v])%P);
			}
		}
		printf("-\n");
	}
	return 0;
}