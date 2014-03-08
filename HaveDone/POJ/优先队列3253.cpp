#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll __int64
const int inf = 2000000000;
const int N = 10100;

struct cmp{
	bool operator()(const int &a,const int &b){
		return a > b;
	}
};
priority_queue<int,vector<int>,cmp> qu;
int main()
{
	int n,i,a,b;
	ll ans,temp;
	while(scanf("%d",&n) == 1)
	{
		while(!qu.empty()) qu.pop();
		for(i=0 ; i < n ; ++i){
			scanf("%d",&a);
			qu.push(a);
		}
		if(n==1){
			printf("%d\n",a); continue;
		}
		ans = 0;
		while(qu.size() != 1){
			a = qu.top(); qu.pop();
			b = qu.top(); qu.pop();
			temp = a+b;
			ans += temp;
			qu.push(temp);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}