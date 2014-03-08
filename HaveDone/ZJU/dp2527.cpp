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
const int inf = 1000000000;
const int M   = 100010;
const int N   = 1010;
typedef long long LL;

int b[N],a[N],dp[N][N];
int main(){
	int n;
	while( scanf("%d", &n) != EOF ){
		memset( dp, -1, sizeof( dp ) );
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &b[i]);
		sort( b, b+n );
		int cnt = 0, ans = 2, tmp = 1;
		a[cnt++] = b[0];
		for(int i=1 ; i < n ; ++i){
			if( b[i-1] != b[i] ){
				a[cnt++] = b[i];
				if( tmp > ans ) ans = tmp;
				tmp = 1;
			}
			else if( b[i-1] == b[i] ) tmp++;
		}
		if( tmp > ans ) ans = tmp;
		n = cnt;
		for(int i=0 ; i < n ; ++i){
			for(int j=0 ; j < i ; ++j){
				int l=0,r=j-1,mid;
				while( l <= r ){
					mid = (l+r)>>1;
					if( a[i]-a[j] == a[j]-a[mid] ){
						if( dp[j][mid] == -1 ) dp[j][mid] = 2;
						dp[i][j] = max(dp[i][j],dp[j][mid]+1);
						if( dp[i][j] > ans ) ans = dp[i][j];
					}
					if( a[i]-a[j] < a[j]-a[mid] )
						l = mid+1;
					else r = mid-1;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}