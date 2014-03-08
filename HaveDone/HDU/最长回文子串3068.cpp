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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define _min(x, y) ((x)<(y)?(x):(y))
const int N = 111000;

char str[N*2], s[N];
int p[N*2], n;
void kp(){
    int i, mx = 0, id;
    for( i=1 ; i < n ; i++ ){
        if( mx > i )p[i] = _min( p[2*id-i], p[id]+id-i );
        else p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++);
        if( p[i] + i > mx ){
            mx = p[i] + i;
            id = i;
        }
    }
}
void init(){
	int i, j, k;
	str[0] = '$';
	str[1] = '#';
	for( i=0 ; i < n ; i++ ){
		str[i*2+2] = s[i];
		str[i*2+3] = '#';
	}
	n = n*2+2;
	s[n] = 0;
}
int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	while( scanf("%s", s) != EOF ){
		CLR( str, 0 );
		n = strlen(s);
		init();
		kp();
		int ans = 0;
		for(int i=0 ; i < n ; ++i)
			if( ans < p[i]-1 )
				ans = p[i]-1;
		printf("%d\n", ans);
	}
	return 0;
}