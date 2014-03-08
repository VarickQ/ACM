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

ll n,m,p,fac[M];
void init(){
    fac[0] = 1;
    for(int i = 1; i <= p; i++)
        fac[i] = fac[i-1]*i%p;
}
ll pow(ll a,ll b){
    ll tmp = a%p,ans = 1;
    while(b){
        if(b&1)ans=ans*tmp%p;
        tmp=tmp*tmp%p;
        b >>= 1;
    }
    return ans;
}

ll C(ll n,ll m){
    if(m > n) return  0;
    return fac[n]*pow(fac[m]*fac[n-m],p-2)%p;
}

ll Lucas(ll n, ll m){
    if(m == 0) return 1;
    else return (C(n%p, m%p)*Lucas(n/p, m/p))%p;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&p);
		init();
		printf("%lld\n",Lucas(n+m,n));
	}
	return 0;
}