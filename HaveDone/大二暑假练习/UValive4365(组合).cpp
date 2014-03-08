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
const int N   = 15;
const int M   = 1100000;
const int inf = 2000000000;
typedef long long LL;

LL c[N][N];
void CC(){
	for(int i=0; i<N; i++)
		c[0][i] = 1;
	for(int i=1; i<N; i++)
		for(int j=i; j<N; j++)
			c[i][j] = c[i-1][j-1]+c[i][j-1];
}
int main(){
	CC();
	int a,b;
	while( scanf("%d%d", &a, &b) != EOF ){
		if( a==-1 && b==-1 ) break;
		LL ans = c[a][a+b];
		printf("%d+%d",a,b);
		if( a+b == ans ) printf("=%d\n",a+b);
		else printf("!=%d\n",a+b);
	}
	return 0;
}