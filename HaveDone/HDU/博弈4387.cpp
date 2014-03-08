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
const int N   = 110;
const int M   = 1010;
typedef __int64 LL;

int main(){
	int n,k,cs=1;
	while( scanf("%d%d", &n, &k) != EOF ){
		printf("Case %d: ", cs++);
		if( k==1 ){
			if(n&1) printf("Bob\n");
			else printf("Alice 1\n");
		} else {
			if( n == 2*k+1 ) printf("Alice %d\n",k);
			else printf("Alice 1\n");
		}
	}
	return 0;
}