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
#define Lowbit(x) ((x)&(-x))
const double eps = 1e-10;
const int inf = 1000000000;
const int M   = 501505;
const int N   = 1505;
typedef long long LL;

//-----------dinic
struct{
    int u, v, c, next;
}bf[2*M];
int ne, head[N];
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
	int n, m, i;
	char str[20],ch;
	while( scanf("%d%d", &n, &m) != EOF ){
		if( n==0 && m==0 ) break;
		init();
		int v, cnt = 0;
		for( i=1 ; i <= n ; ++i ){
			scanf("%s ", str);
			addEdge( 0, i, 1 );
			while( 1 ){
				scanf("%d", &v);
				addEdge( i, v+1+n, 1 );
				if( getchar() == '\n' ) break;
			}
		}
		int s = 0,t = n+m+1;
		for( i=n+1 ; i < t ; ++i )
			addEdge( i, t, 1 );
		int l=1, r=n, mid, tmp, ans;
		while( l <= r ){
			mid = (l+r)>>1;
			for( i=2 ; i < ne ; i+=2 ){
				if( bf[i].u <= n ){
					bf[i].c = 1;
					bf[i+1].c = 0;
				} else {
					bf[i].c = mid;
					bf[i+1].c = 0;
				}
			}
			tmp = dinic( s, t );
			if( tmp == n ){
				ans = mid;
				r = mid-1;
			} else l = mid+1;
		}
		printf("%d\n", ans);
	}
	return 0;
}