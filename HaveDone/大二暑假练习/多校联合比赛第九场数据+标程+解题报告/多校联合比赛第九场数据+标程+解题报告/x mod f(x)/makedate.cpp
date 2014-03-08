#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

const int T = 45;

int main () {
    freopen ( "data.tmp", "w", stdout );
    srand ( time ( NULL ) );
    printf ( "%d\n", T + 3 );
    printf ( "1 1000000000\n" );
    printf ( "315 315\n" );
    printf ( "108976860 108976860\n" );
    for ( int i = 1; i <= T; i++ ) {
        int a = (int)((double)rand()/RAND_MAX*(1000000000-1)+0.5)+1;
        int b = (int)((double)rand()/RAND_MAX*(1000000000-1)+0.5)+1;
        if ( a > b ) swap ( a, b );
        printf ( "%d %d\n", a, b );
    }
    return 0;
}

