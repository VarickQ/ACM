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

int a[15][30][30];
int main(){
	int T,n;
	a[0][15][15] = 1;
	for(int k=1 ; k <= 14 ; ++k)
		for(int j=0 ; j < 30 ; ++j)
			for(int i=0 ; i < 30 ; ++i)
				a[k][i][j] = a[k-1][i-1][j]+a[k-1][i-1][j-1]+
				a[k-1][i][j-1]+a[k-1][i][j+1]+a[k-1][i+1][j+1]+a[k-1][i+1][j];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",a[n][15][15]);
	}
	return 0;
}