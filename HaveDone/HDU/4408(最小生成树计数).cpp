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
const LL N = 1050;
const LL M = 101000;
const LL inf = (1LL<<60);

struct Edge{
    LL a,b,c;
}e[M];
LL n, m, P;
LL fa[N], ka[N], vis[N];
LL gk[N][N], tmp[N][N], ans;
vector<LL> gra[N];
bool cmp( const Edge &a, const Edge &b ){
	return a.c < b.c;
}
LL findfa( LL a, LL b[] ){
	return a==b[a]?a:b[a]=findfa(b[a],b);
}
LL det( LL a[][N], LL n ){
    for(LL i=0 ; i < n ; ++i)
		for(LL j=0 ; j < n ; ++j)
			a[i][j] %= P;
    LL ret = 1;
    for(LL i=1 ; i < n ; ++i){
        for(LL j=i+1 ; j < n ; ++j)
            while( a[j][i] ){
                LL t = a[i][i]/a[j][i];
                for(LL k=i ; k < n ; ++k)
                    a[i][k] = (a[i][k]-a[j][k]*t)%P;
                for(LL k=i ; k < n ; ++k)
                    swap( a[i][k], a[j][k] );
                ret = -ret;
            }
        if( a[i][i] == 0 ) return 0;
        ret = ret*a[i][i]%P;
    }
    return (ret+P)%P;
}
 
int main(){
	while( scanf("%I64d%I64d%I64d", &n, &m, &P) == 3 ){
		if( n==0 && m==0 && P==0 ) break;
		memset( ka, 0, sizeof( ka ) );
		memset( gk, 0, sizeof( gk ) );
		memset( tmp, 0, sizeof( tmp ) );
		memset( vis, 0, sizeof( vis ) );
		for(LL i=0 ; i < m ; ++i)
			scanf("%I64d%I64d%I64d", &e[i].a, &e[i].b, &e[i].c);
		sort( e, e+m, cmp );
		for(LL i=1 ; i <= n ; ++i){
			fa[i] = i;
			gra[i].clear();
		}
		LL pre = -1;
		ans = 1;
		for(LL h=0 ; h <= m ; ++h){
			if( h == m || e[h].c != pre ){
				for(LL i=1 ; i <= n ; ++i)
					if( vis[i] ){
						LL u = findfa(i,ka);
						gra[u].push_back(i);
						vis[i] = 0;
					}
				for(LL i=1 ; i <= n ; ++i)
					if( gra[i].size() > 1 ){
						for(LL a=1 ; a <= n ; ++a)
							for(LL b=1 ; b <= n ; ++b)
								tmp[a][b] = 0;
						LL len = gra[i].size();
						for(LL a=0 ; a < len ; ++a)
							for(LL b=a+1 ; b < len ; ++b){
								LL la = gra[i][a],lb = gra[i][b];
								tmp[a][b] = (tmp[b][a]-=gk[la][lb]);
								tmp[a][a] += gk[la][lb];
								tmp[b][b] += gk[la][lb];
							}
						LL ret = det( tmp, len );
						ans = ans*ret;//ȡģWA
						for(LL a=0 ; a < len ; ++a)
							fa[gra[i][a]] = i;
					}
				ans %= P;
				for(LL i=1 ; i <= n ; ++i){
					ka[i] = fa[i] = findfa(i,fa);
					gra[i].clear();
				}
				if( h == m ) break;
				pre = e[h].c;
			}
			LL a = e[h].a, b = e[h].b;
			LL pa = findfa(a,fa), pb = findfa(b,fa);
			if( pa == pb ) continue;
			vis[pa] = vis[pb] = 1;
			ka[findfa(pa,ka)] = findfa(pb,ka);
			gk[pa][pb]++;
			gk[pb][pa]++;
		}
		bool flag = false;
		for(LL i=2 ; i <= n && !flag ; ++i)
			if( ka[i] != ka[i-1] )
				flag = true;
		printf("%I64d\n", flag?0:ans);
	}
    return 0;
}