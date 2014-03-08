//ฒน SGU199
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 100000+100;

struct A{
	int s,b,id;
}a[N];
int b[N],ans[N],pre[N],n;
bool cmp(A a,A b){
	if(a.s == b.s)return a.b > b.b;
	return a.s < b.s;
}
int main()
{
	int i,j;
	while(scanf("%d",&n) != EOF)
	{
		memset(b,0,sizeof(b));
		memset(pre,0,sizeof(pre));
		for(i=1 ; i <= n ; i++){
			scanf("%d%d",&a[i].s,&a[i].b);
			a[i].id = i;
		}
		sort(a+1,a+n+1,cmp);
		ans[1] = 1;
		b[1] = a[1].b;
		int l,r,len = 1;
		for(i=2 ; i <= n ; i++)
		{
			if(a[i].b > b[len]){
				j = ++len;
			} else {
				j = l = 1; r = len;
				while(l <= r){
					int mid = (l+r)>>1;
					if(a[i].b > b[mid])
						j = l = mid+1;
					else r = mid-1;
				}
			}
			b[j] = a[i].b;
			ans[j] = i;
			pre[i] = ans[j-1];
		}
		printf("%d\n",len);
		for(j=0,i=ans[len] ; i ; i=pre[i])
			ans[j++] = a[i].id;
		sort(ans,ans+len);
		for(i=0 ; i < len-1 ; i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[i]);
	}
	return 0;
}