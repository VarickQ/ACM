#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 12;

bool cmp(const char &a,const char &b){
	return a > b;
}
int main(){
	int Max,Min,cnt,temp,l;
	char str[5];
	while(scanf("%s",str) != EOF){
		if(str[0]=='-') break;
		printf("N=%s:\n",str);
		l = strlen(str);
		if(l != 4){
			printf("No!!\n");
			continue;
		}
		bool f = false;
		cnt = 0;
		while(1){
			l = strlen(str);
			sort(str,str+l,cmp);
			sscanf(str,"%d",&Max);
			l = strlen(str);
			sort(str,str+l);
			sscanf(str,"%d",&Min);
			if(Max==Min && cnt==0) break;
			temp = Max-Min;
			cnt++;
			printf("%d-%d=%d\n",Max,Min,temp);
			if(temp==6174 || temp==0) break;
			sprintf(str,"%d",temp);
		}
		if(cnt != 0)
			printf("Ok!! %d times\n",cnt);
		else printf("No!!\n");
	}
	return 0;
}