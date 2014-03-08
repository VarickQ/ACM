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
#define Lowbit(x) ((x)&(-x))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 20010;
typedef long long LL;

int n,ans,b[N],cnt;
struct A{
	int l, r;
}a[N];
struct Node{
	int left,right,colour;
}node[N*4];
void creatTree(int l,int r,int id){
	node[id].colour = 0;
	node[id].left = l;
	node[id].right = r;
	if( l == r ) return;

	int mid = (l+r)/2;
	creatTree( l, mid, 2*id );
	creatTree( mid+1, r, 2*id+1 );
}
int getid(int val){
	int l = 1,r = cnt,mid;
	while( l <= r ){
		mid = (l+r)/2;
		if( b[mid] == val ) return mid;
		else if( b[mid] < val ) l=mid+1;
		else r = mid-1;
	}
}
void insert(int l,int r,int id,int c){
	if( node[id].left>=l && node[id].right<=r )
		node[id].colour = c;
	else{
		if( node[id].colour > 0 && node[id].colour != c ){
			node[id*2].colour = node[id].colour;
			node[id*2+1].colour = node[id].colour;
			node[id].colour = 0;
		}
		int mid = (node[id].left+node[id].right)/2;
		if( mid >= r ) insert(l,r,id*2,c);
		else if( l > mid ) insert(l,r,id*2+1,c);
		else {
			insert( l, mid, 2*id, c );
			insert( mid+1, r, 2*id+1, c );
		}
	}
}
bool vis[N];
void getans(int id){
	if( node[id].colour > 0 ){
		if( !vis[node[id].colour] ){
			vis[node[id].colour] = true;
			ans++;
		}
		return ;
	}
	if( node[id].left == node[id].right ) return ;
	getans(2*id);
	getans(2*id+1);
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		cnt = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%d%d", &a[i].l, &a[i].r);
			b[++cnt] = a[i].l;
			b[++cnt] = a[i].r;
		}
		sort( b+1, b+cnt+1 );
		cnt = unique(b+1,b+1+cnt)-(b+1);
		//printf("%d\n", cnt);

		creatTree( 1, cnt, 1 );
		for(int i=1 ; i <= n ; ++i)
			insert( getid(a[i].l), getid(a[i].r), 1, i );
		memset( vis, 0, sizeof( vis ) );
		ans = 0;
		getans(1);
		printf("%d\n", ans);
	}
	return 0;
}