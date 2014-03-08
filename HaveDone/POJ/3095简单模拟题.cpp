#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 10010;

int main()
{
	char str[85];
	int i,j,res;
	bool f;
	while(scanf("%s",str) != EOF)
	{
		if(str[0] == '#') break;
		int len = strlen(str);
		res = 0;
		for(i=0 ; str[i] ; ++i)
		{
			if(str[i]=='_')continue;
			else if(str[i]=='.')res += 100;
			else if(str[i]=='/'){
				f = false;
				for(j=i-1 ; j >= 0 ; --j){
					if(str[j]=='_')continue;
					else if(str[j]=='|' || str[j]=='\\' || str[j]=='/'){
						f = true; break;
					}
					else if(str[j]=='.'){
						res += 100; break;
					}
				}
				if(j<=0 && !f && str[0]!='.')res += 100;
			}
			else if(str[i]=='\\'){
				f = false;
				for(j=i+1 ; j < len ; ++j){
					if(str[j]=='_')continue;
					else if(str[j]=='|' || str[j]=='\\' || str[j]=='/'){
						f = true; break;
					}
					else if(str[j]=='.'){
						res += 100; break;
					}
				}
				if(j>=len-1 && !f && str[len-1]!='.')res += 100;
			}
			else if(str[i]=='|'){
				f = false;
				for(j=i-1 ; j >= 0 ; --j){
					if(str[j]=='_')continue;
					else if(str[j]=='|' || str[j]=='\\' || str[j]=='/'){
						f = true; break;
					}
					else if(str[j]=='.'){
						res += 50; break;
					}
				}
				if(j<=0 && !f && str[0]!='.')res += 50;

				f = false;
				for(j=i+1 ; j < len ; ++j){
					if(str[j]=='_')continue;
					else if(str[j]=='|' || str[j]=='\\' || str[j]=='/'){
						f = true; break;
					}
					else if(str[j]=='.'){
						res += 50; break;
					}
				}
				if(j>=len-1 && !f && str[len-1]!='.')res += 50;
			}
		}
		printf("%d\n",res/len);
	}
	return 0;
}