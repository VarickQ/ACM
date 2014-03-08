/*
1003. 我要通过！(20)
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。
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