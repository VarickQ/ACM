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
typedef __int64 ll;
const int inf = 2000000000;
const int M   = 100000;
const int N   = 10000;

bool su[M];
int prime[N],cnt;
void getprime(){
	su[1] = su[0] = true;
	for(ll i=2 ; i <= M-10 ; i++)
		if(!su[i]){
			for(ll j=i*i ; j <= M-10 ; j+=i)
				su[j] = true;
		}
	cnt = 0;
	for(int i=2 ; i <= M-10 ; ++i)
		if(!su[i]) prime[cnt++] = i;
}
bool check( char ch ){
	if( ch <= '9' && ch >='0') return true;
	return false;
}
char str[N];
int res[N],col[N];
int main(){
	getprime();
	int i,j,ans,num;
	while( gets( str ) ){
		if( str[0] == '0' ) break;
		ans = 1;
		i = j = 0;
		while( str[i] ){
			num = 0;
			while( check( str[i] ) ){
				num = num*10+str[i]-'0';
				i++;
			}
			i++;
			int t,temp = 0;
			while( check( str[i] ) ){
				temp = temp*10+str[i]-'0';
				i++;
			}
			i++;
			t = 1;
			for( j=0 ; j < temp ; ++j )
				t *= num;
			ans *= t;
		}
		ans--;
		j = 0;
		for( i=0 ; i < cnt && ans >= prime[i] ; ++i){
			bool f = false;
			while( ans%prime[i] == 0 ){
				res[j] = prime[i];
				ans /= prime[i];
				col[j]++;
				f = true;
			}
			if( f ) j++;
		}
		for( i=j-1 ; i > 0 ; --i )
			printf("%d %d ",res[i],col[i]);
		printf("%d %d\n",res[0],col[0]);
		memset( str, '\0', sizeof( str ) );
		memset( res, 0, sizeof( res ) );
		memset( col, 0, sizeof( col ) );
	}
	return 0;
}