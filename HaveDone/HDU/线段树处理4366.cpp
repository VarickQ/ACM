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
#pragma comment(linker, "/STACK:102400000,102400000")
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 50010;
const int M   = 50010;
typedef __int64 LL;
const LL inf = 1LL<<62;

struct staff{
	int id,loy,abi;
	bool operator<(const staff &a)const{
		if( abi == a.abi ) return id < a.id;
		return abi > a.abi;
	}
}a[N];
vector<int> va[N];
map<int,int> ma;
int low[N],high[N],dep;
void dfs(int u){
	low[u] = dep;
	for(int i=0 ; i < va[u].size() ; ++i){
		++dep;
		dfs( va[u][i] );
	}
	high[u] = dep;
}
int ans[N];
struct Node{
	int l,r,maxloy;
}tr[N*10];
void build(int l,int r,int id){
	tr[id].l = l;
	tr[id].r = r;
	tr[id].maxloy = -1;
	if( l == r ) return ;
	int mid = l+r>>1;
	build( l, mid, id<<1 );
	build( mid+1, r, id<<1|1 );
}
int query(int id,int l,int r){
	if( tr[id].l==l && tr[id].r==r ) return tr[id].maxloy;
	int mid = tr[id].l+tr[id].r>>1;
	if( r <= mid ) return query(id<<1,l,r);
	else if( l > mid ) return query(id<<1|1,l,r);
	else return max(query(id<<1,l,mid),query(id<<1|1,mid+1,r));
}
void update(int id,int x,int val){
	if( tr[id].l == tr[id].r ){
		tr[id].maxloy = val;
		return;
	}
	int mid = tr[id].l+tr[id].r>>1;
	if( x <= mid ) update(id<<1,x,val);
	else update(id<<1|1,x,val);
	tr[id].maxloy = max(tr[id<<1].maxloy,tr[id<<1|1].maxloy);
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\Qian\\Desktop\\in.txt","r",stdin);
	freopen("C:\\Users\\Qian\\Desktop\\out.txt","w",stdout);
#endif
////////////////////////////////////////
	int T, n, m, x;
	scanf("%d", &T);
	while( T-- ){
		ma.clear();
		dep = 0;
		scanf("%d%d", &n, &m);
		for(int i=0 ; i <= n ; ++i) va[i].clear();
		for(int i=1 ; i < n ; ++i){
			scanf("%d%d%d", &x, &a[i].loy, &a[i].abi);
			a[i].id = i;
			ma[a[i].loy] = i;
			va[x].push_back(i);
		}
		dfs(0);
		sort( a+1, a+n );
		build( 0, dep, 1 );
		for(int i=1 ; i < n ; ++i){
			ans[a[i].id] = query(1,low[a[i].id],high[a[i].id]);
			if( ans[a[i].id] != -1 )
				ans[a[i].id] = ma[ans[a[i].id]];
			update(1,low[a[i].id],a[i].loy);
		}
		while( m-- ){
			scanf("%d", &x);
			printf("%d\n", ans[x]);
		}
	}
	return 0;
}