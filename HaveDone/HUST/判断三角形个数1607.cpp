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
#define zero(x) (((x)>0?(x):-(x))<eps)
const int inf = 1000000000;
const int M   = 20005;
const int N   = 205;
typedef long long LL;

struct point{
	double x, y;
}a[N];
int mat[N][N], vis[N][N];
double xmult(double x1,double y1,double x2,double y2,double x0,double y0){
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
bool ok(int i,int k,int j){
	return zero(xmult(a[i].x,a[i].y,a[k].x,a[k].y,a[j].x,a[j].y));
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF){
		memset( mat, 0, sizeof( mat ) );
		for (int i = 0; i < n; ++i)
			scanf("%lf%lf", &a[i].x, &a[i].y);
		double x, y, x1, y1;
		for (int i = 0; i < m; ++i){
			scanf("%lf%lf%lf%lf", &x, &y, &x1, &y1);
			int u, v;
			for (int j = 0; j < n; ++j){
				if (fabs(x-a[j].x)<eps && fabs(y-a[j].y)<eps)
					u = j;
				if (fabs(x1-a[j].x)<eps && fabs(y1-a[j].y)<eps)
					v = j;
			}
			mat[u][v] = mat[v][u] = 1;
		}
		for (int k = 0; k < n; ++k){
			for (int i = 0; i < n; ++i){
				if (i == k) continue;
				for (int j = 0; j < n; ++j){
					if (j == i || j == k || mat[i][j]) continue;
					if(ok(i,j,k) && mat[i][k] && mat[k][j])
						mat[i][j] = mat[j][i] = 1;
				}
			}
		}
		memset( vis, 0, sizeof( vis ));
		int ans = 0;
		for (int k = 0; k < n; ++k){
			for (int i = k+1; i < n; ++i){
				if (mat[k][i] == 0) continue;
				for (int j = i+1; j < n; ++j){
					if (!mat[k][j] || !mat[i][j]) continue;
					if (!ok(i,j,k))
						ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}