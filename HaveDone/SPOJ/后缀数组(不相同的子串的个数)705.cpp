/*
����һ���ַ���������ͬ���Ӵ��ĸ�����
�㷨������
ÿ���Ӵ�һ����ĳ����׺��ǰ׺����ôԭ����ȼ��������к�׺֮��Ĳ���
ͬ��ǰ׺�ĸ�����������еĺ�׺����suffix(sa[1]), suffix(sa[2]),
suffix(sa[3]),����,suffix(sa[n])��˳����㣬���ѷ��֣�����ÿһ���¼�
�����ĺ�׺suffix(sa[k]),��������n-sa[k]+1���µ�ǰ׺������������
height[k]���Ǻ�ǰ����ַ�����ǰ׺����ͬ�ġ�����suffix(sa[k])�������ס�
��n-sa[k]+1-height[k]����ͬ���Ӵ����ۼӺ����ԭ����Ĵ𰸡��������
��ʱ�临�Ӷ�ΪO(n)��

����ǰ׺�;���(1+n)*n/2
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
typedef long long LL;
const int inf = 100000000;
const int N = 50010;
const int M = 50010;

char str[N];
int a[N], n, k;
int wa[N],wb[M];
int wv[N],wn[M];
int sa[N],_rank[N],h[N];

int cmp(int *r,int a,int b,int l){
	return r[a]==r[b] && r[a+l]==r[b+l];
}
void Da(int *r,int n,int m){
	int i, j, p;			//p ��ͬ�ַ�������
	int *x = wa, *y = wb, *t;//_rankֵ������x��
	//��r�г���Ϊ1���Ӵ����л�������
	for( i=0 ; i < m ; ++i ) wn[i] = 0;
	for( i=0 ; i < n ; ++i ) wn[x[i]=r[i]]++;
	for( i=1 ; i < m ; ++i ) wn[i] += wn[i-1];
	for( i=n-1 ; i >= 0 ; --i ) sa[--wn[x[i]]] = i;
	//��r�г���Ϊj���Ӵ����л�������
	for( j=1,p=1 ; p < n ; j*=2,m=p ){
		for( p=0,i=n-j ; i < n ; ++i ) y[p++] = i;
		for( i=0 ; i < n ; ++i ) if(sa[i] >= j) y[p++] = sa[i]-j;
		for( i=0 ; i < n ; ++i ) wv[i] = x[y[i]];
		for( i=0 ; i < m ; ++i ) wn[i] = 0;
		for( i=0 ; i < n ; ++i ) wn[wv[i]]++;
		for( i=1 ; i < m ; ++i ) wn[i] += wn[i-1];
		for( i=n-1 ; i >= 0 ; --i ) sa[--wn[wv[i]]] = y[i];

		t = x, x = y, y = t, p = 1;
		for( x[sa[0]]=0,i=1 ; i < n ; ++i )
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}
void Calheight(int *r,int n){
	int i, j, k = 0;
	for( i=1 ; i <= n ; ++i ) _rank[sa[i]] = i;
	for( i=0 ; i < n ; h[_rank[i++]] = k )
		for( k?k--:0,j=sa[_rank[i]-1] ; r[i+k]==r[j+k]; ++k);
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%s", str);
		n = strlen(str);
		for(int i=0 ; i < n ; ++i) a[i] = str[i];
		a[n] = 0;

		Da(a,n+1,200);
		Calheight(a,n);

		LL ans = (LL)(1+n)*n/2;//!!
		for(int i=1 ; i <= n; ++i)
			ans -= h[i];
		printf("%lld\n", ans);
	}
	return 0;
}