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
const int inf = 1000000000;
const int E = 300100;
const int N = 30500;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))

int n,m,ans;
struct edge{
    int x,y,f,c,nxt;
}e[E];
int en,head[N],pre[N],dist[N],visited[N];

void init(){
	CLR( head, -1 );
	en = 0;
}
void add(int x,int y,int cap,int cost){
    e[en].x = x;
    e[en].y = y;
    e[en].f = cap;
    e[en].c = cost;
    e[en].nxt = head[x];
    head[x] = en++;
}

void addedge(int x,int y,int f,int c){
    add( x, y, f, c );
    add( y, x, 0, -c );
}

bool spfa( int s, int t, int n ){
    int i, v, cur;
    queue<int> q;
    for( i=0 ; i < n ; i++ ){
        pre[i] = -1;
        visited[i] = false;
        dist[i] = inf;
    }
    visited[s] = true;
    dist[s] = 0;
    q.push( s );
    while( !q.empty() ){
        cur = q.front();
        q.pop();
        visited[cur] = false;
        for( i=head[cur] ; i != -1 ; i=e[i].nxt )
            if( e[i].f ){
                v = e[i].y;
                if( dist[v] > dist[cur]+e[i].c ){
                    dist[v] = dist[cur]+e[i].c;
                    pre[v] = i;
                    if( !visited[v] ){
                        visited[v] = true;
                        q.push( v );
                    }
                }
            }
    }
    return dist[t] != inf;
}

int cost( int s, int t, int n ){
    int i,flow = inf,ans = 0;
    while( spfa(s,t,n) ){
        ans += dist[t];
        for( i=pre[t] ; i != -1 ; i=pre[e[i].x] )
            flow = min( flow, e[i].f );
        for( i=pre[t] ; i != -1 ; i=pre[e[i].x] ){
            e[i].f -= flow;
            e[i^1].f += flow;
        }
    }
    return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		init();
		scanf("%d%d", &n, &m);
		int u,v;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &u, &v);
			addedge( u+n, v, 1, 0 );
		}
		int s = 0,t = 2*n+1;
		for(int i=1 ; i <= n ; ++i){
			addedge(s,i,inf,0);
			addedge(i,i+n,1,-1);//最小费用，这里要求点尽量多，所以费用为负
			addedge(i+n,t,inf,0);
		}
		addedge(t,t+1,2,0);//限制，只接受两个点的流量
		printf("%d\n", -cost(s,t+1,t+2));
	}
	return 0;
}