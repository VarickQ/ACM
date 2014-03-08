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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 20010;
const int N   = 105;
typedef long long LL;

char s[N], tmp[N];
int ok(char ch){
	if( ch>='0' && ch<='9' )return 1;
	if( ch>='A' && ch<='Z' )return 2;
	if( ch>='a' && ch<='z' )return 3;
	return 0;
}
char carry( char ch ){
	if( ch == '9' )return '0';
	if( ch == 'Z' )return 'A';
	if( ch == 'z' )return 'a';
	return 0;
}
bool noAlpha(char *s){
	int len = strlen( s );
	for(int i=0 ; i < len ; ++i)
		if( ok(s[i]) ) return false;
	return true;
}
int main(){
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%s%d", s, &n);
		int len = strlen( s );
		for(int i=0,j=len-1 ; i < len ; ++i,--j)
			tmp[i] = s[j];
		tmp[len] = '\0';
		for(int i=0 ; i < n ; ++i){
			if( noAlpha(tmp) ) tmp[0]++;
			else {
				bool f = false, c = false;
				for(int j=0 ; j < len ; ++j){
					if( ok(tmp[j]) ){
						if( !f ){
							char t = carry( tmp[j] );
							if( (int)t != 0 ){
								tmp[j] = t; c = true;
							}
							else {
								tmp[j]++; c = false;
							}
							f = true;
						} else {
							if( c ){
								char t = carry( tmp[j] );
								if( (int)t != 0 ){
									tmp[j] = t; c = true;
								}
								else{
									tmp[j]++; c = false;
								}
							}
						}
					}
				}
				if( c ){
					len++;
					for(int j=len-2 ; j >= 0 ; --j){
						int t = ok( tmp[j] );
						if( t != 0 ){
							if( t == 1 ) tmp[j+1] = '1';
							else if( t == 2 ) tmp[j+1] = 'A';
							else if( t == 3 ) tmp[j+1] = 'a';
							break;
						} else {
							tmp[j+1] = tmp[j];
						}
					}
					c = false;
				}
			}
			for(int j=len-1 ; j >= 0 ; --j)
				printf("%c", tmp[j]);
			puts("");
		}
		puts("");
	}
	return 0;
}