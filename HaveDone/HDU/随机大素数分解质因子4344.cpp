#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <time.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 20500;
typedef __int64 LL;
const int M   = 10000100;

///////////随机大素数Miller_Rabin&Pollard_rho
const int S = 20;
LL factor[N],fac_top;

LL muti_mod(LL a, LL b, LL c){ //返回(a*b) mod c,a,b,c<2^63
	a %= c;
	b %= c;
	LL ret = 0;
	while(b){
		if(b&1){
			ret += a;
			if(ret>=c)
				ret -= c;
		}
		a <<= 1;
		if(a>=c) a -= c;
		b >>= 1;
	}
	return ret;
}

LL pow_mod(LL x, LL n, LL mod){ //返回x^n mod c ,非递归版
	if(n==1) return x%mod;
	int bit[64], k = 0;
	while(n){
		bit[k++] = n&1;
		n >>= 1;
	}
	LL ret = 1;
	for(k = k-1; k>=0; k--){
		ret = muti_mod(ret, ret, mod);
		if(bit[k]==1)
			ret = muti_mod(ret, x, mod);
	}
	return ret;
}

bool check(LL a, LL n, LL x, LL t){ //以a为基，n-1=x*2^t，检验n是不是合数
	LL ret = pow_mod(a, x, n), last = ret;
	for(int i = 1; i<=t; i++){
		ret = muti_mod(ret, ret, n);
		if(ret==1&&last!=1&&last!=n-1)
			return 1;
		last = ret;
	}
	if(ret!=1) return 1;
	return 0;
}

bool Miller_Rabin(LL n){
	LL x = n-1, t = 0;
	while((x&1)==0)
		x >>= 1, t++;
	bool flag = 1;
	if(t>=1&&(x&1)==1){
		for(int k = 0; k<S; k++){
			LL a = rand()%(n-1)+1;
			if(check(a, n, x, t)){
				flag = 1;
				break;
			}
			flag = 0;
		}
	}
	if(!flag||n==2) return 0;
	return 1;
}

LL gcd(LL a, LL b){
	if(a==0) return 1;
	if(a<0) return gcd(-a, b);
	while(b){
		LL t = a%b;
		a = b;
		b = t;
	}
	return a;
}

LL Pollard_rho(LL x, LL c){
	LL i = 1, x0 = rand()%x, y = x0, k = 2;
	while(1){
		i++;
		x0 = (muti_mod(x0, x0, x)+c)%x;
		LL d = gcd(y-x0, x);
		if(d!=1&&d!=x){
			return d;
		}
		if(y==x0) return x;
		if(i==k){
			y = x0;
			k += k;
		}
	}
}

void findfac(LL n){ //递归进行质因数分解N
	if(n==1) return;
	if(!Miller_Rabin(n)){
		factor[fac_top++] = n;
		return;
	}
	LL p = n;
	while(p>=n)
		p = Pollard_rho(p, rand()%(n-1)+1);
	findfac(p);
	findfac(n/p);
}
////////////////////////
bool su[M];
int prime[N],cnt;
void getprime(){
	su[1] = su[0] = true;
	for(LL i=2 ; i <= M-100 ; i++)
		if(!su[i]){
			for(LL j=i*i ; j <= M-100 ; j+=i)
				su[j] = true;
		}
	cnt = 0;
	for(int i=2 ; i <= M-100 ; ++i)
		if(!su[i]) prime[cnt++] = i;
}
int main(){
	srand(time(NULL));
	getprime();
	int T;
	LL n, ans;
	scanf("%d", &T);
	while( T-- ){
		scanf("%I64d", &n);
		ans = 0;
		int k = 0;
		if( n <= 1000000000 ){
			LL ft,m = (LL)sqrt(1.0*n);
			for(int i=0 ; i<cnt && n>1 && prime[i]<=m ; ++i){
				LL tmp = 1;
				if( n%prime[i] == 0 ){
					k++;
					ft = prime[i];
					while( n%prime[i]==0 ){
						n/=prime[i]; tmp*=prime[i];
					}
				}
				if(tmp!=1) ans += tmp;
			}
			if(k==1)printf("1 %I64d\n", ans/ft);
			else printf("%d %I64d\n", k, ans);
		} else {
			if( !Miller_Rabin(n) ) printf("1 %I64d\n", n);
			else {
				fac_top = 0;
				findfac( n );
				sort( factor, factor+fac_top );
				LL tmp = factor[0];
				k = 1;
				for(int i=1 ; i < fac_top ; ++i){
					if( factor[i] == factor[i-1] )
						tmp *= factor[i];
					else {
						ans += tmp;
						tmp = factor[i];
						k++;
					}
				}
				ans += tmp;
				if( k==1 ) printf("1 %I64d\n", ans/factor[0]);
				else printf("%d %I64d\n", k, ans);
			}
		}
	}
	return 0;
}