#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
#define N 400000
char str[N];
int next[N],ans[N];
void NEXT(char *str){
    int i = 0,j = -1;
    next[0] = -1;
    int len = strlen(str);
	while(i < len){
        if(j == -1 || str[i] == str[j])
            ++i,++j,next[i] = j;
		else j = next[j];
    }
}
int main() {
	int i,j;
	while(scanf("%s",str) != EOF)
	{
		NEXT(str);
		int len=strlen(str);
		for(i=len,j=0 ; next[i]!=-1 ; ){
			ans[j++]=i; i=next[i];
		}
		j--;
		printf("%d",ans[j--]);
		for(; j >= 0 ; j--)
			printf(" %d",ans[j]);
		printf("\n");
	}
    return 0;
}