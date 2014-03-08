//4203 ²©ÞÄ£¬ÕÒ¹æÂÉ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 ll;

int main () {
	int T, s, k;
	scanf ("%d", &T);
	while (T --) {
		scanf("%d%d", &s, &k);
		if( k&1 ){
			if( s&1 ) printf("1\n");
			else printf("0\n");
		} else {
			if( s < k ) printf("%d\n", s%2);
			else {
				if( s%(k+1) == k ) printf("%d\n", k);
				else printf("%d\n", (s%(k+1))%2);
			}
		}
	}
	return 0;
}