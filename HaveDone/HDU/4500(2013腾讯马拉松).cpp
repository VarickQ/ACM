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
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 2000010;
const int N   = 25;
typedef __int64 LL;

int mat[N][N];
int main(){
    int n, m;
    while( scanf("%d%d", &n, &m) && (n+m) ){
        memset( mat, 0, sizeof( mat ) );
        for(int i=1 ; i <= n ; ++i)
            for(int j=1 ; j <= m ; ++j)
                scanf("%d", &mat[i][j]);
        int Max = -inf, pi, pj;
        for(int i=1 ; i <= n ; ++i)
            for(int j=1 ; j <= m ; ++j){
                int t = mat[i+1][j]+mat[i-1][j]+mat[i][j+1]+mat[i][j-1];
                if( mat[i][j] > 0 ) t = -t;
                if( t > Max ){
                    Max = t;
                    pi = i; pj = j;
                }
            }
        printf("%d %d %d\n", pi, pj, Max);
    }
    return 0;
}