/*
����һ���ַ����������ٳ���k�ε���ظ��Ӵ�����k���Ӵ������ص���
�㷨������
�������������һ���࣬Ҳ���ȶ��ִ𰸣�Ȼ�󽫺�׺�ֳ������顣��
ͬ���ǣ�����Ҫ�жϵ�����û��һ����ĺ�׺������С��k������У���ô����
k����ͬ���Ӵ��������������򲻴��ڡ����������ʱ�临�Ӷ�ΪO(nlogn)��
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
const int N = 20010;
const int M = 1000010;

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
bool check(int mid){
	int cnt = 1;
	for(int i=1 ; i <= n ; ++i){
		if( h[i] >= mid ){
			cnt++;
			if( cnt >= k ) return true;
		}
		else cnt = 1;
	}
	return false;
}
int main(){
	while( scanf("%d%d", &n, &k) != EOF ){
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &a[i]);
		a[n] = 0;

		Da(a,n+1,M);
		Calheight(a,n);

		int mid,l=1,r=n;
		while( l <= r ){
			mid = (l+r)/2;
			if( check(mid) ) l = mid+1;
			else r = mid-1;
		}
		printf("%d\n", r);
	}
	return 0;
}