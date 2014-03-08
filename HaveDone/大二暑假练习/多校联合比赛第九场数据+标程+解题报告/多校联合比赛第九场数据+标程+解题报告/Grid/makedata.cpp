/*
 * Author:  whu_yixiaohan
 * Created Time:  2012/8/15 19:46:27
 * File Name: make.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clrs( x , y ) memset( x , y , sizeof(x) )
int main(){
    freopen("grid.in","w",stdout);
    srand(time(NULL));
    int T = 100 ;
    printf("%d\n" , T );
    while ( T -- ) {
        int mod = 1000 , mod1 = 1000 ;
        if ( T >= 80 ) mod = mod1 = 50 ;
        int n = rand() % mod + 1 , m = rand() % mod + 1 ;
        printf("%d %d\n" , n , m ) ;
        rep( i , m ) {
            mod1 = n ;
            if ( T >= 30 ) mod1 = 100;
            int a = rand() % 2 + 1 ;
            int b = rand() % n + 1 ;
            int c = rand() % mod1 ;
            printf("%d %d %d\n" , a ,b , c ) ;
        } 
            
    }
}

