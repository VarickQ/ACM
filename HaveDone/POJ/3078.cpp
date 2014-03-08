#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
const int N = 25;

int a[N],b[N];
char str[N][10];
int main(){
	int T,m,n,s,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&m,&n);
		for(int i=1 ; i <= m ; ++i){
			scanf("%s",str[i]);
			a[i] = i; b[i] = 0;
		}
		for(int i=0 ; i < n ; ++i){
			scanf("%d%d",&s,&t);
			b[t] = a[s];
			a[s] = 0;
		}
		for(int i=1 ; i <= m ; ++i)
			if(a[i] != 0)
				for(int j=1 ; j <= m ; ++j)
					if(b[j] == 0){
						b[j] = a[i]; break;
					}
		for(int i=1 ; i < m ; ++i)
			printf("%s ",str[b[i]]);
		printf("%s\n",str[b[m]]);
	}
	return 0;
}