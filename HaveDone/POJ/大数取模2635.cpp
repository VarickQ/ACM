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
const int inf = 1000000000;
const int M = 1000200;
const int N = 1000005;
typedef long long ll;

int num[110],len;
bool su[M];
int prime[N],cnt;
void getprime(){
	su[1] = su[0] = true;
	for(ll i=2 ; i <= M-100 ; i++)
		if(!su[i]){
			for(ll j=i*i ; j <= M-100 ; j+=i)
				su[j] = true;
		}
	cnt = 0;
	for(int i=2 ; i <= M-100 ; ++i)
		if(!su[i]) prime[cnt++] = i;
}

int Mod( int M ){
	ll ans = 0;
	for(int i=len ; i >= 0 ; --i)
		ans = (ans*1000000000+num[i]) % M;
	return (int)ans;
}
int main(){
	char K[110];
	int l,k,i;
	getprime();
	while( scanf("%s%d", K, &l) != EOF ){
		if( K[0]=='0' && l==0 ) break;
		memset( num, 0, sizeof( num ) );
		len = 0;
		for( k=1,i=strlen(K)-1 ; i >= 0 ; --i,k*=10 ){
			if( k == 1000000000 ){
				k = 1; len++;
			}
			num[len] += (K[i]-'0')*k;
		}
		bool f = false;
		for( i=0 ; i < cnt && prime[i] < l ; ++i){
			if( Mod( prime[i] ) == 0 ){
				f = true; break;
			}
		}
		if( f ) printf("BAD %d\n", prime[i]);
		else printf("GOOD\n");
	}
	return 0;
}