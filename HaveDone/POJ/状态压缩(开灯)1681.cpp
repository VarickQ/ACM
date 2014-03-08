#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;

int mat[20][20],temp[20][20];
int main(){
	int T,n,i,j,p;
	char ch;
	scanf("%d",&T);
	while(T--){
		memset(mat,0,sizeof(mat));
		scanf("%d",&n);
		int M = 1<<n;
		for(i=1 ; i <= n ; ++i)
			for(j=1 ; j <= n ; ++j){
				scanf(" %c",&ch);
				if(ch == 'y') mat[i][j] = 1;
				else mat[i][j] = 0;
			}
		int min = inf;
		for(i=0 ; i < M ; ++i){ //枚举第一行状态
			memset(temp,0,sizeof(temp));
			int s = i;
			for(j=1 ; j <= n ; ++j){
				temp[1][j] = s&1;
				s >>= 1;
			}
			for(j=2 ; j <= n ; ++j)
				for(p=1 ; p <= n ; ++p)
					temp[j][p]=!(mat[j-1][p]^temp[j-1][p]^temp[j-2][p]^temp[j-1][p-1]^temp[j-1][p+1]);
			bool f = false;
			for(j=1 ; j <= n ; ++j)
				if(!(mat[n][j]^temp[n][j]^temp[n-1][j]^temp[n][j-1]^temp[n][j+1])){
					f = true; break;
				}
			if(f) continue;
			int sum = 0;
			for(j=1 ; j <= n ; ++j)
				for(p=1 ; p <= n ; ++p)
					if(temp[j][p]) sum++;
			if(sum < min) min = sum;
		}
		if(min==inf) printf("inf\n");
		else printf("%d\n",min);
	}
	return 0;
}