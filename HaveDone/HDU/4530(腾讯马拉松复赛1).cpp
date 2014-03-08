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
const int inf = 1000000000;
const int N = 1005;
typedef long long LL;

int main(){
    int T, x, q, a, b;
    scanf("%d", &T);
    while( T-- ){
        scanf("%d%d", &x, &q);
        for(int i=0 ; i < q ; ++i){
            scanf("%d%d", &a, &b);
            if( a == 1 ){
                double t = b*(60.0-x);
                printf("%.2lf\n", t);
            }
            else if( a == 2 ){
                double t = b*60.0+b*60.0/(60.0-x)*x;
                printf("%.2lf\n", t);
            }
            else if( a == 3 ){
                double t = b*43200.0*60.0/x;
                printf("%.2lf\n", t);
            }
        }
    }
    return 0;
}