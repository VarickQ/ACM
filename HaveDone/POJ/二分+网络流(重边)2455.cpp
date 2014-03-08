#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
typedef long long LL;
const int N   = 205;
const int M   = 2500005;
const int inf = 1000000000;

//------------------------DinicÄ£°å
struct edge
{
    int v, next;
    int val;
} net[ 10*N*N+100 ];

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
        net[end].v = x, net[end].val = c,//ÓÐÖØ±ß=c
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
struct E{
	int x, y, c;
}a[N*N+100];
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int n, p, t;
	while( scanf("%d%d%d", &n, &p, &t) != EOF ){
		int l = inf, r = 0, mid;
		for(int i=0 ; i < p ; ++i){
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
			l = min( l, a[i].c );
			r = max( r, a[i].c );
		}
		while( l < r ){
			Dinic d;
			mid = (l+r)>>1;
			for(int i=0 ; i < p ; ++i)
				if( a[i].c <= mid )
					d.insert( a[i].x, a[i].y, 1 );
			if( d.MaxFlow(1,n) >= t )
				r = mid;
			else l = mid+1;
		}
		printf("%d\n", r);
	}
    return 0;
}