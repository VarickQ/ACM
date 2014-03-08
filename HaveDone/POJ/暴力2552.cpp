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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 3005;
const int M   = 35100;
typedef long long LL;

bool f[M];
int ans[N];
int main(){
	f[1] = true;
	for(int i=2 ; i <= M-100 ; ++i){
		if( !f[i] ){
			int tmp = i;
			for(int j=i+1 ; j <= M-100 ; ++j){
				if( !f[j] ) tmp--;
				if( !tmp ){
					f[j] = true;
					tmp = i;
				}
			}
		}
	}
	int cnt = 0;
	for(int i=2 ; cnt < N-2 && i <= M-100 ; ++i)
		if( !f[i] ) ans[++cnt] = i;
	int n;
	while( scanf("%d", &n) && n )
		printf("%d\n", ans[n]);
	return 0;
}