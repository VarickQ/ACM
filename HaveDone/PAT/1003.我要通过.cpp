/*
1003. ��Ҫͨ����(20)
������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����

���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�
�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�

�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��
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

char s[105];
bool judge(char *s){
	int len = strlen(s), tot = 0;
	int a, b, c, cp, ct, pp, pt;
	a = b = c = cp = ct = pp = pt = 0;
	for (int i = 0; i < len; ++i){
		if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T')
			return false;
		if (s[i] == 'P'){
			cp++; pp = i;
		}
		if (s[i] == 'T'){
			ct++; pt = i;
		}
	}
	if (cp > 1 || ct > 1) return false;
	for (int i = pp+1; i < pt; ++i)
		if (s[i] == 'A') b++;
	if (b == 0) return false;
	for (int i = 0; i < pp; ++i)
		if (s[i] == 'A') a++;
	for (int i = pt + 1; i < len; ++i)
		if (s[i] == 'A') c++;
	if (c == b * a) return true;
	return false;
}
int main(){
	int n;
	while (1 == scanf("%d", &n)){
		for (int i = 0; i < n; ++i){
			scanf("%s", s);
			if (judge(s)) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}