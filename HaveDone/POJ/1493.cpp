#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 2000;

int main(){
	int n,a[15];
	char str[26];
	while(scanf("%d",&n) == 1){
		getchar();
		if(n == 0) break;
		memset(a,0,sizeof(a));
		int max = 0;
		for(int i=0 ; i < n ; ++i)
		{
			gets(str);
			for(int j=0 ; str[j] ; ++j)
				if(str[j] == 'X')
					a[i]++;
			if(a[i] > max) max = a[i];
		}
		int ans = 0;
		for(int i=0 ; i < n ; ++i)
			ans += max - a[i];
		printf("%d\n",ans);
	}
	return 0;
}