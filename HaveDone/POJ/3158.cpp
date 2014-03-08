#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 102;

char a[N],b[N];
int fun(char a[],char b[]){
	int i,j,len1,len2;
	len1 = strlen(a);
	len2 = strlen(b);
	int ans = max(len1,len2);
	for(i=0 ; i < len1 ; ++i){
		bool f = false;
		for(j=i ; j<len2+i && j<len1 ; ++j)
			if(a[j]=='2' && b[j-i]=='2'){
				f=true; break;
			}
		if(!f) break;
		ans = max(ans,len2+i+1);
	}
	return ans;
}
int main(){
	int res;
	while(scanf("%s%s",a,b) != EOF){
		res=min(fun(a,b),fun(b,a));
		printf("%d\n",res);
	}
	return 0;
}
/*
2212112
2112112112

12121212
21212121

21212
2211221122
*/