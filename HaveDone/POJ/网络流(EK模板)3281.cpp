#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 2000000000
const int M = 10005;
//http://blog.sina.com.cn/s/blog_6635898a0100ly5j.html ½¨Í¼ÊÇ¹Ø¼ü
struct A{
	int v,w,next,re;
}a[M];
int N,D,F,n,ans;
int heade[M],k;
int qu[M],pre[405];
bool vis[405];
void add(int u,int v){
	a[k].v = v;
	a[k].w = 1;
	a[k].next = heade[u];
	a[k].re = k+1;
	heade[u] = k++;

	a[k].v = u;
	a[k].w = 0;
	a[k].next = heade[v];
	a[k].re = k-1;
	heade[v] = k++;
}
bool EK(){
	int head,tail,i,u,v;
	memset(vis,0,sizeof(vis));
	head = tail = 0;
	qu[tail++] = 0;
	vis[0] = true;
	while(head < tail){
		u = qu[head++];
		for(i=heade[u] ; i!=-1 ; i=a[i].next){
			v = a[i].v;
			if(!vis[v] && a[i].w){
				pre[v] = i;
				if(v==n) return true;
				qu[tail++] = v;
				vis[v] = true;
			}
		}
	}
	return false;
}
void end(){
	for(int u=n ; u != 0 ; u=a[a[k].re].v){
		k = pre[u];
		a[k].w -= 1;
		a[a[k].re].w += 1;
	}
	ans ++;
}
int main()
{
	int f,d,u;
	while(scanf("%d%d%d",&N,&F,&D) != EOF)
	{
		memset(heade,-1,sizeof(heade));
		k = 0;
		n = F+2*N+D+1;
		for(int i=1 ; i <= F ; i++)
			add(0,i);
		for(int i=F+1 ; i <= F+N ; i++)
			add(i,i+N);
		for(int i=F+2*N+1 ; i <= F+2*N+D ; i++)
			add(i,n);
		for(int i=1 ; i <= N ; i++){
			scanf("%d%d",&f,&d);
			for(int j=0 ; j < f ; j++){
				scanf("%d",&u);
				add(u,F+i);
			}
			for(int j=0 ; j < d ; j++){
				scanf("%d",&u);
				add(F+N+i,F+2*N+u);
			}
		}
		ans = 0;
		while(EK())end();
		printf("%d\n",ans);
	}
	return 0;
}