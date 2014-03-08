#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 110;

struct A{
	int id,num;
}a[N];
int b[N],ans[N],cnt;
bool c[N];
bool cmp(A a,A b){
	return a.num < b.num;
}
int main()
{
	int n,p,i,j;
	while(scanf("%d%d",&n,&p) == 2)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(i=0 ; i < n ; ++i){
			for(j=0 ; j < p ; ++j){
				scanf("%d",&a[j].num);
				a[j].id = j+1;
			}
			sort(a,a+p,cmp);
			c[a[p-1].id] = true;
			for(j=p-2 ; j >= 0 ; --j)
				if(a[j].num == a[p-1].num)
					c[a[j].id] = true;
			bool f = false;
			for(j=0 ; j < p ; ++j)
				if(a[j].num == a[0].num && !c[a[j].id]){
					f = true; break;
				}
			if(f){
				b[a[j].id]++;
				for(j=j+1 ; j < p ; ++j){
					if(a[j].num == a[0].num)
						b[a[j].id] ++;
				}
			}
		}
		cnt = 0;
		for(i=1 ; i <= p ; ++i)
			if(b[i]*2>n && !c[i])
				ans[cnt++] = i;
		if(cnt==0)printf("0\n");
		else {
			for(i=0 ; i < cnt-1 ; ++i)
				printf("%d ",ans[i]);
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}