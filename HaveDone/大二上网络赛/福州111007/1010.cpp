#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 1000000000;
const int M = 100000;
const int N = 100005;

struct A{
	int Di,Ti;
}a[N];
bool cmp(const A a,const A b){
	return a.Ti > b.Ti;
}
int main(){
	int T,n,cs=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d",&a[i].Di,&a[i].Ti);
		sort(a,a+n,cmp);
		int t=a[0].Di,ans=a[0].Di+a[0].Ti;
		for(int i=1 ; i < n ; ++i){
			if(t+a[i].Di+a[i].Ti > ans)
				ans = t+a[i].Di+a[i].Ti;
			t += a[i].Di;
		}
		printf("Case %d: %d\n",++cs,ans);
	}
	return 0;
}