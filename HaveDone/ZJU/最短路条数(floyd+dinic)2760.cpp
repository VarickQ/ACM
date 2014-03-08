#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 200010;
const int N   = 105;
typedef long long LL;

int mat[N][N], n, tmp[N][N];
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
        net[end].v = x, net[end].val = 0,
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
void floyd(){
	for(int k=0 ; k < n ; ++k)
		for(int i=0 ; i < n ; ++i)
			for(int j=0 ; j < n ; ++j)
				if( mat[i][j] > mat[i][k]+mat[k][j] )
					mat[i][j] = mat[i][k]+mat[k][j];
}
int main(){
	int s, t;
	while( scanf("%d", &n) != EOF ){
		Dinic d;
		for(int i=0 ; i < n ; ++i){
			for(int j=0 ; j < n ; ++j){
				scanf("%d", &mat[i][j]);
				if( i == j ) mat[i][j] = 0;
				tmp[i][j] = mat[i][j];
				if( mat[i][j] == -1 )
					tmp[i][j] = mat[i][j] = inf;
			}
		}
		scanf("%d%d", &s, &t);
		if( s == t ){
			puts("inf"); continue;
		}
		floyd();
		int ans;
		for(int i=0 ; i < n ; ++i){
			if( mat[s][i] == inf ) continue;
			for(int j=0 ; j < n ; ++j)
				if( mat[s][j]!=inf && mat[i][j]!=inf
					&& mat[s][j] == mat[s][i]+tmp[i][j])
					d.insert( i, j, 1 );
		}
		ans = d.MaxFlow(s,t);
		printf("%d\n", ans);
	}
	return 0;
}