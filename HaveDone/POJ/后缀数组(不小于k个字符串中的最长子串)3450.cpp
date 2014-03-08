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
const int N = 900010;
const int M = 900010;

int wa[N],wb[N],wv[N],_ws[N];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) _ws[i]=0;
     for(i=0;i<n;i++) _ws[x[i]=r[i]]++;
     for(i=1;i<m;i++) _ws[i]+=_ws[i-1];
     for(i=n-1;i>=0;i--) sa[--_ws[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
       for(p=0,i=n-j;i<n;i++) y[p++]=i;
       for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
       for(i=0;i<n;i++) wv[i]=x[y[i]];
       for(i=0;i<m;i++) _ws[i]=0;
       for(i=0;i<n;i++) _ws[wv[i]]++;
       for(i=1;i<m;i++) _ws[i]+=_ws[i-1];
       for(i=n-1;i>=0;i--) sa[--_ws[wv[i]]]=y[i];
       for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
       x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
     return;
}
int _rank[N],h[N];
void calh(int *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++) _rank[sa[i]]=i;
     for(i=0;i<n;h[_rank[i++]]=k)
     for(k?k--:0,j=sa[_rank[i]-1];r[i+k]==r[j+k];k++);
     return;
}
int a[N],sa[N],n;

char str[210],ans[210];
int f[N],T,vis[N],ii=0;
string res,tt;
bool check(int mid){
	tt = "";
	string tmp;
	int r,cnt,ret = 0;
	for(int i=2 ; i <= n ; i=r+1){
		while( h[i]<mid && i<=n )i++;
		r = i;
		while( h[r]>=mid ) r++;
		if( r-i+1 < T ) continue;
		ii++, cnt = 0;
		for(int k=i-1 ; k < r ; ++k)
			if( f[sa[k]] != 0 )
				if(vis[f[sa[k]]]!=ii)
					vis[f[sa[k]]]=ii,cnt++;
		if( cnt >= T ){
			tmp = "";
			for(int j=0 ; j < mid ; ++j)
				tmp += a[sa[i]+j]-1+'a';
			//cout << tmp << endl;
			if( tmp < tt || tt == "" )
				tt = tmp;
			ret = 1;
		}
	}
	return ret;
}
int main(){
	while( scanf("%d", &T) && T ){
		int len, k=27;
		n = 0;
		for(int i=1 ; i <= T ; ++i){
			scanf("%s", str);
			len = strlen(str);
			for(int j=0 ; j < len ; ++j){
				a[n] = str[j]-'a'+1;
				f[n++] = i;
			}
			a[n] = k;
			f[n++] = 0;
			k++;
		}
		a[n] = 0;

		da(a,sa,n+1,k);
		calh(a,sa,n);
		h[n+1] = -1;

		res = "";
		int mid,l=0,r=200,ok=0;
		while( l <= r ){
			mid = (l+r)/2;
			if( check(mid) ){
				l = mid+1;
				if( ok < mid || res == "" )
					res = tt;
				ok = mid;
			}
			else r = mid-1;
		}
		if( ok == 0 ) puts("IDENTITY LOST");
		else cout << res << endl;
	}
	return 0;
}