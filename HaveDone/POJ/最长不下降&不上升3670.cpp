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
const int N = 30005;

int a[N],p[N],n;
int LIS1(){//up
	int l,r,len = 1;
	p[1] = a[1];
	for(int i=2 ; i <= n ; ++i){
		if(a[i] >= p[len])
			p[++len] = a[i];
		else {
			l = 1; r = len;
			while(l <= r){
				int mid = (l+r)/2;
				if(a[i] >= p[mid]) l = mid+1;
				else r = mid-1;
			}
			p[l] = a[i];
		}
	}
	return len;
}
int LIS2(){//down
	int l,r,len = 1;
	p[1] = a[1];
	for(int i=2 ; i <= n ; ++i){
		if(a[i] <= p[len])
			p[++len] = a[i];
		else {
			l = 1; r = len;
			while(l <= r){
				int mid = (l+r)/2;
				if(a[i] <= p[mid]) l = mid+1;
				else r = mid-1;
			}
			p[l] = a[i];
		}
	}
	return len;
}
int main(){
	int ans;
	while(scanf("%d",&n) == 1){
		memset(p,0,sizeof(p));
		for(int i=1 ; i <= n ; ++i)
			scanf("%d",&a[i]);
		int len = LIS1();
		ans = n-len;
		memset(p,0,sizeof(p));
		len = LIS2();
		ans = min(ans,n-len);
		printf("%d\n",ans);
	}
	return 0;
}