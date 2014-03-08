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
typedef __int64 ll;
#define eps 1e-8
const int inf = 2000000000;
const int M = 10005;
const int N = 1005;

struct A{
	int v,t,next;
}e[M];
int heade[M],k;
int stack[M*10],top;
int in[N],n,m,t[N];
void add(int u,int v,int c){
	e[k].v = v;
	e[k].t = c;
	e[k].next = heade[u];
	heade[u] = k++;
}
void topsort(){
	memset(stack,0,sizeof(stack));
	top = 0;
	for(int i=0 ; i < n ; ++i){
		if(in[i] == 0){
			stack[top++] = i;
			t[i] = 1;
		}
	}
	while(top){
		int u = stack[--top];
		for(int i=heade[u] ; i!=-1 ; i=e[i].next){
			t[e[i].v] = max(t[e[i].v],t[u]+e[i].t);
			if(--in[e[i].v] == 0)
				stack[top++] = e[i].v;
		}
	}
	int ans = 0;
	for(int i=0 ; i < n ; ++i)
		ans = max(ans,t[i]);
	printf("%d\n",ans);
}
int main(){
	int a,b,c;
	while(scanf("%d%d",&n,&m) == 2){
		memset(in,0,sizeof(in));
		memset(heade,-1,sizeof(heade));
		memset(t,0,sizeof(t));
		k = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			in[b]++; t[b] = c;
		}
		topsort();
	}
	return 0;
}