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
const int N = 2010;
const int M = 2010;

char s[N];
int a[N], n;
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

int RMQ[N], Log[N], best[20][N];
void initRMQ(int n){
	int i, j, a, b;
	for( i=1 ; i <= n ; ++i ) RMQ[i] = h[i];
	for(Log[0]=-1,i=1 ; i <= n ; ++i){
		if( (i&(i-1)) == 0 )
			Log[i] = Log[i-1]+1;
		else Log[i] = Log[i-1];
	}
	for( i=1 ; i <= n ; ++i ) best[0][i] = i;
	for( i=1 ; i <= Log[n] ; ++i ){
		for( j=1 ; j <= n+1-(1<<i) ; ++j ){
			a = best[i-1][j];
			b = best[i-1][j+(1<<(i-1))];
			if( RMQ[a] < RMQ[b] ) best[i][j] = a;
			else best[i][j] = b;
		}
	}
}
int askRMQ(int a,int b){
	int t;
	t = Log[b-a+1];
	b = b-(1<<t)+1;
	a = best[t][a];
	b = best[t][b];
	return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b){
	int t;
	a = _rank[a];
	b = _rank[b];
	if( a > b ) swap( a, b );
	return h[askRMQ(a+1,b)];
}
int main(){
	while( scanf("%s", s) != EOF ){
		n = strlen(s);
		int l = n;
		s[n] = '$';
		for(int j=n+1,k=n-1 ; j <= 2*n ; ++j,--k)
			s[j] = s[k];
		n += n+1;
		s[n] = '\0';
		//printf("%s\n", s);
		for(int i=0 ; i < n ; ++i) a[i] = s[i];
		a[n] = 0;

		Da(a,n+1,200);
		Calheight(a,n);
		int ans = 0, pos;
		initRMQ(n);
		for(int i=0 ; i < l ; ++i){
			int tmp = lcp(i,n-i);
			if( tmp*2 > ans ){//偶数长度
				ans = tmp*2;
				pos = i-tmp;
			}
			tmp = lcp(i,n-i-1);
			if( tmp*2-1 > ans ){//奇数长度
				ans = tmp*2-1;
				pos = i-tmp+1;
			}
		}
		for(int i=pos ; i < pos+ans ; ++i)
			printf("%c", s[i]);
		puts("");
	}
	return 0;
}