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
const int N   = 200005;

int fa[N],cha[N];
int find(int x){
    if( fa[x] == x ) return x;
    else {
        int tt = find( fa[x] );
        cha[x] += cha[fa[x]];
        fa[x] = tt;
        return tt;
    }
}
void Union( int x, int y, int rx, int ry ,int d ){
    fa[ry] = rx;
    cha[ry] = cha[x]-cha[y]+d;
}
int main(){
    int n,m,a,b,x,ans;
    while( scanf("%d%d", &n, &m) != EOF ){
        memset( cha, 0, sizeof( cha ) );
        for(int i=0 ; i <= n ; ++i)
            fa[i] = i;
        ans = 0;
        for(int i=0 ; i < m ; ++i){
            scanf("%d%d%d", &a, &b, &x);
            a--;
            int rx = find( a );
            int ry = find( b );
            if( rx == ry && cha[b]-cha[a] != x )
                    ans++;
            else if( rx != ry )
                Union( a, b, rx, ry, x );
        }
        printf("%d\n", ans);
    }
    return 0;
}