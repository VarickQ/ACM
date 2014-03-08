#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 ll;
const int inf = 2000000000;
const int N   = 100005;

int fa[N],rank[N];
//rank[x]=
//    0    ��ʾ�ڵ�x��father[x]Ϊͬ��
//    1    ��ʾx��father[x]
//    2    ��ʾx��father[x]��
int find( int x ){
	if(fa[x] == x) return x;
	else {
		int temp = fa[x];
		fa[x] = find( fa[x] );
		rank[x] = (rank[temp]+rank[x])%3;
		return fa[x];
	}
}
void Union( int x, int y, int d ){
	int rx = find( x );
	int ry = find( y );
	//s��ʾ a��b�Ĺ�ϵ
	//s=rank[a]+rank[ra]-rank[b]
	//rank[ra]= s-rank[a]+rank[b]
	fa[rx] = ry;
	rank[rx] = (rank[y]-rank[x]+d+3)%3;
}
int main(){
	int n,m,d,x,y;
	scanf("%d%d", &n, &m);
	for(int i=0 ; i <= n ; ++i){
		fa[i] = i;
		rank[i] = 0;
	}
	int ans = 0;
	for(int i=0 ; i < m ; ++i){
		scanf("%d%d%d", &d, &x, &y);
		if( x>n || y>n ) ans++;
		else if( d==2 && x==y ) ans++;
		else {
			int rx = find( x );
			int ry = find( y );
			if( rx == ry ){
				if( (rank[x]-rank[y]+3)%3 != d-1 )
					ans ++;
			} else {
				Union( x, y, d-1 );
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}