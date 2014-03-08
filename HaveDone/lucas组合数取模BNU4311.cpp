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
typedef long long ll;
const int M = 105555;
const int N = 121;

ll n,m,p;
ll sPow(ll x,ll n,ll p){
	ll sum=1;
	while(n){
		if(n&1) sum=(sum%p)*(x%p)%p;
		x = (x%p)*(x%p)%p;
		n >>= 1;
	}
	return sum%p;
}

ll C(ll n,ll r,ll p){
	ll i,res=1,t;
	for(i=1 ; i <= r ; i++){
		res = (res%p)*((n-i+1)%p)%p;
		t = sPow(i,p-2,p);
		res = (res%p)*(t%p)%p;
	}
	return res;
}

ll com_mod(ll n,ll r,ll p){
	if(n<r)	return 0;
	return C(n,r,p);
}

ll lucas(ll n,ll m,ll p){
	ll res = 1;
	while(n&&m&&res){
		res = res*com_mod(n%p,m%p,p)%p;
		n /= p;
		m /= p;
	}
	return res;
}

int main(){
	while(scanf("%lld%lld",&n,&m) != EOF){
		printf("%lld\n", lucas(n,m,2));
	}
	return 0;
}