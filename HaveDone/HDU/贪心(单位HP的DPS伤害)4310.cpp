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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
typedef long long LL;
const int N   = 105;
const int M   = 300000;
const LL inf = 1000000000;

struct Node{
	int dps,hp;
	double dph;
}a[N];
bool cmp(Node a, Node b){
	return a.dph > b.dph;
}
int sum[N];
int main(){
	int n;
	while( scanf("%d", &n) == 1 ){
		CLR( sum, 0 );
		for(int i=1 ; i <= n ; ++i){
			scanf("%d%d", &a[i].dps, &a[i].hp);
			a[i].dph = (a[i].dps+0.0)/a[i].hp;
		}
		sort( a+1, a+n+1, cmp );
		for(int i=n ; i >= 1 ; --i)
			sum[i] = sum[i+1]+a[i].dps;
		int ans = 0;
		for(int i=1 ; i <= n ; ++i)
			ans += sum[i]*a[i].hp;
		printf("%d\n", ans);
	}
    return 0;
}