/*
dp[j] = max(dp[j], dp[i]+v[j])��ǰ��v[j]>v[i], ���ɵ����� 
����j>i, dp[i]��ǰi���е�����״̬, v[j]��j�ļ�ֵ
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
const int N = 1010;
const int inf = 1000000000;
const double eps = 1e-6;

int a[N], dp[N];
int main(){
	int n;
	while( scanf("%d", &n) && n ){
		int ans = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &a[i]);
			dp[i] = a[i];
		}
		for(int i=0 ; i < n ; ++i)
			for(int j=i+1 ; j < n ; ++j){
				if( a[j] > a[i] )
					dp[j] = max(dp[j],dp[i]+a[j]);
				if( dp[j] > ans ) ans = dp[j];
			}
		printf("%d\n", ans);
	}
	return 0;
}