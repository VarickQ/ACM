#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1010;

int a[N],b[N];
int c[N],n;
int Lowbit(int t){
	return t & (-t);
}
void update(int pos,int num){
	while(pos <= n){
		c[pos] += num;
		pos += Lowbit(pos);
	}
}
int Sum(int i){
	int sum = 0;
	while(i > 0){
		sum += c[i];
		i -= Lowbit(i);
	}
	return sum;
}
int main()
{
	int i,x;
	while(scanf("%d",&n) != EOF)
	{
		memset(c,0,sizeof(c));
		for(i=1 ; i <= n ; ++i){
			scanf("%d%d",&a[i],&x);
			b[x] = i;
		}
		for(i=1 ; i <= n ; ++i)
			a[i] = b[a[i]];

		int ans = 0;
		for(i=1 ; i <= n ; ++i)
		{
			update(a[i],1);
			ans += Sum(n)-Sum(a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}