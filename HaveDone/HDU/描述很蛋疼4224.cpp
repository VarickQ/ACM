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
const int N = 100050;

int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
    int T, cs = 0;
	int x,y;
    scanf("%d", &T);
    while (T--) {
		bool f1 = false,f2 = false,f = false;
		for(int i=0 ; i < 3 ; ++i){
			scanf("%d%d", &x, &y);
			if( x > y ) f1 = true;
			if( x < y ) f2 = true;
			if( x != y ) f = true;
		}
		printf("Case %d: ", ++cs);
		if( !f || (f1 & f2) ) printf("Yes\n");
		else printf("No\n");
    }
    return 0;
}