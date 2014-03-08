#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-10
#define zero(x) (((x)>0?(x):-(x))<eps)
const int M = 1000;
const int N = 10002;

struct A{
	int v,next;
}e[N];
int heade[N],k,n;
int stack[N],top;
int in[N];
void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
void topsort(){
	memset(stack,0,sizeof(stack));
	top = 0;
	bool f = false;
	for(int i=1 ; i <= n ; ++i){
		if(in[i] == 0){
			stack[top++] = i;
			if(!f){
				printf("%d",i); f=true;
			} else printf(" %d",i);
		}
	}
	while(top){
		int u = stack[--top];
		for(int i=heade[u] ; i!=-1 ; i=e[i].next){
			if(--in[e[i].v] == 0){
				stack[top++] = e[i].v;
				printf(" %d",e[i].v);
			}
		}
	}
}
int main(){
	int m;
	while(scanf("%d",&n) == 1){
		memset(heade,-1,sizeof(heade));
		memset(in,0,sizeof(in));
		k = 0;
		for(int i=1 ; i <= n ; ++i)
			while(scanf("%d",&m) && m){
				add(i,m);
				in[m]++;
			}
		topsort();
		printf("\n");
	}
	return 0;
}