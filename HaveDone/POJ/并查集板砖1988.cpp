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
const int N   = 30010;

int fa[N],c[N],cb[N];
int find( int x )
{
    if(fa[x] == x) return x;
	else {
		int tmp = fa[x];
		fa[x] = find( fa[x] );
		cb[x] += cb[tmp];
		return fa[x];
	}
}
void Union( int x, int y, int rx, int ry )
{
    fa[rx] = ry;
	cb[rx] += c[ry];
	c[ry] += c[rx];
}
int main(){
	int n,a,b;
	char ch[2];
	for(int i=0 ; i <= N ; ++i){
		fa[i]=i; c[i]=1; cb[i]=0;
	}
	scanf("%d", &n);
	while( n-- ){
		scanf("%s", ch);
		if( ch[0] == 'M' ){
			scanf("%d%d", &a, &b);
			int rx = find( a );
			int ry = find( b );
			if( rx != ry ) Union( a, b, rx, ry );
		} else {
			scanf("%d", &a);
			find( a );
			printf("%d\n", cb[a]);
		}
	}
	return 0;
}