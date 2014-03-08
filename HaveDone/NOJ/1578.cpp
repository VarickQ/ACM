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
#define ll long long
const int inf = (1<<30);
const ll M = 1000000007;
const int N = 1010;

char str[N],base[26];
int main() {
	int T,cs=0;
	scanf("%d\n",&T);
	while(T--){
		gets(str);
		gets(base);
		printf("%d ",++cs);
		for(int i=0 ; str[i] ; ++i){
			if(str[i]>='A' && str[i]<='Z')
				printf("%c",base[str[i]-'A']);
			else printf("%c",str[i]);
		}
		printf("\n");
	}
	return 0;
}