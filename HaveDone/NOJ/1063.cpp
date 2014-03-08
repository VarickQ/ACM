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
const int M = 33000;
const int N = 5000;
typedef long long LL;

bool su[M];
int prime[N],cnt;
void S(){
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
	S();
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		printf("%d=", n);
		int num, i, f = 0;
		for( i=0 ; i < cnt ; ++i ){
			num = 0;
			while( n%prime[i] == 0 ){
				n /= prime[i];
				num++;
			}
			if( num == 0 ) continue;
			if( n > 1 ){
				f = 1;
				if( num == 1 )printf("%d*", prime[i]);
				else printf("(%d^%d)*",prime[i], num);
			} else break;
		}
		if( num == 1 ) printf("%d\n", prime[i]);
		else if(f) printf("(%d^%d)\n", prime[i], num);
		else printf("%d^%d\n", prime[i], num);
	}
	return 0;
}