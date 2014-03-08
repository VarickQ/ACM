#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 2000;

int a[22],state[22];
int main(){
	int n,m,c,b,cs=0;
	while(scanf("%d%d%d",&n,&m,&c) == 3){
		if(n==0 && m==0 && c==0) break;
		memset(state,0,sizeof(state));
		for(int i=1 ; i <= n ; ++i)
			scanf("%d",&a[i]);
		int max = 0,now = 0;
		bool f = false;
		for(int i=0 ; i < m ; ++i){
			scanf("%d",&b);
			if(f) continue;
			if(state[b]){
				state[b] = false;
				now -= a[b];
			} else {
				state[b] = true;
				now += a[b];
			}
			if(now > c) f = true;
			max = now>max?now:max;
		}
		printf("Sequence %d\n",++cs);
		if(f) printf("Fuse was blown.\n\n");
		else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",max);
	}
	return 0;
}