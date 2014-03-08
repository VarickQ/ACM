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
const int N = 50005;
typedef long long LL;
const LL inf = (1LL<<60);

int t[N];
LL v[N],dp[N];
struct Node{
	int left,right;
	LL num;
}a[N*5];
void CreatT(int l,int r,int id){
	a[id].left = l;
	a[id].right = r;
	a[id].num = inf;
	if( l == r ) return ;
	int mid = (l+r)>>1;
	CreatT( l, mid, 2*id );
	CreatT( mid+1, r, 2*id+1 );
}
void update(int x,int id,LL val){
	if( a[id].left == a[id].right ){
		a[id].num = min( a[id].num, val );
		return ;
	}
	int mid = (a[id].left+a[id].right)>>1;
	if( mid >= x ) update( x, 2*id, val );
	else update( x, 2*id+1, val );
	a[id].num = min( a[2*id].num, a[2*id+1].num );
}
LL get(int l,int r,int id){
	if( a[id].left>=l && a[id].right<=r )
		return a[id].num;
	int mid = (a[id].left+a[id].right)>>1;
	if( r <= mid ) return get(l,r,2*id);
	else {
		if( l > mid ) return get(l,r,2*id+1);
		else return min(get(l,mid,2*id),get(mid+1,r,2*id+1));
	}
}
int main(){
	int n;
	while( scanf("%d", &n) != EOF ){
		for(int i=1 ; i <= n ; ++i)
			scanf("%lld", &v[i]);
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &t[i]);
		CreatT( 1, n, 1 );
		CLR( dp, 0 );
		for(int i=1 ; i <= n ; ++i){
			update( i+t[i]-1>n?n:i+t[i]-1, 1, dp[i-1]+v[i] );
			dp[i] = get( i, n, 1 );
		}
		printf("%lld\n", dp[n]);
	}
    return 0;
}