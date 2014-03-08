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
typedef long long LL;
const double eps = 1e-8;
const LL MOD = 1000000007;
const int inf = 1000000000;
const int M = 200005;
const int N = 205;

struct Node{
	int x, y, z, f, l;
}a[N];
int n;
double mat[N][N];
double dis(Node a,Node b){
	double x = 0.0 + a.x - b.x;
	double y = 0.0 + a.y - b.y;
	double z = 0.0 + a.z - b.z;
	return sqrt( x * x + y * y + z * z );
}
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
	while( scanf("%d", &n) != EOF ){
		int sum = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%d%d%d%d%d",&a[i].x,&a[i].y,&a[i].z,&a[i].f,&a[i].l);
			sum += a[i].f;
		}
		for(int i=1 ; i <= n ; ++i){
			for(int j=1 ; j < i ; ++j)
				mat[i][j] = mat[j][i] = dis(a[i],a[j]);
			mat[i][i] = 0;
		}
		int s = 0, tmp, TT = 40, ok = 0;
		double l = 0,r = 35000, mid, ans;
		while( TT-- ){
			init();
			mid = (l + r)/2;
			for(int i=1 ; i <= n ; ++i){
				addEdge( i, i+n, a[i].l );
				addEdge( s, i, a[i].f );
			}
			for(int i=1 ; i <= n ; ++i)
				for(int j=1 ; j <= n ; ++j)
					if( i!=j && mat[i][j] < mid+eps ){
						addEdge( i+n, j, inf );
					}
			tmp = dinic( s, 1 );
			if( tmp == sum ){
				ok = 1;
				ans = mid;
				r = mid;
			} else l = mid;
		}
		if( ok ) printf("%.7lf\n", ans);
		else puts("-1");
	}
	return 0;
}