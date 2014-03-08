#include <cstdio>
using namespace std;

int d[10][82][82][82];

void init () {
    for ( int i = 1; i <= 81; i++ )
        d[0][0][i][0] = 1;
    for ( int l = 0; l < 9; l++ )
        for ( int i = 0; i <= (l<<3)+l; i++ )
            for ( int j = 1; j <= 81; j++ )
                for ( int k = 0; k < j; k++ )
                    for ( int x = 0; x <= 9; x++ )
                        d[l+1][i+x][j][(k*10+x)%j] += d[l][i][j][k];
}

int calc ( int x ) {
    if ( x == 0 ) return 0;
    
    int re = 0;
    if ( x == 1000000000 ) { re++; x--; }
    int len, sum, t, tt, power = 1, bit[11];
    len = sum = 0;
    t = tt = x;
    while ( t > 0 ) {
        bit[++len] = t % 10;
        t /= 10;
        sum += bit[len];
    }
    if ( x % sum == 0 ) re++;
    for ( int i = 1; i <= len; i++ ) {
        tt /= 10; power *= 10;
        t = tt * power;
        sum -= bit[i];
        for ( int j = 0; j < bit[i]; j++ ) {
            for ( int k = sum + j; k <= sum + ( (i-1) << 3 ) + i - 1 + j; k++ ) {
                if ( k == 0 ) continue;
                int dd = t % k;
                if ( dd > 0 ) dd = k - dd;
                re += d[i-1][k-sum-j][k][dd];
            }
            t += power / 10;
        }
    }
    return re;
}

int main () {
  //  freopen ( "data.in", "r", stdin );
  //  freopen ( "data.out", "w", stdout );
    init ();
    int T;
    scanf ( "%d", &T );
    for ( int case_num = 1; case_num <= T; ) {
        int a, b;
        scanf ( "%d%d", &a, &b );
        printf ( "Case %d: %d\n", case_num++, calc(b) - calc(a-1) );
    }
    return 0;
}
