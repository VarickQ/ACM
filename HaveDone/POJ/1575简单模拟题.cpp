#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 10010;

bool check(char ch){
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		return true;
	return false;
}
int main()
{
	char str[25];
	int i,j,res;
	bool f;
	while(scanf("%s",str) != EOF)
	{
		if(!strcmp(str,"end")) break;
		int len = strlen(str);
		f = false;
		for(i=0 ; i < len ; ++i)
			if(check(str[i])){
				f = true; break;
			}
		if(f){
			for(i=0 ; i < len-2 ; ++i){
				if(check(str[i])&&check(str[i+1])&&check(str[i+2]) ||
					!check(str[i])&&!check(str[i+1])&&!check(str[i+2])){
					f = false; break;
				}
			}
		}
		if(f){
			for(i=0 ; i < len-1 ; ++i)
				if(str[i]==str[i+1] && str[i]!='e' && str[i]!='o'){
					f = false; break;
				}
		}
		if(f)printf("<%s> is acceptable.\n",str);
		else printf("<%s> is not acceptable.\n",str);
	}
	return 0;
}