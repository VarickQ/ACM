#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
/*
1005. ����(3n+1)���� (25)

������(Callatz)�����Ѿ���1001�и������������������Ŀ������΢��Щ���ӡ�

��������֤�����Ȳ����ʱ��Ϊ�˱����ظ����㣬���Լ�¼�µ��ƹ�����������ÿһ�����������n=3������֤��ʱ��������Ҫ����3��5��8��4��2��1�������Ƕ�n=5��8��4��2������֤��ʱ�򣬾Ϳ���ֱ���ж������Ȳ������α��������Ҫ�ظ����㣬��Ϊ��4�����Ѿ�����֤3��ʱ���������ˣ����ǳ�5��8��4��2�Ǳ�3�����ǡ����������ǳ�һ�������е�ĳ����nΪ���ؼ����������n���ܱ������е��������������ǡ�

���ڸ���һϵ�д���֤�����֣�����ֻ��Ҫ��֤���еļ����ؼ������Ϳ��Բ������ظ���֤���µ����֡������������ҳ���Щ�ؼ����֣������Ӵ�С��˳��������ǡ�

�����ʽ��ÿ�������������1��������������1�и���һ��������K(<100)����2�и���K��������ͬ�Ĵ���֤��������n(1<n<=100)��ֵ�����ּ��ÿո������

�����ʽ��ÿ���������������ռһ�У����Ӵ�С��˳������ؼ����֡����ּ���1���ո��������һ�������һ�����ֺ�û�пո�
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