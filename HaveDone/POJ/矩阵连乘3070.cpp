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

void fen(int r[][2],int k[][2]){
	int ans[2][2];
	ans[0][0]=(r[0][0]*k[0][0]%M+r[0][1]*k[1][0]%M)%M;
	ans[0][1]=(r[0][0]*k[0][1]%M+r[0][1]*k[1][1]%M)%M;
	ans[1][0]=(r[1][0]*k[0][0]%M+r[1][1]*k[1][0]%M)%M;
	ans[1][1]=(r[1][0]*k[0][1]%M+r[1][1]*k[1][1]%M)%M;
	r[0][0]=ans[0][0],r[0][1]=ans[0][1],r[1][0]=ans[1][0],r[1][1]=ans[1][1];
}
int fbnq(int n){
	int k[2][2]={1,0,0,1};
	int r[2][2]={1,1,1,0};
	while(n > 1){
		if(n&1)
			fen(k,r);
		fen(r,r);
		n >>= 1;
	}
	fen(r,k);
	return r[0][1];
}
int main(){
	int n;
	while(scanf("%d",&n) == 1){
		if(n==-1) break;
		if(n == 0) printf("0\n");
		else printf("%d\n",fbnq(n));
	}
	return 0;
}