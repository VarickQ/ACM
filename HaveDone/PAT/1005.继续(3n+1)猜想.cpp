#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
/*
1005. 继续(3n+1)猜想 (25)

卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。

输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。
*/
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
const int N   = 5050;
typedef long long LL;

bool vis[N];
int a[N];
int main(){
	int n;
	while (1 == scanf("%d", &n)){
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort( a, a+n );
		int cnt = 0;
		memset( vis, false, sizeof( vis ) );
		for (int i = 0; i < n; ++i){
			if ( vis[a[i]] ) continue;
			int tmp = a[i];
			while (tmp != 1){
				if (tmp&1) tmp = (3 * tmp + 1) / 2;
				else tmp = tmp / 2;
				vis[tmp] = true;
			}
		}
		int i = n-1;
		for ( ; i >= 0; --i)
			if (!vis[a[i]]){
				printf("%d", a[i]);
				break;
			}
		for ( --i; i >= 0; --i)
			if (!vis[a[i]]) printf(" %d", a[i]);
		puts("");
	}
	return 0;
}