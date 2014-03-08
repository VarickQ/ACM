#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 2000;

char str[55];
int Is(char a[]){
	if(a[0]=='\\'||a[0]=='/') return 3;//unix path
	int i;
	for(i=0 ; a[i] ; ++i)
		if(a[i]==':') break;
	i++;
	if(a[i]=='\\'&&a[i+1]=='/'||a[i]=='/'&&a[i+1]=='\\'||a[i]=='/'&&a[i+1]=='/'||a[i]=='\\'&&a[i+1]=='\\')
		return 1;//url
	return 2;//windows path
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		if(Is(str) == 1){
			printf("It's a URL!\n");
			for(int i=0 ; str[i] ; ++i){
				if(str[i]=='\\')printf("/");
				else printf("%c",str[i]);
			}
		}
		else if(Is(str) == 2){
			printf("It's a path in Windows system!\n");
			for(int i=0 ; str[i] ; ++i){
				if(str[i]=='/')printf("\\");
				else printf("%c",str[i]);
			}
		}
		else if(Is(str) == 3){
			printf("It's a path in Unix-like systems!\n");
			for(int i=0 ; str[i] ; ++i){
				if(str[i]=='\\')printf("/");
				else printf("%c",str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}