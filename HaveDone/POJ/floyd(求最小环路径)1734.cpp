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
typedef long long LL;
const int inf = 100000000;
const int N = 105;

int a[N][N], b[N][N], pre[N][N], ans[N];
int main(){
	int n, m, u, v, c;
	while( scanf("%d%d", &n, &m) != EOF ){
		for(int i=1 ; i <= n ; ++i){
			for(int j=1 ; j <= n ; ++j){
				a[i][j] = b[i][j] = inf;
				pre[i][j] = i;
			}
			a[i][i] = b[i][i] = 0;
		}
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &u, &v, &c);
			if( a[u][v] > c )
				a[u][v] = a[v][u] = b[u][v] = b[v][u] = c;
		}
		int Min = inf, cnt;
		for(int k=1 ; k <= n ; ++k){
			for(int i=1 ; i < k ; ++i)
				for(int j=i+1 ; j < k ; ++j)
					if( Min > a[i][j]+b[j][k]+b[k][i] ){
						Min = a[i][j]+b[j][k]+b[k][i];
						cnt = 0;
						for(int s=i,t=j;s!=t;t=pre[s][t])
							ans[cnt++] = t;
						ans[cnt++] = i;
						ans[cnt++] = k;
					}
			for(int i=1 ; i <= n ; ++i)
				for(int j=1 ; j <= n ; ++j)
					if( a[i][j] > a[i][k]+a[k][j] ){
						a[i][j] = a[i][k]+a[k][j];
						pre[i][j] = pre[k][j];
					}
		}
		if( Min == inf ) puts("No solution.");
		else {
			for(int i=0 ; i < cnt-1 ; ++i)
				printf("%d ", ans[i]);
			printf("%d\n", ans[cnt-1]);
		}
	}
	return 0;
}