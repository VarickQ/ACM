#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const ll inf = (1LL<<63-1);
const ll M = 1000000007;
const int N = 1005;

int a[N];
bool cmp(const int &a,const int &b){
	return a > b;
}
int main(){
	int T,n,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0 ; i < n ; ++i)
			scanf("%d",&a[i]);
		t = n;
		while(t){
			sort(a,a+n,cmp);
			for(int i=1 ; i < n ; ++i){
				if(a[i] > 0 && a[0] > 0){
					a[0]--; a[i]--;
				}
				else break;
			}
			if(a[0]!=0) break;
			t--;
		}
		if(t==0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}