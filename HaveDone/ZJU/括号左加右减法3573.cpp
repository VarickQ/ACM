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
const int inf = 1000000000;
const int N   = 15005;

int c[N],c2[N],n;
int main(){
	int a,b,d;
	while(scanf("%d", &n) == 1){
		memset( c, 0, sizeof( c ) );
		memset( c2, 0, sizeof( c2 ) );
		while( 1 ){
			scanf("%d%d%d",&a,&b,&d);
			if( a == -1 ) break;
			c[a] += d;
			if(a>0)c2[a-1] += -d;
			c[b+1] += -d;
			c2[b] += d;
		}
		int Max=0,temp=0,pos;
		for(int i=0 ; i <= n ; ++i){
			if( c[i] != 0 ){
				temp += c[i];
				if( temp > Max ){
					Max = temp; pos = i;
				}
			}
		}
		printf("%d ", pos);
		Max = temp = pos = 0;
		for(int i=n ; i >= 0 ; --i){
			if( c2[i] != 0 ){
				temp += c2[i];
				if( temp > Max ){
					Max = temp; pos = i;
				}
			}
		}
		printf("%d\n", pos);
	}
	return 0;
}