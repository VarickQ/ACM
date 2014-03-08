#include <stdio.h>
#include <math.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 10000000;
const int N = 10005;

struct A{
	int v,c,next;
}e[N*5];
int k,end,heade[N],d[N];
int qu[N*100];
bool inqu[N];

void add(int u,int v,int w){
	e[k].v = v;
	e[k].c = w;
	e[k].next = heade[u];
	heade[u] = k++;
}

void spfa(){
	for(int i=1 ; i <= end ; i++)
		d[i] = -inf;
	d[0] = 0;
	int head=0,tail=1;
	qu[0] = 0;
	while(tail > head){
		int u = qu[head];
		inqu[u] = true;
		for(int i=heade[u] ; i != 0 ; i=e[i].next){
			int v = e[i].v;
			if(d[v] < d[u] + e[i].c){
				d[v] = d[u] + e[i].c;
				if(!inqu[v]){
					inqu[v] = true;
					qu[tail++] = v;
				}
			}
		}
		inqu[u]=false;
		head++;
	}
}
int main()
{
	int i,a,b,n;
	end = 0;
	k = 1;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		if(b+1 > end)end = b+1;
		add(a,b+1,2);
	}
	for(i=0 ; i <= end ; i++)
	{
		add(i,i+1,0);
		add(i+1,i,-1);
	}
	spfa();
	printf("%d\n",d[end]);
	return 0;
}