#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;
#define ll __int64
const int inf = (1<<30);
const ll M = 1000000007;
const int N = 1000010;

char str[260];
bool check(int start,int end){
	if(start == end){
		if(str[start]<='z' && str[start]>='p')
			return true;
		else return false;
	} else {
		if(str[start]=='N' && check(start+1,end))
			return true;
		else if(str[start]=='C' || str[start]=='D' || str[start]=='E' || str[start]=='I'){
			for(int i=start+1 ; i <= end ; ++i)
				if(check(start+1,i) && check(i+1,end))
					return true;
			return false;
		}
		else return false;
	}
}
int main(){
	int len;
	while(scanf("%s",str) != EOF){
		len = strlen(str);
		if( check(0,len-1) )
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}