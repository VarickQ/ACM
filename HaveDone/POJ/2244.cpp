#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-10
#define zero(x) (((x)>0?(x):-(x))<eps)
const int M = 10000;
const int N = 10002;

int main(){
	int n,left,i,s;
	while(scanf("%d",&n) && n){
		for(i=2 ; ; ++i){
			s = 0;
			left = n-1;
			while(1){
				s = (s+i-1)%left;
				if(s == 0)break;
				left--;
			}
			if(left==1) break;
		}
		printf("%d\n",i);
	}
	return 0;
}