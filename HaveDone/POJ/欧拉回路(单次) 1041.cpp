#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2005;

struct A{
	int v,next,id;
	bool vis;
}e[N*10];
int heade[N],k,vis[N],ans[N],n,du[N];
void add(int u,int v,int z){
	e[k].id = z;
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
void dfs(int u){
	for(int i=heade[u] ; i!=-1 ; i=e[i].next)
	{
		if(!vis[e[i].id]){
			vis[e[i].id] = true;
			dfs(e[i].v);
			ans[n++] = e[i].id;
		}
	}
}
int main()
{
	int x,y,z,mx=0;
	memset(heade,-1,sizeof(heade));
	while(scanf("%d%d",&x,&y) == 2)
	{
		if(x==0&&y==0&&k==0)break;
		if(x==0&&y==0){
			bool f = 0;
			for(int i=1 ; i <= mx ; i++)
				if(du[i]&1){
					f = 1; break;
				}
			if(f) printf("Round trip does not exist.\n");
			else {
				dfs(1);
				for(int i=0 ; i < n-1 ; i++)
					printf("%d ",ans[i]);
				printf("%d\n",ans[n-1]);
			}
			memset(du,0,sizeof(du));
			memset(vis,0,sizeof(vis));
			memset(heade,-1,sizeof(heade));
			mx=k=n=0; continue;
		}
		scanf("%d",&z);
		add(x,y,z);
		add(y,x,z);
		du[x]++; du[y]++;
		mx = max(x,y);
	}
	return 0;
}