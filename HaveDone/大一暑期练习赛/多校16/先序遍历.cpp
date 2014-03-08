#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

const int N = 100010;
const __int64 inf = (1LL)<<60;
#define ll __int64

struct A{
	int l,r,c;
}node[N];
int k;
void insert(int n,int id){
	if(node[id].c < n){//right
		if(node[id].r == -1){
			node[id].r = k;
			node[k++].c = n;
		} else {
			insert(n,node[id].r);
		}
	} else {
		if(node[id].l == -1){
			node[id].l = k;
			node[k++].c = n;
		} else {
			insert(n,node[id].l);
		}
	}
}
void fun(int n){
	printf(" %d",node[n].c);
	if(node[n].l != -1)
		fun(node[n].l);
	if(node[n].r != -1)
		fun(node[n].r);
}
int main(){
	int n,m,i;
	while(scanf("%d",&n) == 1)
	{
		memset(node,-1,sizeof(node));
		k = 0;
		scanf("%d",&m);
		node[k++].c = m;
		for(i=1 ; i < n ; ++i){
			scanf("%d",&m);
			insert(m,0);
		}
		printf("%d",node[0].c);
		if(node[0].l != -1)
			fun(node[0].l);
		if(node[0].r != -1)
			fun(node[0].r);
		printf("\n");
	}
	return 0;
}