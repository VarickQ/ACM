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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 105;
const int M   = 10050;
const int inf = 1000000000;
const int MOD = 100000007;
typedef long long LL;

struct Node{
	int u,v,w,p;
}e[M];
//-----------dinic
struct{
    int u, v, c, next;
}bf[2*M],tbf[2*M];
int ne, head[N], heade[N], bne;
int cur[N], ps[N], dep[N];

void init(){
	ne = 2;
	memset( head, -1, sizeof( head ) );
}
void addEdge(int u, int v, int c){
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
 
int dinic(int s, int t){
    int tr, res = 0;
    int i, j, k, f, r, top;
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
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int n, m, s, t, a, u, v, w, p, tnt;
	while( scanf("%d%d", &n, &m) != EOF ){
		init();
		CLR( heade, -1 );
		s = 0;
		t = n+1;
		tnt = n+2;
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &a);
			if( a ) addEdge( s, i, a );
		}
		int cnt = 0,f = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d%d", &u, &v, &w, &p);
			if( p < 0 ){
				f += w;
				addEdge( u, tnt, inf );
				addEdge( tnt, v, inf );
				addEdge( tnt, t, w );
				tnt++;
			}
			else if( p == 0 )
				addEdge( u, v, inf );
			else {
				e[cnt].u = u;
				e[cnt].v = v;
				e[cnt].w = w;
				e[cnt].p = p;
				cnt++;
			}
		}
		if( f == 0 ){
			puts("Poor Heaven Empire"); continue;
		}
		bne = ne;
		for(int i=2 ; i < ne ; ++i)
			tbf[i] = bf[i];
		for(int i=0 ; i < tnt ; ++i)
			heade[i] = head[i];

		int cost = inf, ans = 0;
		for(int st=0 ; st < (1<<cnt) ; ++st){
			ne = bne;
			CLR( head, -1 );
			for(int j=2 ; j < ne ; ++j)
				bf[j] = tbf[j];
			for(int j=0 ; j < tnt ; ++j)
				head[j] = heade[j];
			int ss = st,tmp = 0,res;
			for(int j=0 ; j < cnt ; ++j){
				if( ss&1 ){
					tmp += e[j].w;
					addEdge( e[j].u, e[j].v, inf );
				} else
					addEdge( e[j].u, e[j].v, 1 );
				ss >>= 1;
			}
			res = dinic(s,t);
			if( res > ans ){
				ans = res;
				cost = tmp;
			}
			/*这个没写也AC了
			else if( res == ans ){
				cost = min(cost,tmp);
			}
			*/
		}
		if( ans == 0 ) puts("Poor Heaven Empire");
		else printf("%d %d\n", ans, cost);
	}
	return 0;
}