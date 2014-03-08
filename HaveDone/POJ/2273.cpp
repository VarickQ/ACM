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
const int M = 2000100;
const int N = 10010;

int main(){
	int row,col,temp,k,i;
	char str[500],ans[50];
	while(scanf("%s",str) != EOF)
	{
		k = 0;
		for(i=1 ; str[i]!='C' ; ++i)
			ans[k++] = str[i];
		ans[k] = '\0';
		sscanf(ans,"%d",&row);
		k = 0;
		for(i=i+1 ; str[i] ; ++i)
			ans[k++] = str[i];
		ans[k] = '\0';
		sscanf(ans,"%d",&col);
		if(row==0 && col==0) break;
		k = 0;
		while(col){
			temp = col%26;
			col /= 26;
			if(temp==0){
				col--; ans[k++]='Z';
			} else ans[k++] = temp-1+'A';
		}
		for(i=k-1 ; i >= 0 ; --i)
			printf("%c",ans[i]);
		printf("%d\n",row);
	}
	return 0;
}