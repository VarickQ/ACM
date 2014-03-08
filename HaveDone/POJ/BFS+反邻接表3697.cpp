#include <stdio.h>//BFS
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int inf = 2000000000;
const int M = 2000100;
const int N = 10010;

struct A{
	int v,next;
}e[M];
int heade[N],k,n,m;
int fa[N];
bool vis[N];
void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
int bfs(){
	int i,cnt=0,u;
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(i=heade[u] ; i != -1 ; i=e[i].next)
			fa[e[i].v] = u;
		for(i=1 ; i <= n ; ++i){
			if(fa[i]!=u && !vis[i]){
				vis[i]=true; cnt++; q.push(i);
			}
		}
	}
	return cnt;
}
int main(){
	int x,y,cs=0;
	while(scanf("%d%d",&n,&m) == 2){
		if(n==0 && m==0) break;
		memset(heade,-1,sizeof(heade));
		memset(vis,0,sizeof(vis));
		memset(fa,0,sizeof(fa));
		k = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		int ans = bfs();
		printf("Case %d: %d\n",++cs,ans);
	}
	return 0;
}