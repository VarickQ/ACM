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
const int inf = (1<<30);
const ll M = 1000000007;
const int N = 1010;

struct A{
	char name[50];
	int num,pub;
}a[N];
bool cmp(const A &a,const A &b){
	if(a.num == b.num) return a.pub < b.pub;
	return a.num > b.num;
}
int main() {
	int n,c,p;
	while(scanf("%d",&n) == 1)
	{
		memset(a,0,sizeof(a));
		for(int i=0 ; i < n ; ++i){
			scanf("%s",a[i].name);
			for(int j=0 ; j < 4 ; ++j){
				scanf("%d%d",&c,&p);
				if(p != 0){
					a[i].num++;
					a[i].pub += p+(c-1)*20;
				}
			}
		}
		sort(a,a+n,cmp);
		printf("%s %d %d\n",a[0].name,a[0].num,a[0].pub);
	}
	return 0;
}