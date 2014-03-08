/*
给你全0的一棵树，两种操作，o:node将node节点的子树上的值取反；q:node询问node的子树中1的个数。
dfs将树进行后序遍历，用一个点表示其一个子树。用线段树处理修改和查询，注意向上传递和向下传递！
*/
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
const LL MOD = 1000000007;
const int M = 10005;
const int N = 400005;

struct AA{
	int v, next;
}e[N];
struct Tr{
	int left,right;
	int val, sum;
}node[N*4];
int head[N], en, n, m;
int a[N], cnt, num[N];
void add(int u,int v){
	e[en].v = v;
	e[en].next = head[u];
	head[u] = en++;
}
void init(){
	en = cnt = 0;
	memset( head, -1, sizeof( head ) );
	memset( a, 0, sizeof( a ) );
	memset( num, 0, sizeof( num ) );
}
int dfs(int u){
	//if( head[u] == -1 ) num[u] = 1;
	num[u] = 1;
	for(int i=head[u] ; i!=-1 ; i=e[i].next)
		num[u] += dfs( e[i].v );
	a[u] = ++cnt;
	return num[u];
}
void pushup( int id ){
	if( node[id].left == node[id].right ) return ;
	node[id].sum = node[id<<1].sum + node[id<<1|1].sum;
}
void pushdown( int id ){
	if( node[id].val > 0 ){
		node[id<<1].val ^= 1;
		node[id<<1|1].val ^= 1;
		node[id<<1].sum = node[id<<1].right-node[id<<1].left+1-node[id<<1].sum;
		node[id<<1|1].sum = node[id<<1|1].right-node[id<<1|1].left+1-node[id<<1|1].sum;
		node[id].val = 0;
	}
}
void createTree(int l,int r,int id){
	node[id].left = l;
	node[id].right = r;
	node[id].val = 0;
	node[id].sum = 0;
	if( l == r ) return ;

	int mid = (l + r)>>1;
	createTree( l, mid, id<<1 );
	createTree( mid+1, r, id<<1|1);
	pushup(id);
}
void modify(int l,int r,int id){
	if( node[id].left>=l && node[id].right<=r ){
		node[id].val ^= 1;
		node[id].sum = node[id].right-node[id].left+1-node[id].sum;
		return ;
	}
	pushdown(id);
	int mid = (node[id].left+node[id].right)>>1;
	if( r <= mid ) modify( l, r, id<<1 );
	else {
		if( l > mid ) modify( l, r, id<<1|1 );
		else {
			modify( l, mid, id<<1 );
			modify( mid+1, r, id<<1|1 );
		}
	}
	pushup(id);
}
int query(int l,int r,int id){
	if( node[id].left>=l && node[id].right<=r )
		return node[id].sum;
	pushdown(id);
	int mid = (node[id].left + node[id].right)>>1;
	if( r <= mid ) return query( l, r, id<<1 );
	else {
		if( l > mid ) return query( l, r, id<<1|1 );
		else {
			return query( l, mid, id<<1 )+query( mid+1, r, id<<1|1 );
		}
	}
}
int main(){
	int x;
	while( scanf("%d%d", &n, &m) != EOF ){
		init();
		for(int i=2 ; i <= n ; ++i){
			scanf("%d", &x);
			add( x, i );
		}
		dfs( 1 );
		/*for(int i=1 ; i <= n ; ++i)
			printf("%d ", a[i]);
		puts("");*/
		createTree( 1, n, 1 );
		for(int i=0 ; i < m ; ++i){
			char s[2];
			scanf("%s%d", s, &x);
			int l = a[x] - num[x] + 1;
			int r = a[x];
			if( s[0] == 'o' ) modify( l, r, 1 );
			else if( s[0] == 'q' ){
				int res = query( l, r, 1 );
				printf("%d\n", res);
			}
		}
		puts("");
	}
	return 0;
}