/*
1006. ������ʽ������� (15)

����������ĸB����ʾ���١�����ĸS��ʾ��ʮ�����á�12...n������ʾ��λ����n��<10����������ʽ�������һ��������3λ��������������234Ӧ�ñ����ΪBBSSS1234����Ϊ����2�����١���3����ʮ�����Լ���λ��4��

�����ʽ��ÿ�������������1����������������������n��<1000����

�����ʽ��ÿ���������������ռһ�У��ù涨�ĸ�ʽ���n��
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
const int N   = 105;
typedef long long LL;

char s[N];
void putB(int n){
	for (int i = 0; i < n; ++i)
		printf("B");
}
void putS(int n){
	for (int i = 0; i < n; ++i)
		printf("S");
}
void putG(int n){
	for (int i = 1; i <= n; ++i)
		printf("%c", i + '0');
}
int main(){
	int n;
	while (1 == scanf("%s", s)){
		int len = strlen(s);
		if (len == 3){
			putB(s[0] - '0');
			putS(s[1] - '0');
			putG(s[2] - '0');
		}
		else if (len == 2){
			putS(s[0] - '0');
			putG(s[1] - '0');
		}
		else {
			putG(s[0] - '0');
		}
		puts("");
	}
	return 0;
}