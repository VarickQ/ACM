//A
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 10005;

int mi,ma,a[20],b[20][20],ans;
void xinqin(int tt){
	int x;
	for(int i=0 ; i < a[0] ; ++i)//t
		for(int j=0 ; j < a[1] ; ++j){//f
			x = tt+b[0][i]+b[1][j];
			if( x <= ma && x >= mi)
				ans ++;
		}
	for(int i=0 ; i < a[2] ; ++i){//m
		x = tt+b[2][i];
		if( x <= ma && x >= mi )
			ans ++;
	}
}
int main(){
	int T,temp;
	scanf("%d", &T);
	while( T-- ){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0 ; i < 5 ; ++i)
			scanf("%d", &a[i]);
		for(int i=0 ; i < 5 ; ++i){
			for(int j=0 ; j < a[i] ; ++j){
				scanf("%d", &b[i][j]);
			}
		}
		scanf("%d %d", &mi, &ma);
		ans = 0;
		//1h1s
		for(int i=0 ; i < a[3] ; ++i)//h
			for(int j=0 ; j < a[4] ; ++j){//s
				temp = b[3][i]+b[4][j];
				xinqin(temp);
			}
		//1h2s
		for(int i=0 ; i < a[3] ; ++i)//h
			for(int j=0 ; j < a[4] ; ++j)//s
				for(int s=j+1 ; s < a[4] ; ++s){
					temp = b[3][i]+b[4][j]+b[4][s];
					xinqin(temp);
				}
		//2h1s
		for(int i=0 ; i < a[3] ; ++i)//h
			for(int h=i+1 ; h < a[3] ; ++h)
				for(int j=0 ; j < a[4] ; ++j){//s
					int temp = b[3][i]+b[3][h]+b[4][j];
					xinqin(temp);
				}
		//2h2s
		for(int i=0 ; i < a[3] ; ++i)//h
			for(int h=i+1 ; h < a[3] ; ++h){
				for(int j=0 ; j < a[4] ; ++j)
					for(int s=j+1 ; s < a[4] ; ++s){
						int temp = b[3][i]+b[3][h]+b[4][j]+b[4][s];
						xinqin(temp);
					}
			}
		printf("%d\n", ans);
	}
	return 0;
}
//F
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 10005;

int stack[N],top;
int main(){
	int T,n,m,now;
	char ss[25];
	scanf("%d", &T);
	while( T-- ){
		top = 0;
		stack[top++] = 1;
		now = 1;
		scanf("%d%d", &n, &m);
		for(int i=0 ; i < m ; ++i){
			scanf("%s", ss);
			if(!strcmp(ss,"PRE")){
				if(top==0 || top==1){
					printf("1\n");
					now = 1;
					stack[top++] = now;
				} else {
					top--;
					printf("%d\n",stack[top-1]);
					now = stack[top-1];
				}
			}
			else if(!strcmp(ss,"PLAY")){
				int x;
				scanf("%d", &x);
				printf("%d\n", x);
				now = x;
				if(stack[top-1] != x)
					stack[top++] = x;
			}
			else if(!strcmp(ss,"NEXT")){
				if( now == n ) printf("%d\n",n);
				else{
					now++;
					printf("%d\n", now);
					if(now != stack[top-1])
						stack[top++] = now;
				}
			}
		}
	}
	return 0;
}