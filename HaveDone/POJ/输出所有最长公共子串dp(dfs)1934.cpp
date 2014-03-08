/*
1�����Ȱ��ճ���ķ����������������еĳ���
Ҳ������O(MN)���Ǹ���̬�滮��������ڶ�ά����dp��
dp[i][j] = { �ִ�a��1~i�������ִ�b��1~j���ֵ�����������еĳ��� }
2����������
last1[i][j] = { ���±�iΪֹ���ַ�j���ִ�a�����һ�γ��ֵ��±� }
last2[i][j] = { ���±�iΪֹ���ַ�j���ִ�b�����һ�γ��ֵ��±� }
3��ö��������ִ���ÿһ���ַ�
�����һ���ַ���ʼö��
����˵����ö�����һ���ַ���'C'�������
��ô 'CDCD' �� 'FUCKC' �������ִ���
һ���� (0, 2) (0, 4)  (2, 2)  (2. 4) �����ֿ��ܡ�
������ǰ�����ǿ��������ģ���Ϊ���ĸ�����ǰ������Ϊ������ö���ṩ�˸���Ŀռ䡣
last��������������������ġ�
4���������
����������stl��set��
ע�⣬���ڸոյ�ö�ٹ��������ÿ���ַ��������ǲ������صġ�
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

char s1[N],s2[N];
int dp[N][N],last1[N][27],last2[N][27];
string tmp;
set<string> st;
void dfs( int l1, int l2, int len ){
	if( len <= 0 ){
		reverse( tmp.begin(), tmp.end() );
		st.insert(tmp);
		reverse( tmp.begin(), tmp.end() );
		return;
	}
	if( l1 && l2 ){
		for(int i=0 ; i < 26 ; ++i){
			if(dp[last1[l1][i]][last2[l2][i]] == len ){
				tmp += (i+'a');
				dfs( last1[l1][i]-1, last2[l2][i]-1, len-1 );
				tmp.erase(tmp.end()-1);
			}
		}
	}
}
int main(){
	while( scanf("%s%s", s1+1, s2+1) != EOF ){
		st.clear();
		memset( dp, 0, sizeof( dp ) );
		int l1 = strlen(s1+1);
		int l2 = strlen(s2+1);
		for(int i=1 ; i <= l1 ; ++i)
			for(int j=1 ; j <= l2 ; ++j)
				if( s1[i] == s2[j] )
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		memset( last1, 0, sizeof( last1 ) );
		memset( last2, 0, sizeof( last2 ) );
		for(int i=1 ; i <= l1 ; ++i){
			for(int j=0 ; j < 26 ; ++j){
				if( s1[i] == j+'a' )
					last1[i][j] = i;
				else
					last1[i][j] = last1[i-1][j];
			}
		}
		for(int i=1 ; i <= l2 ; ++i){
			for(int j=0 ; j < 26 ; ++j){
				if( s2[i] == j+'a' )
					last2[i][j] = i;
				else
					last2[i][j] = last2[i-1][j];
			}
		}
		tmp = "";
		dfs(l1,l2,dp[l1][l2]);
		for(set<string>::iterator it=st.begin() ; it!=st.end() ; ++it)
			cout << *it << endl;
	}
	return 0;
}