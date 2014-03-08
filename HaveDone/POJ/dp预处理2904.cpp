/*
    一个邮筒理论上能承受的最大爆破值为m，则实际在范围[1,m]
    现在要测试它的实际爆破值
    
    如果只有一个邮筒的话，就需要从小到大测试直到破
    最坏情况下，到最后才破
    那就需要测试1,2,,m 总共需要(m+1)*m/2数量的火药了
    注：上一次测试没爆的话，邮筒还是完好的
    
    但如果有多个邮筒，则可以不用测试那么多次
    如2个的话，第一次测试t ，1<=t<=m
    爆：下次就要测试[1,t-1] 只剩下一个邮筒，
    不爆：继续用当前的邮筒，测试[t+1,m]
    
    所以dp[k,i,j]表示还剩下k个邮筒，爆破值的范围在[i,j]，为测出爆破值至少需要的火药
    枚举t，则可以由dp[k-1,i,t-1],dp[k,t+1,j]转移过来
    由于事先不知道，为了使火药足够，所以只能取最大值 max(dp[k-1,i,t-1],dp[k,t+1,j])
    但为了最少的测试，所以枚举t，得到最少需要的火药
    dp[k,i,j] = min{t+max(dp[k-1,i,t-1],dp[k,t+1,j])}
    
    参考http://www.cppblog.com/Yuan/archive/2011/03/03/141051.html
*/
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
const int inf = 1000000000;
const double eps = 1e-6;

int dp[11][101][101];
int main(){
	int n, k, m;
	for(int i=1 ; i <= 100 ; ++i)
		for(int j=i ; j <= 100 ; ++j)
			dp[1][i][j] = (j-i+1)*(j+i)/2;
	for( k=2 ; k <= 10 ; ++k ){
		for(int l=0 ; l <= 100 ; ++l){
			for(int i=1 ; i+l <= 100 ; ++i){
				int j = i+l;
				dp[k][i][j] = inf;
				if(l==0) dp[k][i][j] = i;
				for(int t=i ; t <= j ; ++t)
					dp[k][i][j]=min(dp[k][i][j],t+max(dp[k-1][i][t-1],dp[k][t+1][j]));
			}
		}
	}
	scanf("%d", &n);
	while( n-- ){
		scanf("%d%d", &k, &m);
		printf("%d\n", dp[k][1][m]);
	}
	return 0;
}