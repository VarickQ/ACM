#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const __int64 N = 1100;

ll dp[N],ans;
struct A{
	__int64 l,k,w,z;
}a[N];
bool cmp(A &a,A &b){
	if(a.l != b.l) return a.l < b.l;
	if(a.k != b.k) return a.k < b.k;
	return a.z > b.z;
}
bool check(__int64 i,__int64 j){
	if(a[i].z==0 && a[i].l>=a[j].l&&a[i].k>=a[j].k)
		return true;
	if(a[i].z==1 && a[i].l*a[i].k > a[j].l*a[j].k && a[i].l>=a[j].l&&a[i].k>=a[j].k)
		return true;
	if(a[i].z==2 && a[i].l > a[j].l&&a[i].k > a[j].k)
		return true;
	return false;
}
int main(){
	__int64 n;
	while(scanf("%I64d",&n) && n)
	{
		for(__int64 i=0 ; i < n ; ++i){
			scanf("%I64d%I64d%I64d%I64d",&a[i].l,&a[i].k,&a[i].w,&a[i].z);
			if(a[i].k > a[i].l) swap(a[i].k,a[i].l);
		}
		sort(a,a+n,cmp);
		memset(dp,0,sizeof(dp));
		ans = 0;
		for(__int64 i=0 ; i < n ; ++i){
			dp[i] = a[i].w;
			for(__int64 j=0 ; j < i ; ++j)
				if(check(i,j)) dp[i] = max(dp[i],dp[j]+a[i].w);
			ans = max(ans,dp[i]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}