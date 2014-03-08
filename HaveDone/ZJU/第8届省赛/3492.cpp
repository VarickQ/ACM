#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
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
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 20010;
const int N   = 105;
typedef long long LL;


char s[30], str[N][30];
int main(){
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%s", &n, s);
		int pos = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%s", str[i]);
			if( strcmp(str[i],s) == 0 )
				pos = i;
		}
		printf("%s\n", str[(pos+n/2)%n]);
	}
	return 0;
}