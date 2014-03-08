#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

char str[105];
int main(){
	int T,A,E,I,O,U;
	scanf("%d\n",&T);
	while(T--){
		A = E = I = O = U = 0;
		gets(str);
		//getchar();
		for(int i=0 ; str[i] ; ++i){
			if(str[i] == 'a') A++;
			if(str[i] == 'e') E++;
			if(str[i] == 'i') I++;
			if(str[i] == 'o') O++;
			if(str[i] == 'u') U++;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",A,E,I,O,U);
		if(T) printf("\n");
	}
	return 0;
}