#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
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
typedef __int64 LL;

#define inf (1LL<<50)
#define M 200000
#define N 1010
struct edge{
    LL from,to,val,next;
}e[M];
LL w[N],que[N],dis[N],edge,cur[N];
void add(LL from,LL to,LL va){
    e[edge].from=from;
    e[edge].to=to;
    e[edge].val=va;
    e[edge].next=w[from];
    w[from]=edge++;

    e[edge].from=to;
    e[edge].to=from;
    e[edge].val=0;
    e[edge].next=w[to];
    w[to]=edge++;
}
LL bfs(LL n,LL s,LL t){
    LL head,tail,id;
    head=tail=0;que[tail++]=s;
    memset(dis,-1,sizeof( LL )*n);
    dis[s]=0;
    while(head<tail) // bfs,得到顶点i的距s的最短距离dis[i]
    {
        for(id=w[que[head++]];id!=-1;id=e[id].next)
            if(e[id].val>0&&dis[e[id].to]==-1)
            {
                dis[e[id].to]=dis[e[id].from]+1;
                que[tail++]=e[id].to;
                if(e[id].to==t) return 1;
            }
    }
    return 0;
}
LL Dinic(LL n,LL s,LL t){//0~n-1
    LL Mflow=0,tmp,i;
    while(bfs(n,s,t)){
        LL u=s,tail=0;
        for(i=0;i<n;i++) cur[i]=w[i];
        while(cur[s]!=-1){
            if(u!=t&&cur[u]!=-1&&e[cur[u]].val>0&&dis[u]!=-1&&dis[u]+1==dis[e[cur[u]].to]){
                que[tail++]=cur[u];
                u=e[cur[u]].to;
            }
            else if(u==t){
                for(tmp=inf,i=tail-1;i>=0;i--)
                    tmp=min(tmp,e[que[i]].val);
                for(Mflow+=tmp,i=tail-1;i>=0;i--){
                    e[que[i]].val-=tmp;
                    e[que[i]^1].val+=tmp;
                    if(e[que[i]].val==0) tail=i;
                }
                u=e[que[tail]].from;
            }
            else{
                while(tail>0&&u!=s&&cur[u]==-1) u=e[que[--tail]].from;
                cur[u]=e[cur[u]].next;
            }
        }
    }
    return Mflow;
}
int main(){
    LL u, v, m, c, s, t, n;
    while( scanf("%I64d%I64d", &n, &m) != EOF ){
        memset( w, -1, sizeof( w ) );
        edge = 0;
        scanf("%I64d%I64d", &s, &t);
        for(LL i=0 ; i < n ; ++i){
            scanf("%I64d", &c);
            add( i+n, i, c );
        }
        for(LL i=0 ; i < m ; ++i){
            scanf("%I64d%I64d", &u, &v);
            u--,v--;
            add( u, v+n, inf );
            add( v, u+n, inf );
        }
        printf("%I64d\n", Dinic(2*n,s+n-1,t-1));
    }
    return 0;
}