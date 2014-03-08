/*
1）首先按照常规的方法求出最长公共子序列的长度
也就是用O(MN)的那个动态规划，结果放在二维数组dp里
dp[i][j] = { 字串a的1~i部分与字串b的1~j部分的最长公共子序列的长度 }
2）求辅助数组
last1[i][j] = { 到下标i为止，字符j在字串a中最后一次出现的下标 }
last2[i][j] = { 到下标i为止，字符j在字串b中最后一次出现的下标 }
3）枚举最长公共字串的每一个字符
从最后一个字符开始枚举
比如说现在枚举最后一个字符是'C'的情况。
那么 'CDCD' 与 'FUCKC' 这两个字串。
一共有 (0, 2) (0, 4)  (2, 2)  (2. 4) 这四种可能。
很明显前三个是可以舍弃的，因为第四个优于前三个，为后续的枚举提供了更大的空间。
last数组正好是用来做这个的。
4）排序输出
代码里用了stl的set。
注意，由于刚刚的枚举过程是针对每个字符，所以是不用判重的。
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