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
typedef __int64 LL;
const double eps = 1e-8;
const LL MOD = 1000000007;
const int inf = 1000000000;
const int M = 100005;
const int N = 100005;

int b[N];
struct A{
    int d, p;
}a[N];
bool cmp(const A &a,const A &b){
    if( a.p == b.p ) return a.d > b.d;
    return a.p < b.p;
}
multiset<int> st;
multiset<int>::iterator it;
int main(){
    int n, m, x;
    while( scanf("%d%d", &n, &m) != EOF ){
        st.clear();
        for(int i=0 ; i < n ; ++i){
            scanf("%d", &x);
            st.insert(x);
        }
        for(int i=0 ; i < m ; ++i)
            scanf("%d", &a[i].d);
        for(int i=0 ; i < m ; ++i)
            scanf("%d", &a[i].p);
        if( m < n ){
            puts("No"); continue;
        }
        sort( a, a+m, cmp );
        LL ans = 0;
        for(int i=0 ; i < m ; ++i){
            it = st.upper_bound( a[i].d );
            if( it != st.begin() ){
                it--;
                st.erase(it);
                ans += a[i].p;
                if( st.empty() ) break;
            }
        }
        if( st.empty() ) printf("%I64d\n", ans);
        else puts("No");
    }
    return 0;
}