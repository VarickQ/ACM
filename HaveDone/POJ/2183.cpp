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
#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int inf = 2000000000;
const int M = 100000;
const int N = 100;

int num[N];
int main(){
	int n,i,j;
	while(scanf("%d",&n) == 1){
		memset(num,0,sizeof(num));
		bool f = false;
		for(i=0 ; ; ++i){
			n = (n/10)%10000;
			n = (n*n)%1000000;
			num[i] = n;
			for(j=0 ; j < i ; ++j)
				if(num[j] == n){
					f = true; break;
				}
			if(f) break;
		}
		printf("%d %d %d\n",num[i],i-j,i+1);
	}
	return 0;
}