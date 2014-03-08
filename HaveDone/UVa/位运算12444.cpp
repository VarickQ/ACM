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
const int inf = 1000000000;
const int N = 35;
typedef long long ll;

int a[35],b[35],tmp[35];
int Tento(int n,int a){
	int i = 0;
	while( n ){
		tmp[i++] = n%a;
		n /= a;
	}
	return i;
}
int main(){
	int T,c,d;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &c, &d);
		if( (c|d) != d ) {
			printf("-1\n"); continue;
		}
		int num = ((~c)&d);
		CLR( tmp, 0 );
		int l = Tento(num,2);
		int ans1 = c, ans2 = c;
		for(int i=l ; i >= 0 ; --i)
			if( tmp[i] ){
				ans2 += (1<<i); tmp[i] = 0;
				break;
			}
		for(int i=0 ; i < l ; ++i)
			if( tmp[i] ) ans1 += (1<<i);
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}