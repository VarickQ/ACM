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
#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int inf = 2000000000;
const int M = 55;
const int N = 102;

bool mark[N];
int num[N][10];
int main(){
	int n,k,i,temp;
	for(i=2 ; i <= 100 ; ++i){
		//printf("%d\n\t",i);////
		memset(mark,0,sizeof(mark));
		temp = 1;
		while(temp && !mark[temp]){
			mark[temp] = true;
			temp *= 10;
			num[i][temp/i]++;
			//printf("%d",temp/i);//////
			temp %= i;
		}
		//printf("\n");//////
	}
	while(scanf("%d%d",&n,&k) != EOF){
		int cnt = 0;
		for(int i=2 ; i <= n ; ++i)
			cnt += num[i][k];
		printf("%d\n",cnt);
	}
	return 0;
}