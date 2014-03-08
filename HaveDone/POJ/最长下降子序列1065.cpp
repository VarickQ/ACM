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
typedef long long ll;
const int inf = 2000000000;
const int M   = 1000000000;
const int N   = 5005;

struct Node{
	int l,w;
}a[N];
bool cmp(const Node &a,const Node &b){
	if(a.l == b.l) return a.w < b.w;
	return a.l < b.l;
}
int p[N];
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--){
		memset(p,0,sizeof(p));
		scanf("%d",&n);
		for(int i=1 ; i <= n ; ++i)
			scanf("%d%d",&a[i].l,&a[i].w);
		sort(a+1,a+n+1,cmp);
		int l,r,len = 1;
		p[1] = a[1].w;
		for(int i=2 ; i <= n ; ++i){
			if(a[i].w < p[len]) p[++len] = a[i].w;
			else {
				l = 1; r = len;
				while(l <= r){
					int mid = (l+r)/2;
					if(a[i].w < p[mid]) l=mid+1;
					else r = mid-1;
				}
				p[l] = a[i].w;
			}
		}
		printf("%d\n",len);
	}
	return 0;
}
