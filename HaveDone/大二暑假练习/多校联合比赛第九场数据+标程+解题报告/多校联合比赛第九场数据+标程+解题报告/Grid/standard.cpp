/*
 * Author:  whu_yixiaohan
 * Created Time:  2012/8/15 16:17:01
 * File Name: grid.cpp
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
#define maxint 100000000
#define maxn 1100 
typedef struct operation{
    int a , x ;
    operation(int _a, int _x): a(_a), x(_x) {}
    bool operator < ( const operation &q ) const {
        return q.a > a ;
    }
}ope;
vector<ope> op1 , op2 ;
int T_T , n , m , ans1 , ans2 ;
int l[maxn],r[maxn];
void clear(){
    repf( i , 1 , 1010 ) 
        l[i] = r[i] = maxint ;
    op1.clear() ; op2.clear() ;
}
void init(){//读入处理 然后把操作放进vector里排序
    scanf( "%d %d" , &n , &m ) ;
    rep( i , m ) {
        int s , a , x ;
        scanf("%d %d %d" , &s , &a , &x ) ;
        if ( s == 1 ) 
            op1.push_back( operation( a , x ) ) ;
        else if ( s == 2 ) 
            op2.push_back( operation( a , x ) ) ;
    } 
    sort( op1.begin() , op1.end() ) ;
    sort( op2.begin() , op2.end() ) ;
}
void getlr(){//背包过程 得到l和r数组
    l[0] = 0 ;
    rep ( i , op1.size() ) {
        int a = op1[i].a , x = op1[i].x ;
        repd( j , a , x )
            l[j] = min( l[j] , l[j-x] + 1 ) ;
    } 
    r[n+1] = 0 ;
    repd( i , op2.size() - 1 , 0 ) {
        int a = op2[i].a , x = op2[i].x ;
        repf( j , a , n - x + 1 ) 
            r[j] = min( r[j] , r[j+x] + 1 ) ;  
    }
}
int getans1() {        
    l[0] = r[n+1] = maxint ;
    repd( i , n , 0 ){//从大到小枚举能填满的格子总数 遇到第一个可行的即为第一个答案
        if ( ( l[i] != maxint )  || ( r[n-i+1] != maxint ) )  return i ;
        repf( j , 1 , i-1 )  
            if ( ( l[j] != maxint ) && ( r[n-(i-j) + 1] != maxint ) )    
                return i ;
    }
    return 0 ;
}
int getans2( int ans1 ) {//对于第一个答案 枚举所有方案 取操作数最小的
    int ans2 = min( l[ans1] , r[ n - ans1 + 1] ) ;
    repf( i , 1 , ans1 - 1 ) 
        ans2 = min( ans2 , l[i] + r[n-(ans1-i)+1] ) ; 
    if ( ans1 == 0 ) ans2 = 0 ;
    return ans2 ;
}
int main(){
  //  freopen("grid.in","r",stdin);
//	freopen("grid.out","w",stdout);
    scanf( "%d" , &T_T );
    repf( t , 1 , T_T ){
        clear() ;
        init() ;
        getlr() ;
        int ans1 = getans1() ;
        int ans2 = getans2( ans1 ) ;
        printf("Case %d: %d %d\n" , t , ans1 , ans2 ) ;
    }
}

