#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-8;
const int inf = 1000000000;
const int M = 6050000;
const int N = 1000;

char s1[N],s2[N];
int a[30],b[30];
int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T,cs = 1;
	scanf("%d\n", &T);
	while( T-- ){
		CLR( a, 0 );
		CLR( b, 0 );
		gets(s1);
		gets(s2);
		for(int i=0 ; s1[i] ; ++i)
			a[s1[i]-'a']++;
		for(int i=0 ; s2[i] ; ++i)
			b[s2[i]-'a']++;
		int ans = 0;
		for(int i=0 ; i < 30 ; ++i)
			ans += abs(a[i]-b[i]);
		printf("Case #%d:  %d\n", cs++, ans);
	}
    return 0;
}