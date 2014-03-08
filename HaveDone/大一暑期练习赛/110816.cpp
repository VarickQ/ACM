#include <stdio.h>//C
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int mark[2005];
int mat[2005][12];
int main()
{
	int T,n,m,cs=1;
	scanf("%d",&T);
	while(T--)
	{
		memset(mark,0,sizeof(mark));
		scanf("%d%d",&n,&m);
		for(int i=0 ; i < n ; ++i)
			for(int j=0 ; j < m ; ++j)
				scanf("%d",&mat[i][j]);

		int now,ans = 0;
		for(int j=0 ; j < m ; ++j){
			for(int i=0 ; i < n ; ++i)
				mark[i] = mat[i][j];
			sort(mark,mark+n);
			now = 0;
			for(int i=0 ; i < n ; ++i)
				now += abs(i-mark[i]);
			ans += now;
		}
		printf("Case %d: %d\n",cs++,ans);
	}
	return 0;
}
#include <stdio.h>//J
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
const int inf=123456789;
const int N = 10000;

long long n,a[65];
int main()
{
	int T,cs=1,i;
	a[0] = 1;
	for(i=1 ; i < 60 ; ++i)
		a[i] = a[i-1]*2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		printf("Case %d: ",cs++);
		for(i=0 ; i < 60 ; ++i)
			if(a[i] > n) break;
		printf("%d\n",i);
	}
	return 0;
}
#include <stdio.h>//A²¹
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
#define ll long long
#define MOD 10000019
const int N = 100100;

bool isprime[N];
int prime[N],pcnt;
void S()
{
	memset(isprime,true,sizeof(isprime));
	isprime[1] = isprime[0] = false;

	for(ll i=2 ; i < N ; ++i)
		if(isprime[i])
			for(ll j=2 ; j*i < N ; ++j)
				isprime[j*i] = false;

	pcnt = 0;
	for(int i=2 ; i < N ; ++i)
		if(isprime[i]) prime[pcnt++] = i;
}
int main()
{
	int T,t,n,i,count,cs=1;
	long long b;
	S();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&t);
		bool f = false;
		b = 1;
		
		for(i=0 ; i<pcnt && prime[i]<=n ; ++i)
		{
			int temp = n;
			count = 0;
			while(temp){
				count += temp/prime[i];
				temp /= prime[i];
			}
			while(count >= t){
				f = true;
				count -= t;
				b = b*prime[i]%MOD;
			}
		}
		printf("Case %d: ",cs++);
		if(!f) printf("-1\n");
		else printf("%lld\n",b);
	}
	return 0;
}