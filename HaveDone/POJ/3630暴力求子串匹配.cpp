#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define inf 100000000
#define PI 3.14159265358979323846

char num[10005][11];
int cmp(const void *a,const void *b){
	return strcmp( (char*)a, (char*)b);
}
int main(){
	int t,i,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool f = true;
		for(i=0 ; i < n ; i++)
			scanf("%s",num[i]);
		qsort(num,n,sizeof(num[0]),cmp);
		for(i=1 ; i < n ; i++)
		{
			int len1 = strlen(num[i-1]);
			int j = 0;
			while(num[i-1][j] == num[i][j]){
				j ++;
				if(j==len1){
					f = false;
					break;
				}
			}
			if(!f) break;
		}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}