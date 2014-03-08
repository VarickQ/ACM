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

int sum[N][N];
struct point{
	int x,y;
}a[N],g[M];
bool cmp(point a,point b){
	if( a.x == b.x ) return a.y < b.y;
	return a.x < b.x;
}
LL xmul(point p0,point p1,point p2){//!!
	return (LL)(p1.x-p0.x)*(p2.y-p0.y)-(LL)(p2.x-p0.x)*(p1.y-p0.y);
}
int main(){
	int n,m,cs=1;
	while( scanf("%d%d", &n, &m) != EOF )
	{
		memset( sum, 0, sizeof( sum ) );
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d", &a[i].x, &a[i].y);
		for(int i=0 ; i < m ; ++i)
			scanf("%d%d", &g[i].x, &g[i].y);
		sort(a,a+n,cmp);
		for(int i=0 ; i < n ; ++i)
			for(int j=i+1 ; j < n ; ++j)
				for(int k=0 ; k < m ; ++k)
					if( g[k].x>=a[i].x && g[k].x<=a[j].x && xmul(a[i],a[j],g[k])>0 )
						sum[i][j]++;
		int ans = 0;
		for(int i=0 ; i < n ; ++i)
			for(int j=i+1 ; j < n ; ++j)
				for(int k=j+1 ; k < n ; ++k){
					int tmp = abs(sum[i][k]-sum[i][j]-sum[j][k]);
					if( tmp&1 ) ans++;
				}
		printf("Case %d: %d\n", cs++, ans);
	}
	return 0;
}