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
#define eps 1e-8
const int inf = 2000000000;
const int M = 10005;
const int N = 1005;

int main(){
	int n,cs=0;
	while(scanf("%d",&n) && n){
		printf("%d. ",++cs);
		n *= 3;
		if(n&1){
			printf("odd ");
			n = (n+1)/2;
		} else {
			printf("even ");
			n /= 2;
		}
		n = (n*3)/9;
		printf("%d\n",n);
	}
	return 0;
}