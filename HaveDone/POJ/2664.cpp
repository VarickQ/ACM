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
typedef long long ll;
const int M = 10100;
const int N = 10000;

bool mark[N];
int main(){
	int k,m,n,c,r;
	while(scanf("%d",&k) && k){
		scanf("%d",&m);
		memset(mark,0,sizeof(mark));
		for(int i=0 ; i < k ; ++i){
			scanf("%d",&n);
			mark[n] = true;
		}
		int cnt,ans=0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d",&c,&r);
			cnt = 0;
			for(int j=0 ; j < c ; ++j){
				scanf("%d",&n);
				if(mark[n]) cnt++;
			}
			if(cnt >= r) ans++;
		}
		if(ans < m) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}