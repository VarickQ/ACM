#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 1000000000
const int N = 910;
const int M = 500000;

struct A{
	int v,next;
}e1[M],e2[M];
int head1[N],k1,head2[N],k2;
int fa[N];
int ans[N],n;
bool vis[N],root[N];
void add1(int u,int v){
	e1[k1].v = v;
	e1[k1].next = head1[u];
	head1[u] = k1++;
}
void add2(int u,int v){
	e2[k2].v = v;
	e2[k2].next = head2[u];
	head2[u] = k2++;
}
void init(){
	memset(head1,-1,sizeof(head1));
	memset(head2,-1,sizeof(head2));
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
	memset(root,true,sizeof(root));
	for(int i=1 ; i <= n ; i++)fa[i]=i;
	k1 = k2 = 0;
}
int find_set(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find_set(fa[x]);
}
void dfs(int u){
	for(int i=head1[u] ; i!=-1 ; i=e1[i].next)
	{
		int son = e1[i].v;
		dfs(son);
		fa[son] = u;//union
	}
	vis[u] = true;
	for(int i=head2[u] ; i!=-1 ; i=e2[i].next)
	{
		int son = e2[i].v;
		if(vis[son])
			ans[find_set(son)]++;
	}
}
int main()
{
	int q,u,k,v,i,j;
	while(scanf("%d",&n) == 1)
	{
		init();
		for(i=0 ; i < n ; i++){
			scanf("%d:(%d)",&u,&k);
			for(j=0 ; j < k ; j++){
				scanf("%d",&v);
				add1(u,v);
				root[v] = false;
			}
		}
		scanf("%d",&q);
		while(q--)
		{
			while(getchar()!='(');
			scanf("%d%d",&u,&v);
			add2(u,v);
			add2(v,u);
		}
		while(getchar()!=')');
		for(i=1 ; i <= n ; i++)
			if(root[i]){
				dfs(i); break;
			}
		for(i=1 ; i <= n ; i++)
			if(ans[i] > 0)
				printf("%d:%d\n",i,ans[i]);
	}
	return 0;
}
