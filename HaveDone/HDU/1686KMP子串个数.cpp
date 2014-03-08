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
const int N   = 1000005;

char cs[N],str[10005];
int next[10005];
void Next(){
	int i = 0, j = -1;
	next[0] = -1;
	while( str[i] ){
		if( j == -1 || str[i] == str[j] )
			++i, ++j, next[i] = j;
		else j = next[j];
	}
}
void KMP(){
	int i = 0, j = 0;
	int s1 = strlen( cs );
	int s2 = strlen( str );
	int ans = 0;
	while( cs[i] ){
		while( i < s1 && j < s2 ){
			if( j == -1 || cs[i] == str[j] )
				++i, ++j;
			else j = next[j];
		}
		if( j >= s2 ){
			ans++;
			j = next[j];
		}
	}
	printf("%d\n", ans );
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%s %s", str, cs);
		Next();
		KMP();
	}
	return 0;
}