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
const int N   = 100010;
const int M   = 200010;
const int inf = 2000000000;
typedef __int64 LL;

struct Node{
	int left,right,cMin,cMax,col;
}tr[N*5];
int a[N];

void pushup( int id ){
	if( tr[id].left == tr[id].right ) return;
	if( tr[id<<1].col==tr[id<<1|1].col && tr[id<<1].col!=-1 )
		tr[id].col = tr[id<<1].col;
	else tr[id].col = -1;
	tr[id].cMin = min(tr[id<<1].cMin,tr[id<<1|1].cMin);
	tr[id].cMax = max(tr[id<<1].cMax,tr[id<<1|1].cMax);
}

void pushdown( int id ){
	if( tr[id].col != -1 ){
		tr[id<<1].col = tr[id].col;
		tr[id<<1|1].col = tr[id].col;
		tr[id<<1].cMin = tr[id<<1].cMax = tr[id].col;
		tr[id<<1|1].cMin = tr[id<<1|1].cMax = tr[id].col;
		tr[id].col = -1;
	}
}

void build( int id, int l, int r ){
	tr[id].left = l;
	tr[id].right = r;
	tr[id].col = -1;
	if( l == r ){
		tr[id].cMax = tr[id].cMin = tr[id].col = a[l];
		return;
	}
	int mid = l+r>>1;
	build( id<<1, l, mid );
	build( id<<1|1, mid+1, r );
	pushup(id);
}

void update( int id, int l, int r, int c ){
	if( tr[id].col == c ) return;//¼ôÖ¦
	if( tr[id].left>=l && tr[id].right<=r ){
		tr[id].col = c;
		tr[id].cMax = tr[id].cMin = c;
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

int query(int id, int l, int r, int c ){
	if( tr[id].cMin>c || tr[id].cMax<c || (tr[id].col!=c&&tr[id].col!=-1) )
		return 0;//¼ôÖ¦
	if( tr[id].left>=l && tr[id].right<=r && tr[id].col==c )
		return tr[id].right-tr[id].left+1;
	pushdown(id);
	int mid = tr[id].left+tr[id].right>>1;
	if( r <= mid ) return query( id<<1, l, r, c );
	else {
		if( l > mid ) return query( id<<1|1, l, r, c );
		else return query( id<<1, l, r, c )+query( id<<1|1, l, r, c );
	}
}

int main(){
	int n, m, q, x, y, c;
	while( ~scanf("%d%d", &n, &m) ){
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &a[i]);
		build( 1, 1, n );
		while( m-- ){
			scanf("%d%d%d%d", &q, &x, &y, &c);
			x++;y++;
			if( q == 1 ) update( 1, x, y, c );
			else printf("%d\n", query( 1, x, y, c ));
		}
	}
	return 0;
}