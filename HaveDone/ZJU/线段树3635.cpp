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
const int N   = 50010;
const int M   = 50010;
typedef long long LL;
const LL inf = 1LL<<62;

struct Node{
	int left,right,k;
}tr[N*5];
int ans[N];
void biuld(int l,int r,int id){
	tr[id].left = l;
	tr[id].right = r;
	tr[id].k = r-l+1;
	if( l == r ) return;
	int mid = l+r>>1;
	biuld(l,mid,id<<1);
	biuld(mid+1,r,id<<1|1);
}
void update(int id,int x,int i){
	if( tr[id].left == tr[id].right ){
		ans[i] = tr[id].left;
		tr[id].k = 0;
		return ;
	}
	if( tr[id<<1].k >= x ) update(id<<1,x,i);
	else update(id<<1|1,x-tr[id<<1].k,i);
	tr[id].k = tr[id<<1].k+tr[id<<1|1].k;
}
int main(){
	int n,m,x;
	while( scanf("%d", &n) != EOF ){
		biuld( 1, n, 1 );
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &x);
			update( 1, x, i );
		}
		scanf("%d", &m);
		while( m-- ){
			scanf("%d", &x);
			if(m) printf("%d ", ans[x]);
			else printf("%d\n", ans[x]);
		}
	}
	return 0;
}