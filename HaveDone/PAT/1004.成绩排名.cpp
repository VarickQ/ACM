/*
1004. 成绩排名 (20)

读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
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

struct Node{
	char name[20], id[20];
	int score;
}a[N];
bool cmp(const Node &a,const Node &b){
	return a.score < b.score;
}
int main(){
	int n;
	while (1 == scanf("%d\n", &n)){
		for (int i = 0; i < n; ++i)
			scanf("%s%s%d", a[i].name, a[i].id, &a[i].score);
		sort( a, a+n, cmp );
		printf("%s %s\n%s %s\n", a[n-1].name, a[n-1].id, a[0].name, a[0].id);
	}
	return 0;
}