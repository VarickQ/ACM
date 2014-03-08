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
typedef __int64 ll;
const int inf = 2000000000;
const int M = 100000;
const int N = 20005;

struct Node{
	int num,id;
}a[N];
int c[N],n,ls[N],rs[N],lb[N],rb[N];
bool cmp1(Node a,Node b){
	return a.num < b.num;
}
bool cmp2(Node a,Node b){
	return a.num > b.num;
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
	int i,j,T;
	__int64 ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(ls,0,sizeof(ls));
		memset(lb,0,sizeof(lb));
		memset(rs,0,sizeof(rs));
		memset(rb,0,sizeof(rb));
		for(i=1 ; i <= n ; i++){
			scanf("%d",&a[i].num);
			a[i].id = i;
		}

		memset(c,0,sizeof(c));
		sort(a+1,a+n+1,cmp1);
		for(i=1 ; i <= n ; i++){
			Plus(a[i].id,1);
			ls[i] = Sum(a[i].id)-1;
			lb[i] = (Sum(n)-Sum(a[i].id));
		}
		memset(c,0,sizeof(c));
		sort(a+1,a+n+1,cmp2);
		for(j=n,i=1 ; i <= n ; i++,j--){
			Plus(a[i].id,1);
			rs[j] = Sum(a[i].id)-1;
			rb[j] = (Sum(n)-Sum(a[i].id));
		}

		ans = 0;
		for(i=1 ; i <= n ; ++i)
			ans += ls[i]*rb[i]+lb[i]*rs[i];
		printf("%I64d\n",ans);
	}
	return 0;
}