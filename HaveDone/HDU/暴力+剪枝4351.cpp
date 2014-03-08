#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <time.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 100005;
typedef __int64 LL;

LL a[N], sum[N];
int main(){
    int T, n, cs=0;
    scanf("%d", &T);
    while( T-- ){
        scanf("%d", &n);
        LL x;
        memset( sum, 0, sizeof( sum ) );
        for(int i=1 ; i <= n ; ++i){
            scanf("%I64d", &x);
            if( x == 0 ) a[i] = 0;
            else if(x%9 == 0) a[i] = 9;
            else a[i] = x%9;
            if(i>1) sum[i] = sum[i-1]+a[i];
            else sum[i] = a[i];
        }
        int q, l, r, ok;
        bool v[20];
        printf("Case #%d:\n", ++cs);
        scanf("%d", &q);
        while( q-- ){
            memset( v, 0, sizeof( v ) );
            ok = 0;
            scanf("%d%d", &l, &r);
            for(int j=0 ; j <= r-l ; ++j){
                for(int i=l ; i+j <= r ; ++i){
                    LL tmp = sum[i+j]-sum[i-1];
                    if( tmp == 0 ) tmp = 0;
                    else if( tmp%9 == 0 ) tmp = 9;
                    else tmp %= 9;
                    v[tmp] = true;
                    ok = v[9]+v[8]+v[7]+v[6]+v[5];
                    if(ok==5) break;
                }
                if(ok==5) break;
            }
            int cnt = 0;
            for(int i=9 ; i >= 0 ; --i){
                if( v[i] ){
                    printf("%d", i);
                    cnt++;
                    if( cnt < 5 ) printf(" ");
                    else if( cnt == 5 ){
                        printf("\n"); break;
                    }
                }
            }
            if( cnt < 5 ){
                for(int i=cnt ; i < 4 ; ++i) printf("-1 ");
                printf("-1\n");
            }
        }
        if( T ) printf("\n");
    }
    return 0;
}