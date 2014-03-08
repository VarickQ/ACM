#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
typedef long long ll;
const ll inf = 1000000000;
const ll M   = 100000;
const ll N   = 50005;

ll a[N],numa[40],numo[40],numx[40];
ll tmp[40],k;
ll aa,oo,xx;
void change(ll n){
	CLR(tmp, 0 );
	while( n ){
		tmp[k] = n%2;
		n /= 2;
		k++;
	}
}
void add(){
	for(ll i=0 ; i < 31 ; ++i){
		numa[i] += tmp[i];
		numo[i] += tmp[i];
		numx[i] += tmp[i];
	}
	for(ll i=0 ; i < 31 ; ++i){
		aa += numa[i]*(1<<i);
		oo += numo[i]*(1<<i);
		xx += numx[i]*(1<<i);
	}
}
int main(){
	ll T,n,cs=1;
	scanf("%lld", &T);
	while( T-- ){
		scanf("%lld", &n);
		for(ll i=0 ; i < n ; ++i)
			scanf("%lld", &a[i]);
		aa = oo = xx = 0;
		ll fm = (1+n)*n/2;
		CLR( numa, 0 );
		CLR( numo, 0 );
		CLR( numx, 0 );
		k = 0;
		change( a[0] );
		add();
		for(ll i=1 ; i < n ; ++i){
			k = 0;
			change(a[i]);
			for(ll j=0 ; j < 31 ; ++j){
				if( tmp[j] == 0 ){
					numa[j] = 0;
				} else {
					numo[j] = i;
					numx[j] = i-numx[j];
				}
			}
			add();
		}
		printf("Case #%lld: %.6lf %.6lf %.6lf\n",cs++,1.0*aa/fm,1.0*oo/fm,1.0*xx/fm);
	}
	return 0;
}