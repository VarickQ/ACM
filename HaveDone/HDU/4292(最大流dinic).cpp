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
typedef __int64 LL;
const LL N = 2050;
const LL M = 1000010;
const LL inf = 1000000000;

//-----------dinic
struct{
    LL u, v, c, next;
}bf[2*M];
LL ne, head[N];
LL cur[N], ps[N], dep[N];

void init(){
    ne = 2;
    memset( head, -1, sizeof( head ) );
}
void addEdge(LL u, LL v, LL c){
    bf[ne].u = u;
    bf[ne].v = v;
    bf[ne].c = c;
    bf[ne].next = head[u];
    head[u] = ne ++;
    
    bf[ne].u = v;
    bf[ne].v = u;
    bf[ne].c = 0;
    bf[ne].next = head[v];
    head[v] = ne ++;
}
 
LL dinic(LL s, LL t){
    LL tr, res = 0;
    LL i, j, k, f, r, top;
    while(1){
        memset(dep, -1, sizeof(dep));
        for(f = dep[ps[0]=s] = 0, r = 1; f != r;)
            for(i = ps[f ++], j = head[i]; j; j = bf[j].next)
                if(bf[j].c && dep[k=bf[j].v] == -1){
                    dep[k] = dep[i] + 1;
                    ps[r ++] = k;
                    if(k == t){
                        f = r; break;
                    }
                }
        if(dep[t] == -1) break;
        memcpy(cur, head, sizeof(cur));
        i = s, top = 0;
        while(1){
            if(i == t){
                for(tr = inf, k = 0; k < top; k ++)
                    if(bf[ps[k]].c < tr)
                        tr = bf[ps[f=k]].c;
                for(k = 0; k < top; k ++){
                    bf[ps[k]].c -= tr;
                    bf[ps[k]^1].c += tr;
                }
                i = bf[ps[top=f]].u;
                res += tr;
            }
            for(j = cur[i]; cur[i]; j = cur[i] = bf[cur[i]].next)
                if(bf[j].c && dep[i]+1 == dep[bf[j].v]) break;
            if(cur[i]){
                ps[top ++] = cur[i];
                i = bf[cur[i]].v;
            }else{
                if(top == 0) break;
                dep[i] = -1;
                i = bf[ps[-- top]].u;
            }
        }
    }
    return res;
}
LL a[N];
char str[N];
int main(){
    LL n,d,f;
    while( scanf("%I64d%I64d%I64d", &n, &f, &d) != EOF ){
        init();
        LL s = 0, t = n*2+f+d+1;

        for(LL i=1 ; i <= f ; ++i){
            scanf("%I64d", &a[i]);
            if(a[i]>0)addEdge( s, i, a[i] );
        }
        for(LL i=1 ; i <= d ; ++i)
            scanf("%I64d", &a[i]);

        for(LL i=1 ; i <= n ; ++i){
            scanf("%s", str+1);
            LL len = strlen(str+1);
            for(LL j=1 ; j <= len ; ++j)
                if( str[j] == 'Y' )
                    addEdge( j, i+f, inf );
        }
        for(LL i=1 ; i <= n ; ++i)
            addEdge( f+i, f+n+i, 1 );

        for(LL i=1 ; i <= n ; ++i){
            scanf("%s", str+1);
            LL len = strlen(str+1);
            for(LL j=1 ; j <= len ; ++j)
                if( str[j] == 'Y' )
                    addEdge( i+f+n, j+f+n*2, inf );
        }

        for(LL i=1 ; i <= d ; ++i)
            if(a[i]>0)addEdge( i+n*2+f, t, a[i] );

        LL ans = dinic( s, t );
        printf("%I64d\n", ans);
    }
    return 0;
}