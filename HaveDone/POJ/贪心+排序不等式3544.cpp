���򲻵�ʽ��sequence inequality,�ֳ�����ԭ��
���������� a1 , a2 ,���� an; b1 , b2 ,���� bn ���� a1 �� a2 �ܡ����� an, b1 �� b2 �ܡ����� bn ������c1,c2,����,cn��b1,b2,������bn����һ���У�����
a1* bn + a2 *b{n-1}+ ... + an *b1
�� a1 *c1 + a2* c2 +����+ an *cn
�� a1 *b1 + a2 *b2 + ����+an* bn.
���ҽ��� a1 = a2 = ... = an �� b1 = b2 = ... = bn ʱ�Ⱥų�����������͵���˳��͡�
�������򲻵�ʽҲ�ɼ��Ϊ�� ����͡�����͡�ͬ���.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
const int M = 1000200;
const int N = 1205;
typedef long long ll;

struct village{
	ll dis,price,profit;
	int id;
}a[N];
struct pigs{
	ll wight;
	int id;
}p[N];
bool cmp1(const pigs a, const pigs b){
	return a.wight > b.wight;
}
bool cmp2(const village a,const village b){
	return a.profit > b.profit;
}
int main(){
	int n,t;
	while( scanf("%d%d", &n, &t) == 2 ){
		for(int i=0 ; i < n ; ++i){
			scanf("%lld", &p[i].wight);
			p[i].id = i+1;
		}
		sort( p, p+n, cmp1 );
		for(int i=0 ; i < n ; ++i){
			scanf("%lld", &a[i].dis);
			a[i].id = i+1;
		}
		for(int i=0 ; i < n ; ++i){
			scanf("%lld", &a[i].price);
			a[i].profit = a[i].price-a[i].dis*t;
		}
		sort( a, a+n, cmp2 );
		int ans[1005];
		for(int i=0 ; i < n ; ++i)
			ans[a[i].id] = p[i].id;
		for(int i=1 ; i < n ; ++i)
			printf("%d ", ans[i]);
		printf("%d\n",ans[n]);
	}
	return 0;
}