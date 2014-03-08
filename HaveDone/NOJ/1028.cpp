#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;
#define ll long long
const int M = 1000005;
const int N = 10000;
const ll inf = (1LL)<<60;

bool su[M];
ll prime[N];
int cnt;
void PrimeList(){
	su[1] = su[0] = true;
	for(ll i=2 ; i <= M-5 ; i++)
		if(!su[i]){
			for(ll j=i*i ; j <= M-5 ; j+=i)
				su[j] = true;
		}
	cnt = 0;
	for(int i=2 ; i <= M-5 ; ++i)
		if(!su[i]) prime[cnt++] = i;
}

int main(){
	ll n;
	PrimeList();
	while(scanf("%lld",&n) == 1){
		if(n < 0) break;
		for(int i=0 ; i < cnt ; ++i){
			if(n%prime[i] == 0){
				while(n%prime[i] == 0){
					printf("%lld\n",prime[i]);
					n /= prime[i];
				}
			}
		}
		if(n!=1) printf("%lld\n",n);
		printf("\n");
	}
	return 0;
}