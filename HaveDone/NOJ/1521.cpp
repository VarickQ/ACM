#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct A{
	int k,v,p;
}a[10005];
bool cmp(const A a,const A b){
	if(a.v != b.v)
		return a.v > b.v;
	else if(a.k != b.k)
		return a.k > b.k;
	return a.p < b.p;
	
}
int main(){
	int n;
	while(scanf("%d",&n) == 1){
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d%d",&a[i].k,&a[i].v,&a[i].p);
		sort(a,a+n,cmp);
		for(int i=0 ; i < n ; ++i)
			printf("%d\n",a[i].p);
	}
	return 0;
}