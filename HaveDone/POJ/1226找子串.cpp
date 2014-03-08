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

char str[102][102],l[102];
int main(){
	int T,n,Min,len;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		len = inf;
		for(int i=0 ; i < n ; ++i){
			scanf("%s", str[i]);
			if( len > strlen(str[i]) ){
				len = strlen(str[i]);
				Min = i;
			}
		}
		strcpy( l, str[Min] );
		int p,ans = len;
		char t1[105],t2[105];
		bool f = false;
		while( 1 ){
			for(int i=0 ; i <= len-ans ; ++i){
				strncpy( t1, l+i, ans );
				t1[ans] = '\0';
				for(int j=0 ; j < ans ; ++j)
					t2[j] = t1[ans-j-1];
				t2[ans] = '\0';
				p = 0;
				for(int j=0 ; j < n ; ++j){
					if( strstr( str[j], t1 ) || strstr( str[j], t2 ) ){
						p++;
					}else break;
				}
				if( p==n ) break;
			}
			if( p==n ) break;
			ans--;
		}
		printf("%d\n", ans);
	}
	return 0;
}