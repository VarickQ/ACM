#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
#define N 1000002
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
	int n,i,j,css=1;
	while(scanf("%d",&n) && n)
	{
		scanf("%s",str);
		printf("Test case #%d\n",css++);
		NEXT(str);
		for(i=2 ; i <= n ; i++)
		{
			j = i-next[i];/*计算首尾重复子串的长度*/
			if(i%j==0 && i/j > 1)//重复至少2次
				printf("%d %d\n",i,i/j);
		}
		printf("\n");
	}
    return 0;
}