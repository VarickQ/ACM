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
const int N   = 5010;
typedef long long LL;

int a[N];
struct Node{
	int left, right, num;
}node[N*4];
void createTree(int l, int r, int id){
	node[id].left = l;
	node[id].right = r;
	node[id].num = 0;
	if( l == r ) return ;
	
	int mid = (l+r)/2;
	createTree( l, mid, id*2 );
	createTree( mid+1, r, id*2+1);
}
void insert(int l,int id){
	if( node[id].left==l && l==node[id].right )
		node[id].num = 1;
	else {
		int mid = (node[id].left+node[id].right)>>1;
		if( mid >= l )
			insert( l, id*2 );
		else
			insert( l, id*2+1 );
		node[id].num = node[2*id].num+node[2*id+1].num;
	}
}
int getsum(int l, int r, int id ){
	if( node[id].left>=l && node[id].right<=r )
		return node[id].num;
	else {
		int x=0,y=0,mid = (node[id].left+node[id].right)>>1;
		if( l <= mid )
			x = getsum(l,r,2*id);
		if( r >= mid )
			y = getsum(l,r,2*id+1);
		return x+y;
	}
}
int main(){
	int n;
	while( scanf("%d", &n) != EOF ){
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &a[i]);
		createTree( 0, n-1, 1 );
		int Min,ans = 0;
		for(int i=0 ; i < n ; ++i){
			ans += getsum( a[i], n-1, 1 );
			insert( a[i], 1 );
		}
		Min = ans;
		for(int i=0 ; i < n ; ++i){
			ans = ans-a[i]+n-a[i]-1;
			if( Min > ans ) Min = ans;
		}
		printf("%d\n", Min);
	}
	return 0;
}