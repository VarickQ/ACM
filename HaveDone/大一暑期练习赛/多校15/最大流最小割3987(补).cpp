/*很经典的最大流最小割的题目题意：求最小割，但因为最小割是不唯一的，题目要求得到最小割的条件下使得割边最少建边的时候每条边权 w=w*(E+1)+1;这样得到最大流maxflow/(E+1) 就是答案了道理很简单，如果原先两类割边都是最小割，那么求出的最大流相等但边权变换后只有边数小的才是最小割了，至于为什么乘的是（E+1）是为了保证边数叠加后依然是余数，不至于影响求最小割的结果*/#include <stdio.h>//补 HDU 3987#include <stdlib.h>#include <time.h>#include <vector>#include <iostream>using namespace std;const int maxn = 1002;const __int64 inf = 100000000000000;#define ll __int64int n,m;//----------------dinic模板struct edge{    int v, next;    ll val;} net[ 500010 ];int level[maxn], Qu[maxn], out[maxn],next[maxn];  class Dinic {public:    int end;      Dinic() {        end = 0;           memset( next, -1, sizeof(next) );       }    inline void insert( int x, int y, ll c) {        net[end].v = y, net[end].val = c,        net[end].next = next[x],        next[x] = end ++;        net[end].v = x, net[end].val = 0,        net[end].next = next[y],        next[y] = end ++;    }    bool BFS( int S, int E ) {           memset( level, -1, sizeof(level) );           int low = 0, high = 1;           Qu[0] = S, level[S] = 0;           for( ; low < high; ) {               int x = Qu[low];               for( int i = next[x]; i != -1; i = net[i].next ) {                   if( net[i].val == 0 ) continue;                   int y = net[i].v;                   if( level[y] == -1 ) {                       level[y] = level[x] + 1;                       Qu[ high ++] = y;                   }            }            low ++;        }        return level[E] != -1;    }    ll MaxFlow( int S, int E ){        ll maxflow = 0;        for( ; BFS(S, E) ; ) {            memcpy( out, next, sizeof(out) );            int now = -1;            for( ;; ) {                if( now < 0 ) {                    int cur = out[S];                    for(; cur != -1 ; cur = net[cur].next )                        if( net[cur].val && out[net[cur].v] != -1 && level[net[cur].v] == 1 )                               break;                    if( cur >= 0 ) Qu[ ++now ] = cur, out[S] = net[cur].next;                       else break;                }                int u = net[ Qu[now] ].v;                if( u == E ) {                    ll flow = inf;                    int index = -1;                    for( int i = 0; i <= now; i ++ ) {                        if( flow > net[ Qu[i] ].val )                            flow = net[ Qu[i] ].val, index = i;                    }                    maxflow += flow;                    for( int i = 0; i <= now; i ++ )                        net[Qu[i]].val -= flow, net[Qu[i]^1].val += flow;                       for( int i = 0; i <= now; i ++ ) {                        if( net[ Qu[i] ].val == 0 ) {                            now = index - 1;                            break;                        }                    }                }                else{                    int cur = out[u];                    for(; cur != -1; cur = net[cur].next )                        if (net[cur].val && out[net[cur].v] != -1 && level[u] + 1 == level[net[cur].v])                               break;                    if( cur != -1 )                        Qu[++ now] = cur, out[u] = net[cur].next;                    else out[u] = -1, now --;                }            }        }        return maxflow;    }};int main(){	int T,i,u,v,d,cs=0;	ll ans,c;	scanf("%d",&T);	while(T--)	{		Dinic a;		scanf("%d%d",&n,&m);		for(i=0 ; i < m ; ++i){			scanf("%d%d%I64d%d",&u,&v,&c,&d);			a.insert(u,v,c*10000+1);			if(d) a.insert(v,u,c*10000+1);		}		ans = a.MaxFlow(0,n-1);		printf("Case %d: %I64d\n",++cs,ans%10000);	}	return 0;}