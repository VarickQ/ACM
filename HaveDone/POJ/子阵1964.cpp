/*
����һ��n*m�ľ��Σ�R����ռ�õĵط���F����յء������ҳ�һƬ���ľ��οյء�һС��յػ���3Ԫ�������󻨷ѡ�
�����·���Ŀ�ֵȷ��������������l[j],r[j]����ʾÿһ�е�j���������󵽵�����߿���к����ұ߿���С�
Ȼ��ֻҪ����mat[i][j]*(r[j]-l[j]+1)���ǵ�ǰ��ռ�õ���������һֱȡ���*3�������Ĵ��ˡ�
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

int n, m, mat[N][N],l[N],r[N];
int main(){
	int T;
	char ch[2];
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= m ; ++j){
				scanf("%s", ch);
				if( ch[0] == 'R' ) mat[i][j] = 0;
				else if( ch[0] == 'F' )
					mat[i][j] = mat[i-1][j]+1;
			}
		int ans = 0;
		for(int i=1 ; i <= n ; ++i){
			for(int j=1 ; j <= m ; ++j)
				l[j] = r[j] = j;
			for(int j=1 ; j <= m ; ++j){
				if( mat[i][j] == 0 ) continue;
				while( j>1 && mat[i][l[j]-1]>=mat[i][l[j]] )
					l[j] = l[j]-1;
				while( j<m && mat[i][r[j]+1]>=mat[i][r[j]] )
					r[j] = r[j]+1;
			}
			for(int j=1 ; j <= m ; ++j){
				int tmp = mat[i][j]*(r[j]-l[j]+1);
				if( tmp > ans ) ans = tmp;
			}
		}
		printf("%d\n", ans*3);
	}
	return 0;
}