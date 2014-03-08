#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 1000000000;
const int N = 1000001;

bool Is[N];
int main(){
	int a,b,ans;
	char str[10];
	for(int i=1 ; i <= N-1 ; ++i){
		sprintf(str,"%d",i);
		for(int j=0 ; str[j] ; ++j){
			if(str[j] == '4'){
				Is[i] = true; break;
			}
			if( j != 0 ){
				if(str[j-1]=='6' && str[j]=='2'){
					Is[i] = true; break;
				}
			}
		}
	}
	while(scanf("%d%d",&a,&b) && (a+b)){
		ans = 0;
		for(int i=a ; i <= b ; ++i)
			if(!Is[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}