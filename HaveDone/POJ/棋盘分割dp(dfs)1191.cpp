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
#define abs(x) ((x)>0?(x):-(x))
typedef long long LL;
const int N = 210;
const double eps = 1e-6;

double dp[15][10][10][10][10], s[10][10];
double cal(int x1,int y1,int x2,int y2){
	double t = s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
	return t*t;
}
double dfs(int k,int x1,int y1,int x2,int y2){
	if( k == 1 ) return cal(x1,y1,x2,y2);
	if( fabs(dp[k][x1][y1][x2][y2])>eps ) return dp[k][x1][y1][x2][y2];//TLE
	double tmp = 999999999.0;
	for(int i=x1 ; i < x2 ; ++i)
		tmp=min(tmp,min((dfs(k-1,x1,y1,i,y2)+cal(i+1,y1,x2,y2)),(dfs(k-1,i+1,y1,x2,y2)+cal(x1,y1,i,y2))));
	for(int i=y1 ; i < y2 ; ++i)
		tmp=min(tmp,min((dfs(k-1,x1,y1,x2,i)+cal(x1,i+1,x2,y2)),(dfs(k-1,x1,i+1,x2,y2)+cal(x1,y1,x2,i))));
	dp[k][x1][y1][x2][y2] = tmp;
	return tmp;
}
int main(){
	int n,a;
	while( scanf("%d", &n) != EOF ){
		memset( s, 0, sizeof( s ) );
		for(int i=1 ; i <= 8 ; ++i)
			for(int j=1 ; j <= 8 ; ++j){
				scanf("%d", &a);
				s[i][j] = s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a;
			}
		memset( dp, 0, sizeof( dp ) );
		double ans = sqrt(dfs(n,1,1,8,8)/n-s[8][8]/n*s[8][8]/n);
		printf("%.3lf\n", ans);
	}
	return 0;
}