#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;
#define ll __int64
const int inf = (1<<30);
const ll M = 1000000007;
const int N = 1000010;

char str[75],ans[75];
int main(){
	int k,temp,len;
	while(scanf("%d",&k) && k){
		scanf("%s",str);
		len = strlen(str);
		for(int i=0 ; i < len ; ++i){
			if(str[i] == '_')
				temp = 0;
			else if(str[i] == '.')
				temp = 27;
			else temp = str[i]-'_'-1;
			//ciphercode[i] = (plaincode[ki mod n] - i) mod 28.
			int t = (temp+i)%28;
			if(t == 0)
				ans[(k*i)%len] = '_';
			else if(t == 27)
				ans[(k*i)%len] = '.';
			else ans[(k*i)%len] = 'a'-1+t;
		}
		for(int i=0 ; i < len ; ++i)
			printf("%c",ans[i]);
		printf("\n");
	}
    return 0;
}