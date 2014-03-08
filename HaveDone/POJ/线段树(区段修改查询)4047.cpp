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
const double eps = 1e-8;
typedef long long LL;
const int N = 200010;
const int M = 5050;
const int inf = 1000000000;

int a[N],b[N];
struct Node{
	int left,right,add,Max;
}tr[N*5];
void pushup( int id ){
	if( tr[id].left == tr[id].right ) return ;
	tr[id].Max = max( tr[id<<1].Max, tr[id<<1|1].Max );
}
void pushdown( int id ){
	if( tr[id].add != 0 ){
		tr[id<<1].add += tr[id].add;
		tr[id<<1|1].add += tr[id].add;
		tr[id<<1].Max += tr[id].add;
		tr[id<<1|1].Max += tr[id].add;
		tr[id].add = 0;
	}
}
void biuld( int l, int r, int id ){
	tr[id].left = l;
	tr[id].right = r;
	tr[id].add = 0;
	if( l == r ){
		tr[id].Max = b[l];
		return;
	}
	int mid = l+r>>1;
	biuld( l, mid, id<<1 );
	biuld( mid+1, r, id<<1|1 );
	pushup(id);
}
void update( int id, int l, int r, int c ){
	if( c == 0 ) return;
	if( tr[id].left>=l && tr[id].right<=r ){
		tr[id].Max += c;
		tr[id].add += c;
		return;
	}
	pushdown(id);
	int mid = tr[id].left+tr[id].right>>1;
	if( r <= mid ) update( id<<1, l, r, c );
	else {
		if( l > mid ) update( id<<1|1, l, r, c );
		else {
			update( id<<1, l, mid, c );
			update( id<<1|1, mid+1, r, c );
		}
	}
	pushup(id);
}
int query( int id, int l, int r ){
	if( tr[id].left>=l && tr[id].right<=r )
		return tr[id].Max;
	pushdown(id);
	int mid = tr[id].left+tr[id].right>>1;
	if( r <= mid ) return query( id<<1, l, r );
	else {
		if( l > mid ) return query( id<<1|1, l, r );
		else return max(query( id<<1, l, mid ), query( id<<1|1, mid+1, r ));
	}
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\Qian\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\Qian\\Desktop\\out.txt","w",stdout);
#endif
////////////////////////////////////////
	int T,n,m,k;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d", &n, &m, &k);
		for(int i=1 ; i <= n ; ++i) scanf("%d", &a[i]);
		memset( b, 0, sizeof( b ) );
		for(int i=1 ; i <= k ; ++i) b[1] += a[i];
		for(int i=2 ; i <= n-k+1 ; ++i)
			b[i] = b[i-1]-a[i-1]+a[i+k-1];
		biuld( 1, n-k+1, 1 );
		int q, x, y;
		while( m-- ){
			scanf("%d%d%d", &q, &x, &y);
			if( q == 0 ){
				update( 1, max(1,x-k+1), x, y-a[x] );
				a[x] = y;
			} else if( q == 1 ){
				int val = a[y] - a[x];
				update( 1, max(1,x-k+1), x, val );
				update( 1, max(1,y-k+1), y, -val );
				swap( a[x], a[y] );
			} else {
				int ans = query( 1, x, y-k+1 );
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}