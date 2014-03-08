#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll __int64
const int inf = 2000000000;
const int M = 35000;
const int N = 1005;

int a[N];
int main(){
	int n,i,j,temp,get,cnt;
	while(scanf("%d",&n) && n){
		for(i=0 ; i < n ; ++i)
			scanf("%d",&a[i]);
		cnt = 1;
		while(1){
			get = temp = a[0]/2;
			a[0] /= 2;
			for(i=1 ; i < n ; ++i){
				temp = a[i]/2;
				a[i] /= 2;
				a[i] += get;
				get = temp;
			}
			a[0] += get;
			for(i=0 ; i < n ; ++i)
				if(a[i]&1) a[i]++;
			bool f = false;
			for(i=1 ; i < n ; ++i)
				if(a[i] != a[0]){
					f = true; break;
				}
			if(!f) break;
			cnt++;
		}
		printf("%d %d\n",cnt,a[0]);
	}
	return 0;
}