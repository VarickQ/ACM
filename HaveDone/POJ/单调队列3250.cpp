#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define inf 1<<30
struct Queue{
	int head,tail;//记录队首和队尾
	int X[80005];//记录元素在原队列中的下标
}q;
int cow[80005];
int main()
{
	int n;
	long long ans;
	while(scanf("%d",&n) == 1)
	{
		for(int i=1 ; i <= n ; i++)
			scanf("%d",&cow[i]);
		ans = 0;
		cow[n+1]=inf;
		for(int i=1 ; i <= n+1 ; i++)
		{
			while(q.head<=q.tail && cow[q.X[q.tail]]<=cow[i]){
				ans += i-q.X[q.tail]-1;
				q.tail--;
			}
			q.tail++;
			q.X[q.tail]=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}