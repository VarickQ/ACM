#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int N = 5000;

char num[N],ch[N];
int main(){
	int i,j,temp;
	while(scanf("%s",&ch) != EOF){
		memset(num,0,sizeof(num));
		i = j = 0;
		if(ch[0] == '-'){
			num[0] = '-';
			i = j = 1;
		}
		while(1){//cut lead zero , ~0-9
			if(ch[i]>='1' && ch[i]<='9') break;
			if(ch[i]=='0' && ch[i+1]=='\0') break;
			if(ch[i]=='0' && ch[i+1]>'9'&&ch[i+1]<'0' && ch[i+2]=='\0')
				break;
			i++;
		}
		while(ch[i] != '\0'){
			if(ch[i]<='9' && ch[i]>='0')
				num[j++] = ch[i];
			i++;
		}
		int len = j;
		if(num[0] == '-'){//-0
			if(num[1]=='0'){
				printf("0\n"); continue;
			}
			if(len <= 4) printf("%s",num);
			else {
				printf("-");
				i = len%3;
				if(i == 0){
					printf("%c%c,",num[1],num[2]);
					i = temp = 3;
				}
				else if(i == 1){
					printf("%c%c%c,",num[1],num[2],num[3]);
					i = temp = 4;
				}
				else if(i == 2){
					printf("%c,",num[1]);
					i = temp = 2;
				}
				for( ; i < len ; ++i){
					if((i-temp)%3==0 && i!=temp)printf(",");
					printf("%c",num[i]);
				}
			}
		} else {
			if(len <= 3) printf("%s",num);
			else {
				temp = len%3;
				for(i=0 ; i < temp ; ++i)printf("%c",num[i]);
				for( ; i < len ; ++i){
					if((i-temp)%3==0 && i!=0)printf(",");
					printf("%c",num[i]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}