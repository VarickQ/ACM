//注意三点可以去掉disk的情况：最前面的，中间的，最后面的
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
#define eps 1e-8
const int N = 1005;

double r[N],x[N];
bool vis[N];
int t[N];
int main(){
	int n, cnt;
	while( scanf("%d", &n) != EOF ){
		memset( t, -1, sizeof( t ) );
		memset( vis, 0, sizeof( vis ) );
		cnt = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%lf", &r[i]);
			x[i] = r[i];//初始位置都为半径,去除第一个圆不符合的情况
		}
		double w = 0;
		int pos = 0;
		for(int i=1 ; i < n ; ++i){
			for(int j=0 ; j < i ; ++j){
				double d = x[j]+2.0*sqrt(r[i]*r[j]);
				if( d-x[i] > eps ){
					x[i] = d;
					t[i] = j;//t[i]=j表示第i个圆与第j个相切时横向距离最大
				}
			}
			if( x[i]+r[i]-w > eps ){
				w = x[i]+r[i];//最远距离
				pos = i;
			}
		}
		for(int i=0 ; i < n ; ++i)
			for(int j=t[i]+1 ; j < i ; ++j)//去除中间不符合的圆
				if( !vis[j] ){
					vis[j] = true;
					cnt++;
				}
		for(int i=pos+1 ; i < n ; ++i)//去除最右边不符合的圆
			if( !vis[i] ){
				vis[i] = true;
				cnt++;
			}
		printf("%d\n", cnt);
		for(int i=0 ; i < n ; ++i)
			if( vis[i] ) printf("%d\n", i+1);
	}
	return 0;
}