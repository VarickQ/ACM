/*
1002. д������� (20)
����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�

�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10^100��

�����ʽ����һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�
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
const int inf = 1000000000;
const int M   = 50005;
const int N   = 205;
typedef long long LL;

char str[15][10]={"ling","yi","er","san","si","wu","liu"
	,"qi","ba","jiu","shi"};
char s[105];
int a[105];
int main(){
	while (1 == scanf("%s", s)){
		int num = 0;
		for (int i = 0; s[i]; ++i)
			num += s[i] - '0';
		int cnt = 0;
		while (num){
			a[cnt++] = num % 10;
			num /= 10;
		}
		for (int i = cnt-1; i > 0; --i)
			printf("%s ", str[a[i]]);
		printf("%s\n", str[a[0]]);
	}
	return 0;
}