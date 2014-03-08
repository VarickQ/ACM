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
typedef __int64 ll;
const int inf = 2000000000;
const int M = 100000;
const int N = 1005;

int main()
{
	int T,c,n,a[3];
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		scanf("%d%d%d%d",&c,&a[0],&a[1],&a[2]);
		sort(a,a+3);
		for(int i=3 ; i < 10 ; ++i){
			scanf("%d",&n);
			if(n < a[0]) continue;
			if(n > a[2]){
				a[0]=a[1]; a[1]=a[2]; a[2]=n;
			} else if(n > a[1]){
				a[0]=a[1]; a[1] = n;
			} else if(n > a[0])
				a[0]=n;
		}
		printf("%d %d\n",c,a[0]);
	}
	return 0;
}