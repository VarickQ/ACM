/*
给定一个字符串，求不相同的子串的个数。
算法分析：
每个子串一定是某个后缀的前缀，那么原问题等价于求所有后缀之间的不相
同的前缀的个数。如果所有的后缀按照suffix(sa[1]), suffix(sa[2]),
suffix(sa[3]),……,suffix(sa[n])的顺序计算，不难发现，对于每一次新加
进来的后缀suffix(sa[k]),它将产生n-sa[k]+1个新的前缀。但是其中有
height[k]个是和前面的字符串的前缀是相同的。所以suffix(sa[k])将“贡献”
出n-sa[k]+1-height[k]个不同的子串。累加后便是原问题的答案。这个做法
的时间复杂度为O(n)。

所有前缀和就是(1+n)*n/2
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
	int i, j, p;			//p 不同字符串个数
	int *x = wa, *y = wb, *t;//_rank值保存在x中
	//对r中长度为1的子串进行基数排序
	for( i=0 ; i < m ; ++i ) wn[i] = 0;
	for( i=0 ; i < n ; ++i ) wn[x[i]=r[i]]++;
	for( i=1 ; i < m ; ++i ) wn[i] += wn[i-1];
	for( i=n-1 ; i >= 0 ; --i ) sa[--wn[x[i]]] = i;
	//对r中长度为j的子串进行基数排序
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