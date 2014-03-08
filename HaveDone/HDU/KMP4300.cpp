#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int N   = 100005;
const int MOD = 100000007;
typedef long long LL;

char str[30],s[N],s2[N];
int next[N];
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
int KMP(char *cs,char *str){
    int i = 0, j = 0;
    int s1 = strlen(cs); //Ö÷´®
    int s2 = strlen(str); //Æ¥Åä´®
	while(i < s1 && j < s2){
		if(j == -1 || cs[i] == str[j]){
			i ++,j ++;
		}
		else j = next[j];
	}
	return j;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int T, len;
	scanf("%d", &T);
	while( T-- ){
		scanf("%s%s", str, s);
		len = strlen(s);
		printf("%s", s);
		strcpy(s2,s+(len+1)/2);
		for(int i=0 ; i < len ; ++i)
			for(int j=0 ; j < 26 ; ++j)
				if( str[j] == s[i] ){
					s[i] = j+'a';
					break;
				}
		NEXT(s);
		int pos = KMP(s2,s);
		for(int i=pos ; i < len-pos ; ++i)
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}