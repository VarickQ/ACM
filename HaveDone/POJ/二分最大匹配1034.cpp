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
#define PI acos(-1.0)
typedef long long LL;
#define EPS 1e-8
const int N = 505;

struct point{
	int x,y;
}a[N],b[N];
int mat[N][N], match[N], n, m;
bool vis[N];
bool find(int i){
	for(int j=1 ; j <= m ; ++j){
		if( mat[i][j] && !vis[j] ){
			vis[j] = true;
			if( match[j]==0 || find(match[j]) ){
				match[j] = i;
				return true;
			}
		}
	}
	return false;
}
double dis(point a,point b){
	return sqrt(0.0+(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	while( scanf("%d%d", &n, &m) != EOF ){
		memset( mat, 0, sizeof( mat ) );
		for(int i=1 ; i <= n ; ++i)
			scanf("%d%d", &a[i].x, &a[i].y);
		for(int i=1 ; i <= m ; ++i)
			scanf("%d%d", &b[i].x, &b[i].y);
		for(int i=1 ; i <= n-1 ; ++i){
			for(int j=1 ; j <= m ; ++j){
				double d1 = dis(a[i],b[j])+dis(b[j],a[i+1]);
				double d2 = dis(a[i],a[i+1]);
				if( 2.0*d2 > d1-EPS )
					mat[i][j] = 1;
			}
		}
		memset( match, 0, sizeof( match ) );
		int res = 0;
		for(int i=1 ; i <= n-1 ; ++i){
			memset( vis, 0, sizeof( vis ) );
			if( find(i) ) res++;
		}
		printf("%d\n%d %d", n+res, a[1].x, a[1].y);
		for(int i=1 ; i <= n-1 ; ++i){
			for(int j=1 ; j <= m ; ++j)
				if( match[j] == i ){
					printf(" %d %d", b[j].x, b[j].y);
					break;
				}
			printf(" %d %d", a[i+1].x, a[i+1].y);
		}
		puts("");
	}
	return 0;
}