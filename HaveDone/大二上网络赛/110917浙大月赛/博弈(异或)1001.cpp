#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;
#define ll long long
const ll M = 1000000007;
const int inf = (1<<30);
const int N = 5000010;

int su[N],prime[N],cnt;
void S()
{
	//memset(su,0,sizeof(su));
	su[1]=su[0]=1;
	for(ll i=2;i<=N-10;i++)
		if(!su[i])
		{
			for(ll j=i*i;j<=N-10;j+=i)
				su[j] = 1;
		}
	for(int i=2 ; i <= N-10 ; ++i)
		if(!su[i]) prime[cnt++] = i;
}

int a[N],num[N];
int main() {
	int i,j,n,ans,cs=0;
	S();
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	for(i=4 ; i <= N-10 ; ++i){
		a[i] = 1;
		if(!su[i]) continue;
		if(i&1){
			for(j=1 ; j < cnt && prime[j] < i ; ++j)
				if(i%prime[j]==0){
					a[i]=a[i/prime[j]]+1;
					break;
				}
		}
		else a[i]=a[i/2]+1;
	}
	while(scanf("%d",&n) != EOF)
	{
		scanf("%d",&num[0]);
		ans = a[num[0]];
		for(i=1 ; i < n ; ++i){
			scanf("%d",&num[i]);
			ans = ans^a[num[i]];
		}
		printf("Test #%d: ",++cs);
		if(ans==0) printf("Bob\n");
		else {
			printf("Alice ");
			int temp = ans;
			for(i=0 ; i < n ; ++i){
				if(a[num[i]]==0)continue;
				temp = ans^a[num[i]];
				if(temp <= a[num[i]]) break;
			}
			printf("%d\n",i+1);
		}
	}
	return 0;
}