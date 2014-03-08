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
const int N = 1010;

char base[62]={
	'0','1','2','3','4','5','6','7','8','9',
	'A','B','C','D','E','F','G','H','I','J',
	'K','L','M','N','O','P','Q','R','S','T',
	'U','V','W','X','Y','Z','a','b','c','d',
	'e','f','g','h','i','j','k','l','m','n',
	'o','p','q','r','s','t','u','v','w','x',
	'y','z'};
char str[N],s[N];
int main() {
	int T,ib,ob;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&ib,&ob,str);
		printf("%d %s\n%d ",ib,str,ob);
		int len = strlen(str);
		for(int i=0 ; i < len ; ++i){
			if(str[i]>='0' && str[i]<='9')
				s[i] = str[i]-'0';
			else if(str[i]>='A' && str[i]<='Z')
				s[i] = str[i]-55;
			else if(str[i]>='a' && str[i]<='z')
				s[i] = str[i]-61;
		}
		int num,k,t=0;
		bool f;
		while(len > 0){
			num = k = 0;
			f = false;
			for(int i=0 ; i < len ; ++i){
				num = num*ib+s[i];
				if(num >= ob) f = true;
				if(f) s[k++] = num/ob;
				num %= ob;
			}
			str[t++] = num;
			len = k;
		}
		for(int i=--t ; i >= 0 ; --i)
			printf("%c",base[str[i]]);
		printf("\n\n");
	}
	return 0;
}