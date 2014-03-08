#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-8;
const int inf = 1000000000;
const int M = 6050000;
const int N = 262200;

int n,m,k;
struct Node{
	int left,right,num;
}node[N*3];
void CreateTree(int l,int r,int id){
	node[id].left = l;
	node[id].right = r;
	if( l == r ){
		node[id].num = 1;
		return ;
	}
	int mid = (l+r)>>1;
	CreateTree( l, mid, 2*id );
	CreateTree( mid+1, r, 2*id+1 );
	node[id].num = node[2*id].num + node[2*id+1].num;
}
int res;
void search(int x,int id){
	if( node[id].left == node[id].right ){
		node[id].num--;
		res = node[id].left;
		return ;
	}
	if( node[2*id].num >= x ) search(x,2*id);
	else search(x-node[2*id].num,2*id+1);
	//递归回来后 由左右孩子的sum值更新父亲的sum值
	node[id].num = node[2*id].num + node[2*id+1].num;
}
int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
    int T, cs = 0;
    scanf("%d", &T);
    while (T--) {
		scanf("%d%d", &n, &m);
		CreateTree( 1, n, 1 );
		__int64 ans = 0;
		while( m-- ){
			scanf("%d", &k);
			search( k, 1 );
			ans += res;
		}
		printf("Case %d: %I64d\n", ++cs, ans);
    }
    return 0;
}