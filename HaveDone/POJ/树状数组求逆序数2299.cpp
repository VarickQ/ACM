#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define N 500005

struct Node{
	int num,id;
}a[N];
int c[N],n;
bool cmp(Node a,Node b){
	return a.num < b.num;
}
int Lowbit(int t){
    return t & ( -t );
}
void Plus(int pos,int num){
	while(pos <= n){
		c[pos] += num;
		pos += Lowbit(pos);
	}
}
int Sum(int end){
	int sum = 0;
	while(end > 0){
		sum += c[end];
		end -= Lowbit(end);
	}
	return sum;
}
int main()
{
	int i;
	__int64 ans;
	while(scanf("%d",&n) && n)
	{
		memset(c,0,sizeof(c));
		for(i=1 ; i <= n ; i++){
			scanf("%d",&a[i].num);
			a[i].id = i;
		}
		sort(a+1,a+n+1,cmp);

		ans = 0;
		for(i=1 ; i <= n ; i++)
		{
			Plus(a[i].id,1);
			ans += (Sum(n)-Sum(a[i].id));
		}
		printf("%I64d\n",ans);
	}
	return 0;
}