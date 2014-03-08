#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long LL;
const int N = 1010;

int main(){
	char s[N];
	LL a, b;
	while( scanf("%s", s) != EOF ){
		scanf("%lld%lld", &a, &b);
		LL num, pre = 0;
		int sign, i;
		for( i=0 ; s[i] ; ++i ){
			if( s[i]<'0' || s[i]>'9' ) break;
			else pre = pre*10+s[i]-'0';
		}
		if( s[i++] == '+' ) sign = 1;
		else sign = 0;
		num = 0;
		for( ; s[i] ; ++i ){
			if( s[i]<'0' || s[i]>'9' ){
				if( sign == 1 )
					pre += num;
				else pre -= num;
				num = 0;
				sign = (s[i]=='+')?1:0;
			}
			else num = num*10+s[i]-'0';
		}
		if(sign == 1) pre += num;
		else pre -= num;
		if( a == 9 || pre == b ) puts("A");
		else if( b == 9 || pre == a ) puts("B");
	}
	return 0;
}
