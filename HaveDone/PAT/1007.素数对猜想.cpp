/*
1007. �����Բ��� (20)

�����Ƕ��� dn Ϊ��dn = pn+1 - pn������ pi �ǵ�i����������Ȼ�� d1=1 �Ҷ���n>1�� dn ��ż�����������Բ��롱��Ϊ�����������������Ҳ�Ϊ2����������

�ָ�������������N (< 105)������㲻����N���������������Եĸ�����

�����ʽ��ÿ�������������1����������������������N��

�����ʽ��ÿ���������������ռһ�У�������N���������������Եĸ�����
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