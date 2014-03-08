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
	int T,cs;
	char str[N];
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&cs,str);
		next_permutation(str,str+strlen(str));
		printf("%d ",cs);
		bool f = false;
		for(int i=1 ; str[i] ; ++i)
			if(str[i] < str[i-1]){
				f = true; break;
			}
		if(f) printf("%s\n",str);
		else printf("BIGGEST\n");
	}
	return 0;
}