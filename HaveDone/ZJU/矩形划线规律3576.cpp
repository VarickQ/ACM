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
const int inf = 1000000000;
const int N = 1005;

long long gcd( long long a,long long b ){
	if( b == 0 ) return a;
	else return gcd( b, a%b );
}
int main(){
	long long m,n;
	while( scanf("%lld%lld", &m, &n) == 2 ){
		long long g = gcd( m, n );
		n /= g;
		m /= g;
		double len = sqrt(1.0*n*n+m*m)*g;
		if( n%2==0 || m%2==0 )
			printf("%.3lf\n", len/2.0);
		else
			printf("%.3lf\n", len*(1.0/2+1.0/(2*n*m)));
	}
	return 0;
}