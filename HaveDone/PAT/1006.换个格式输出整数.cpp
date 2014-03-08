/*
1006. 换个格式输出整数 (15)

让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。
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