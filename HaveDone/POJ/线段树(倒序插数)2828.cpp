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
const int N = 200005;
typedef long long LL;

int ans[N];
struct Node{
	int pos,val;
}a[N];
struct Tree{
	int left,right,cnt;
}tree[N*3];

void CreateTree(int l, int r, int id){
	tree[id].left = l;
	tree[id].right = r;
	tree[id].cnt = r-l+1;
	if( l == r ) return ;
	int mid = (l+r)>>1;
	CreateTree( l, mid, 2*id );
	CreateTree( mid+1, r, 2*id+1 );
}
int tmp;
void query(int id,int num){
	if( tree[id].left == tree[id].right ){
		tree[id].cnt = 0;
		tmp = tree[id].left;
		return ;
	}
	if( num <= tree[2*id].cnt ) query( 2*id, num );
	else query( 2*id+1, num-tree[2*id].cnt );
	tree[id].cnt--;
}

int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int n;
	while( scanf("%d", &n) != EOF ){
		CLR( ans, 0 );
		CreateTree( 1, n, 1 );
		for(int i=1 ; i <= n ; ++i)
			scanf("%d%d", &a[i].pos, &a[i].val);
		for(int i=n ; i > 0 ; --i){
			query( 1, a[i].pos+1 );
			ans[tmp] = a[i].val;
		}
		for(int i=1 ; i < n ; ++i)
			printf("%d ", ans[i]);
		printf("%d\n", ans[n]);
	}
	return 0;
}