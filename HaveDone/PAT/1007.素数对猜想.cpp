/*
1007. 素数对猜想 (20)

让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。
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
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100100;
const int N   = 100100;
typedef long long LL;

bool su[M];
int prime[N],cnt,d[N],sum[N];
void S(){
	su[1] = su[0] = true;
	for (LL i=2; i <= M-10; i++)
		if(!su[i]){
			for(LL j = i*i; j <= M-10; j+=i)
				su[j] = true;
		}
	cnt = 0;
	for (int i=2; i <= M-10; ++i)
		if (!su[i]) prime[cnt++] = i;
}
int main(){
	S();
	d[0] = 0;
	for (int i = 1; i <= M-10; ++i)
		d[i] = (prime[i] - prime[i-1] == 2);
	sum[0] = 0;
	for (int i = 1; i <= M-10; ++i)
		sum[i] = sum[i-1] + d[i];
	int n;
	while (1 == scanf("%d", &n)) {
		for (int i = 0; i < cnt; ++i) {
			if (n < prime[i]){
				printf("%d\n", sum[i-1]);
				break;
			}
		}
	}
	return 0;
}