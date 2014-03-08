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
const int N   = 2000000;
const int M   = 1100000;
const int inf = 2000000000;
typedef long long LL;

int joseph(int n,int k){
	int ret=-1,i;
	for (i=1;i<=n;i++)
		ret=(ret+k)%i;
	return ret+1;
}
int main(){
	int n,m;
	while( scanf("%d%d", &n, &m)&&(n+m) ){
		printf("%d %d %d\n", n, m, joseph(n,m));
	}
	return 0;
}