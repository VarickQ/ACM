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
typedef long long LL;
const int N   = 500;
const int M   = 300000;
const int inf = 2000000000;
const LL MAXL = 1LL<<60;

//-----------dinic
struct{
    int u, v, c, next;
}bf[2*M];
int ne, head[N];
int cur[N], ps[N], dep[N];
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
int a[N],c[N];
LL map[N][N];
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int n, p;
	scanf("%d%d", &n, &p);
	int sum = 0;
	for(int i=1 ; i <= n ; ++i){
		scanf("%d%d", &a[i], &c[i]);
		sum += a[i];
	}
	for(int i=1 ; i <= n ; ++i){
		for(int j=1 ; j <= n ; ++j)
			map[i][j] = MAXL;
		map[i][i] = 0;
	}
	int u, v, w;
	while( p-- ){
		scanf("%d%d%d", &u, &v, &w);
		if( map[u][v] > w )
			map[u][v] = map[v][u] = w;
	}
	LL l = 0, r = 0, mid, ans = -1;
	//floyd
	for(int k=1 ; k <= n ; ++k)
		for(int i=1 ; i <= n ; ++i)
			if( map[i][k] < MAXL )
				for(int j=1 ; j <= n ; ++j)
					if(map[k][j]!=MAXL&&map[i][j]>map[i][k]+map[k][j]){
						map[i][j] = map[i][k]+map[k][j];
						r = max(r,map[i][j]);
					}

	int s = 0, t = 2*n+1;
	r += 100;
	while( l < r ) {
		mid = (l+r)>>1LL;
		ne = 2;
		memset( head, -1, sizeof( head ) );
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				if( map[i][j] <= mid && map[i][j] )
					addEdge( i, j+n, inf );
		for(int i=1 ; i <= n ; ++i){
			addEdge( s, i, a[i] );
			addEdge( i, i+n, inf );
			addEdge( i+n, t, c[i] );
		}
		if( dinic(s,t) == sum )
			ans = r = mid;
		else l = mid+1;
	}
	printf("%lld\n", ans);
    return 0;
}