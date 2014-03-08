#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
typedef long long LL;
const int N   = 1000005;
const int M   = 300000;
const LL inf = 1000000000;
const double PI = acos(-1.0);

LL a[N];
int b[N];
void euler(){
    int i, j; 
    for( i=1 ; i <= N ; ++i ) b[i]=i;
    for( i=2 ; i <= N ; i+=2 ) b[i]/=2;
    for( i=3 ; i <= N ; i+=2 )
        if( b[i] == i ) {
            for( j=i ; j <= N ; j+=i )
                b[j] = b[j]/i*(i-1);
		}
}
int main(){
	int n;
	euler();
	a[2] = 1;
	for(int i=3 ; i <= N-5 ; ++i)
		a[i] = a[i-1]+b[i];
	while( scanf("%d", &n) && n ){
		printf("%lld\n", a[n]);
	}
    return 0;
}