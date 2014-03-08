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

int ans[15];
int main(){
	int k,left,i,s;
	for(k=1 ; k < 14 ; ++k){
		for(i=k+1 ; ; ++i){
			left = 2*k-1;
			s = i%(left+1);
			if(s<=k && s!=0) continue;
			if(s==0) s=left+1;
			if(left == k) break;
			while(1){
				s = (s+i-1)%left;
				if(s <= k && s!=0) break;
				if(s==0) s=left;
				left--;
				if(left==0||left==k) break;
			}
			if(left == k) break;
		}
		ans[k] = i;
	}
	while(scanf("%d",&k) && k){
		printf("%d\n",ans[k]);
	}
	return 0;
}