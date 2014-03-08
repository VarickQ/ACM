#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 2000000000;
const int N = 100010;

int cnt[26];
int main(){
	int n,m,p;
	while(scanf("%d%d%d",&n,&m,&p) != EOF){
		memset(cnt,0,sizeof(cnt));
		char ch;
		for(int i=0 ; i < n ; ++i)
			for(int j=0 ; j < m ; ++j){
				scanf(" %c",&ch);
				cnt[ch-'A']++;
			}
		char str[102];
		for(int i=0 ; i < p ; ++i){
			scanf("%s",str);
			for(int j=0 ; str[j] ; ++j)
				cnt[str[j]-'A']--;
		}
		for(int i=0 ; i < 26 ; ++i)
			while(cnt[i]--){
				printf("%c",i+'A');
			}
		printf("\n");
	}
	return 0;
}