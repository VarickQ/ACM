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
const int N   = 200005;

char str[N],s[N];
int next[N],num[N];
void Next( char *str ){
	int i = 0, j = -1;
	next[0] = -1;
	while( str[i] ){
		if( j == -1 || str[i] == str[j] )
			++i, ++j, next[i] = j;
		else j = next[j];
	}
}
int main(){
	int T,len,ans;
	scanf("%d", &T);
	while( T-- ){
		memset( num, 0, sizeof( num ) );
		scanf("%d", &len);
		scanf("%s", str);
		Next( str );
		for(int i=len ; i >= 1 ; --i){
			num[i]++;
			num[next[i]] += num[i];
		}
		ans = 0;
		for(int i=1 ; i <= len ; ++i)
			ans = (ans+num[i])%10007;
		printf("%d\n", ans);
	}
	return 0;
}