#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int N = 105;
const int MOD = 1000000007;
typedef long long ll;
/*
*���⣺n�������̣�ÿ����������m����Ʒ��
*ÿ����Ʒ�� ����b �� ��ֵp
*��Ҫ��ÿ������������ѡһ����Ʒ
*ʹ������ѡȡ��n����Ʒ�е� ��С����b/��ֵ�ܺ�p ���

*˼·���ҳ�ÿ����������С��Ʒ����С���������������Сֵ
*��Ϊ���䣬ö�����е� ����band ̰��ʹ��p�ĺ���С
*/
struct Node{
	int b,p;
}a[N][N];
bool cmp(const Node &a, const Node &b){
	return a.b < b.b;
}
int main(){
	int T,n,Min_b,Max_b,m[N];
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		Min_b = inf;
		Max_b = inf;
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &m[i]);
			for(int j=0 ; j < m[i] ; ++j)
				scanf("%d%d", &a[i][j].b, &a[i][j].p);
			sort( a[i], a[i]+m[i], cmp );
			if( a[i][0].b < Min_b ) Min_b = a[i][0].b;
			if( a[i][m[i]-1].b < Max_b ) Max_b = a[i][m[i]-1].b;
		}
		double ans=0;
		int band;
		for(int b=Min_b ; b <= Max_b ; ++b){
			int price = 0;
			band = inf;
			for(int i=0 ; i < n ; ++i)
			{
				int v = 0;
				//Ѱ�������ڵ� ��Сband
				for(int j=0 ; j < m[i] ; ++j)
					if( a[i][j].b >= b ){
						v = j; break;
					}
				//Ѱ�ұ����band��ģ����Ǽ�ֵ��С��p
				for(int j=v ; j < m[i] ; ++j)
					if( a[i][j].p < a[i][v].p )
						v = j;
				price += a[i][v].p;
				band = min( band, a[i][v].b );
			}
			ans = max(ans,(band+0.0)/price);
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}