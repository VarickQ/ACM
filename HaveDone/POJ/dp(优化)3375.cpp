/*
    题意:在M个数中来匹配另外N个，权为|x-y|  问最小代价  M<10^5 N<2000
    先排序，对于最后的匹配结果，不会出现交叉的情况 就可以做DP了
    dp[i,j] = min(dp[i,j-1],dp[i-1,j-1]+|x-y|);
    这样子是O(NM)的，会TLE
    对于最优的情况，与Bi匹配的Aj 肯定不会有|ii-j|>N的    ii为A[]中最接近Bi的
    所以对每个Bi 找到最接近Bi的Aj 然后只计算它左右各N个

    这样确定了计算范围的，要注意从i-1过渡到i时取值时(dp[i-1])不要越出范围[st2,ed2]
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
const int N = 2010;
const int inf = 1000000000;
const double eps = 1e-6;

int a[100010],b[N],dp[2][100010];
int main(){
	int m,n;
	while( scanf("%d%d", &m, &n) != EOF ){
		for(int i=0 ; i < m ; ++i)
			scanf("%d", &a[i]);
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &b[i]);
		sort( a, a+m );
		sort( b, b+n );
		int st1=0,ed1=0,st2,ed2,tmp=0,pos=0;
		dp[0][0] = 0;
		for(int i=0 ; i < n ; ++i){
			while( pos < m ){
				if( a[pos] > b[i] ) break;
				pos++;
			}
			st2 = max(i,pos-n);
			ed2 = min(m-1,pos+n);
			int k = max(st1,min(st2-1,ed1));
			dp[tmp^1][st2] = dp[tmp][k]+abs(a[st2]-b[i]);
			for(int j=st2+1 ; j <= ed2 ; ++j){
				k = min(j-1,ed1);
				dp[tmp^1][j] = min(dp[tmp][k]+abs(a[j]-b[i]),dp[tmp^1][j-1]);
			}
			st1 = st2;
			ed1 = ed2;
			tmp ^= 1;
		}
		printf("%d\n", dp[tmp][ed1]);
	}
	return 0;
}