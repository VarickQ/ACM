#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int N = 1005;
const int MOD = 1000000007;
typedef long long ll;

int n,m,K;
struct Edge{
	int v,c,next;
}ez[N*100],ef[N*100];
int heade1[N],k1,heade2[N],k2;
int dis[N],cnt[N];
bool vis[N];
struct Node{
	int f,g,v;
	Node(){}//构造函数
	Node(int ff,int gg,int vv):f(ff),g(gg),v(vv){}
	bool operator < (const Node &a) const{
		return f > a.f;//从小到大
	}
};
void addz(int u,int v,int c){
	ez[k1].c = c;
	ez[k1].v = v;
	ez[k1].next = heade1[u];
	heade1[u] = k1++;
}
void addf(int u,int v,int c){
	ef[k2].c = c;
	ef[k2].v = v;
	ef[k2].next = heade2[u];
	heade2[u] = k2++;
}
void init(){
	CLR( heade1, -1 );
	CLR( heade2, -1 );
	k1 = k2 = 0;
}
void dijkstra(int s){
	CLR( vis, 0 );
	for(int i=1 ; i <= n ; ++i) dis[i] = inf;
	dis[s] = 0;
	for(int i=1 ; i <= n ; ++i)
	{
		int x,Min = inf;
		for(int y=1 ; y <= n ; ++y)
			if( !vis[y] && dis[y] <= Min ){
				Min = dis[y];
				x = y;
			}
		vis[x] = true;
		for(int i=heade2[x] ; i!=-1 ; i=ef[i].next){
			if( dis[ef[i].v] > dis[x] + ef[i].c )
				dis[ef[i].v] = dis[x] + ef[i].c;
		}
	}
}
int Astar(int s,int t){
	priority_queue<Node> qu;
	if( dis[s] == inf ) return -1;
	CLR( cnt, 0 );
	qu.push( Node( dis[s], 0, s ) );
	while( !qu.empty() ){
		Node tmp,cur = qu.top(); qu.pop();
		cnt[cur.v]++;
		if( cnt[t] == K ) return cur.f;//找到第k短路
		if( cnt[cur.v] > K ) continue;
		for(int i=heade1[cur.v] ; i!=-1 ; i=ez[i].next){
			tmp.v = ez[i].v;
			tmp.g = cur.g + ez[i].c;
			tmp.f = dis[tmp.v] + tmp.g;
			qu.push( tmp );
		}
	}
	return -1;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int a,b,c;
	while( scanf("%d%d", &n, &m) != EOF ){
		init();
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			addz( a, b, c );
			addf( b, a, c );
		}
		int s,t;
		scanf("%d%d%d", &s, &t, &K);
		if(s==t) K++;//如果起点相同,0不是最短路
		dijkstra(t);
		printf("%d\n", Astar(s,t));
	}
	return 0;
}