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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 1000005;
typedef long long ll;

bool mark[N];
int a[305];
int main(){
	int T,n,ans;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i )
			scanf("%d", &a[i]);
		for(int i=n ; i < 1000000 ; ++i){
			//memset部分比全部快很多，从TLE到AC
			memset(mark, false, sizeof(bool)*i);
			bool f = false;
			for(int j=0 ; j < n ; ++j){
				if( !mark[a[j]%i] )
					mark[a[j]%i] = true;
				else {
					f = true; break;
				}
			}
			if( !f ){
				ans = i; break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}