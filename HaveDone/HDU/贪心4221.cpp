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
const int N = 100050;
int n;
struct node{
    __int64 c,d;
}a[N];
bool cmp(const node a,const node b){
    if(a.d == b.d) return a.c < b.c;
    return a.d < b.d;
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
        scanf("%d", &n);
        for(int i=0 ; i < n ; ++i)
            scanf("%I64d%I64d", &a[i].c, &a[i].d);
        sort( a, a+n, cmp );
        __int64 now=0,ans=0;
        for(int i=0 ; i < n ; ++i){
            now += a[i].c;
            if( now - a[i].d > ans )
                ans = now - a[i].d;
        }
        printf("Case %d: %I64d\n", ++cs, ans);
    }
    return 0;
}