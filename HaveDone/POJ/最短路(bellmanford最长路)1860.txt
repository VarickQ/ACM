#include <stdio.h>
#include <math.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1005
struct A{
	int u,v;
	double r,c;
}e[N];
int n,m,s,k;
double d[N],v;
void add(int u,int v,double r,double c){
	e[k].r = r;
	e[k].c = c;
	e[k].u = u;
	e[k++].v = v;
}
bool bellmanford(){
	int i,j;
	memset(d,0,sizeof(d));
	d[s] = v;
	for(j=0 ; j < n ; j++){//最长路
		int f = 0;
		for(i=0 ; i < k ; i++){
			int x=e[i].u,y=e[i].v;
			if(d[y] < (d[x]-e[i].c)*e[i].r){
				d[y] = (d[x]-e[i].c)*e[i].r;
				f = 1;
			}
		}
		if(!f)break;
	}
	for(i=0 ; i < k ; i++)//判断时候有正环
	{
		int x=e[i].u,y=e[i].v;
		if(d[y] < (d[x]-e[i].c)*e[i].r){
			d[y] = (d[x]-e[i].c)*e[i].r;
			return true;//找到正环路
		}
	}
	return false;
}
int main()
{
	int i,a,b;
	double r1,c1,r2,c2;
	while(scanf("%d%d%d%lf",&n,&m,&s,&v)!=EOF)
	{
		for(i=0,k=0 ; i < m ; i++)
		{
			scanf("%d%d%lf%lf%lf%lf",&a,&b,&r1,&c1,&r2,&c2);
			add(a,b,r1,c1);
			add(b,a,r2,c2);
		}
		if(bellmanford())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}