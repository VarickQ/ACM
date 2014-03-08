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
const int N = 605;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))

//------------------------DinicÄ£°å
struct edge
{
    int v, next;
    int val;
} net[ 100010 ];

int level[N], Qu[N], out[N],Next[N];
class Dinic {
public:
    int end;
    Dinic() {
        end = 0;
        memset( Next, -1, sizeof(Next) );
    }
    inline void insert( int x, int y, int c) {
        net[end].v = y, net[end].val = c,
        net[end].next = Next[x],
        Next[x] = end ++;
        net[end].v = x, net[end].val = c,
        net[end].next = Next[y],
        Next[y] = end ++;
    }
    bool BFS( int S, int E ) {
        memset( level, -1, sizeof(level) );
        int low = 0, high = 1;
        Qu[0] = S, level[S] = 0;
        for( ; low < high; ) {
            int x = Qu[low];
            for( int i = Next[x]; i != -1; i = net[i].next ) {
                if( net[i].val == 0 ) continue;   
                int y = net[i].v;   
                if( level[y] == -1 ) {   
                    level[y] = level[x] + 1;   
                    Qu[ high ++] = y;   
                }
            }
            low ++;
        }
        return level[E] != -1;
    }
    int MaxFlow( int S, int E ){
        int maxflow = 0;
        for( ; BFS(S, E) ; ) {
            memcpy( out, Next, sizeof(out) );
            int now = -1;
            for( ;; ) {
                if( now < 0 ) {
                    int cur = out[S];
                    for(; cur != -1 ; cur = net[cur].next )
                        if( net[cur].val && out[net[cur].v] != -1 && level[net[cur].v] == 1 )   
                            break;
                    if( cur >= 0 ) Qu[ ++now ] = cur, out[S] = net[cur].next;   
                    else break;
                }
                int u = net[ Qu[now] ].v;
                if( u == E ) {
                    int flow = inf;
                    int index = -1;
                    for( int i = 0; i <= now; i ++ ) {
                        if( flow > net[ Qu[i] ].val )
                            flow = net[ Qu[i] ].val, index = i;
                    }
                    maxflow += flow;
                    for( int i = 0; i <= now; i ++ )
                        net[Qu[i]].val -= flow, net[Qu[i]^1].val += flow;   
                    for( int i = 0; i <= now; i ++ ) {
                        if( net[ Qu[i] ].val == 0 ) {
                            now = index - 1;
                            break;
                        }
                    }
                }
                else{
                    int cur = out[u];
                    for(; cur != -1; cur = net[cur].next )
                        if (net[cur].val && out[net[cur].v] != -1 && level[u] + 1 == level[net[cur].v])   
                            break;
                    if( cur != -1 )
                        Qu[++ now] = cur, out[u] = net[cur].next;
                    else out[u] = -1, now --;
                }
            }
        }
        return maxflow;
    }
};
int ans[E];
int main(){
	int n,m,a,b,s,t;
	while( scanf("%d%d", &n, &m) != EOF ){
		Dinic mf;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &a, &b);
			mf.insert( a, b, 1 );
		}
		scanf("%d%d", &s, &t);
		printf("%d\n", mf.MaxFlow(s,t));

		CLR( ans, 0 );
		int cnt = 0;
		for(int i=0 ; i < mf.end ; ++i)
			if( net[i].val > 1 )
				if( i%2 == 0 )
					ans[cnt++] = i/2+1;
		printf("%d\n", cnt);
		for(int i=0 ; i < cnt ; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}