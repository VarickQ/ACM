/*
    һ����Ͳ�������ܳ��ܵ������ֵΪm����ʵ���ڷ�Χ[1,m]
    ����Ҫ��������ʵ�ʱ���ֵ
    
    ���ֻ��һ����Ͳ�Ļ�������Ҫ��С�������ֱ����
    �����£���������
    �Ǿ���Ҫ����1,2,,m �ܹ���Ҫ(m+1)*m/2�����Ļ�ҩ��
    ע����һ�β���û���Ļ�����Ͳ������õ�
    
    ������ж����Ͳ������Բ��ò�����ô���
    ��2���Ļ�����һ�β���t ��1<=t<=m
    �����´ξ�Ҫ����[1,t-1] ֻʣ��һ����Ͳ��
    �����������õ�ǰ����Ͳ������[t+1,m]
    
    ����dp[k,i,j]��ʾ��ʣ��k����Ͳ������ֵ�ķ�Χ��[i,j]��Ϊ�������ֵ������Ҫ�Ļ�ҩ
    ö��t���������dp[k-1,i,t-1],dp[k,t+1,j]ת�ƹ���
    �������Ȳ�֪����Ϊ��ʹ��ҩ�㹻������ֻ��ȡ���ֵ max(dp[k-1,i,t-1],dp[k,t+1,j])
    ��Ϊ�����ٵĲ��ԣ�����ö��t���õ�������Ҫ�Ļ�ҩ
    dp[k,i,j] = min{t+max(dp[k-1,i,t-1],dp[k,t+1,j])}
    
    �ο�http://www.cppblog.com/Yuan/archive/2011/03/03/141051.html
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