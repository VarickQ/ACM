//A by Varick_Q
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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 105;
const int N   = 105;
typedef long long ll;

int main(){
	int n;
	char str[N],ans[N];
	while( scanf("%d %s", &n, str) != EOF ){
		if( n==0 && str[0]=='0' ) break;
		int i,k=0;
		for( i=0 ; str[i] ; ++i )
			if( str[i] != n+'0' )
				ans[k++] = str[i];
		for( i=0 ; ans[i] ; ++i )
			if( ans[i] != '0' ) break;
		if( i < k ){
			for( ; i < k ; ++i )
				printf("%c", ans[i]);
			printf("\n");
		} else printf("0\n");
	}
	return 0;
}