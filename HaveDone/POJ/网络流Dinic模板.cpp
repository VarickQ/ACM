//------------------------Dinicģ��
struct edge
{
    int v, next;
    int val;
} net[ 100010 ];

int level[maxn], Qu[maxn], out[maxn],next[maxn];
class Dinic {
public:
    int end;
    Dinic() {
        end = 0;
        memset( next, -1, sizeof(next) );
    }
    inline void insert( int x, int y, int c) {
        net[end].v = y, net[end].val = c,
        net[end].next = next[x],
        next[x] = end ++;
        net[end].v = x, net[end].val = 0,
        net[end].next = next[y],
        next[y] = end ++;
    }
    bool BFS( int S, int E ) {
        memset( level, -1, sizeof(level) );
        int low = 0, high = 1;
        Qu[0] = S, level[S] = 0;
        for( ; low < high; ) {
            int x = Qu[low];
            for( int i = next[x]; i != -1; i = net[i].next ) {
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
            memcpy( out, next, sizeof(out) );
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