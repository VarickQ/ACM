#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long

char str[10002],cs[1000002];
int next[10002];
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
void KMP(){
    int i = 0, j = 0;
    int s1 = strlen(cs); //主串
    int s2 = strlen(str); //匹配串
	int ans = 0;
	while(cs[i]){//找完主串的每个字符
		while(i < s1 && j < s2){
			if(j == -1 || cs[i] == str[j])
				i ++,j ++;
			else j = next[j];
		}
		if(j == s2){//找到匹配
			ans++;
			j = next[j];//继续找下一个
		}
	}
	printf("%d\n",ans);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",str,cs);
		NEXT(str);
		KMP();
	}
    return 0;
}