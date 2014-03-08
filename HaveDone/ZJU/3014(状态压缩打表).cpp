#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-5;
const int inf = 2000000000;
const int M   = 10000;
const int N   = 2010;
typedef long long LL;
const int S = 20;
vector<LL> factor;

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
		if(a>=c)
			a -= c;
		b >>= 1;
	}
	return ret;
}

LL pow_mod(LL x, LL n, LL mod){ //返回x^n mod c ,非递归版
	if(n==1)
		return x%mod;
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
	if(ret!=1)
		return 1;
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
	if(!flag||n==2)
		return 0;
	return 1;
}
LL gao(int len){
	LL num1, num2, k, ans = -1;
	for(int s=(1<<len)-1 ; s >= 0 ; --s){
		num1 = 0, k = 1;
		for(int j=0 ; j < len ; ++j){
			if( s&(1<<j) ){
				num1 += k*j;
				k *= len;
			}
		}
		num2 = 0, k = 1;
		for(int j=len-1 ; j >= 0 ; --j){
			if( s&(1<<j) ){
				num2 += k*j;
				k *= len;
			}
		}
		if( num1 <= 1 || num2 <= 1 ) continue;
		if( !Miller_Rabin(num1) && !Miller_Rabin(num2) )
			ans = max(ans,num1);
	}
	return ans;
}
char ret[20][20]={"",""
,"not special"
,"21"
,"31"
,"43"
,"5421"
,"5431"
,"76531"
,"765421"
,"9875321"
,"9876421"
,"BA98765421"
,"BA8765431"
,"DCBA9654321"
,"EDCBA8765432"
,"FEDCBA8765431"};
int main(){
	//srand(time(NULL));
	int n;
	////while( scanf("%d", &n) != EOF ){
	//for( n=2 ; n <= 16 ; ++n ){
	//	if( n == 2 ) puts("not special");
	//	else {
	//		int res[20], cnt = 0;
	//		LL ans = gao(n);
	//		while( ans ){
	//			res[cnt++] = ans%n;
	//			ans /= n;
	//		}
	//		printf(",\"");
	//		for(int i=cnt-1 ; i >= 0 ; --i)
	//			printf("%X", res[i]);
	//		printf("\"\n");
	//	}
	//}
	while( scanf("%d", &n) != EOF ){
		printf("%s\n", ret[n]);
	}
	return 0;
}