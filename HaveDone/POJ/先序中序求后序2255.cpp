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

char pre[30],in[30];
int find(char ch,int i,int n){
	for( ; i <= n ; ++i)
		if(ch==in[i]) return i;
}
void slove(int s1,int end1,int s2,int end2){
	if(s2 > end2) return ;
	if(end2 == s2){
		printf("%c",in[s2]);
		return ;
	}
	int l = find(pre[s1],s2,end2);
	slove(s1+1,s1+l-s2,s2,l-1);
	slove(s1+l+1-s2,end1,l+1,end2);
	printf("%c",pre[s1]);
}
int main(){
	while(scanf("%s%s",pre,in) != EOF){
		slove(0,strlen(pre)-1,0,strlen(in)-1);
		printf("\n");
	}
	return 0;
}