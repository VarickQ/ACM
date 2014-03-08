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
#define Lowbit(x) ((x)&(-x))
const double eps = 1e-10;
typedef long long LL;
const LL inf = 1000000000;
const LL M   = 100000;
const LL N   = 105;

struct Node{
	double p;
	LL t,v;
}a[N];
double pp[N][55],tt[N][55];
LL c[55][55];
void C(){
	for(LL i=0; i<55; i++)
		c[0][i] = 1;
	for(LL i=1; i<55; i++)
		for(LL j=i; j<55; j++)
			c[i][j] = c[i-1][j-1]+c[i][j-1];
}
inline double Pow(double a,LL k){
	double res = 1.0;
	while( k-- ) res *= a;
	return res;
}
int main(){
	C();
	LL n, m, l;
	while( scanf("%lld%lld%lld", &n, &m, &l) != EOF ){
		CLR( pp, 0 );
		CLR( tt, 0 );
		LL p;
		for(LL i=0 ; i < n ; ++i){
			scanf("%lld%lld%lld", &p, &a[i].t, &a[i].v);
			a[i].p = p/100.0;
		}
		for(LL i=0 ; i < n ; ++i)
			for(LL j=0 ; j <= m ; ++j){
				pp[i][j] = c[j][m]*Pow(a[i].p,j)*Pow(1.0-a[i].p,m-j);
				tt[i][j] = 1.0*l/a[i].v+1.0*a[i].t*j;
			}
		for(LL i=0 ; i < n ; ++i){
			double tmp, ppp = 0.0;
			for(LL j=0 ; j <= m ; ++j){
				tmp = pp[i][j];
				for(LL k=0 ; k < n ; ++k){
					double t = 0.0;
					if( k == i ) continue;
					for(LL q=0 ; q <= m ; ++q){
						if( tt[k][q]-tt[i][j] > eps )
							t += pp[k][q];
					}
					tmp *= t;
				}
				ppp += tmp;
			}
			printf("%.12lf\n", ppp);
		}
	}
	return 0;
}