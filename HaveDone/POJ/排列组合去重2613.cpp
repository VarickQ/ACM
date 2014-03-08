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
typedef __int64 ll;
const int inf = 2000000000;
const int N   = 100050;

double c1[N],c2[N],ans;
bool cmp( double a, double b ){
	return a > b;
}
int main(){
	//freopen( "in.txt", "r", stdin );

	double i,j,p,q,r,s;
	int k1,k2;
	while( scanf("%lf%lf%lf%lf", &p, &q, &r, &s) != EOF ){

		k1 = 0;
		for( i=s ; i > 1 ; --i ) c1[k1++] = i;
		for( i=p-q+1 ; i <= p ; ++i ) c1[k1++] = i;
		sort( c1, c1+k1, cmp );

		k2 = 0;
		for( i=q ; i > 1 ; --i ) c2[k2++] = i;
		for( i=r-s+1 ; i <= r ; ++i ) c2[k2++] = i;
		sort( c2, c2+k2, cmp );

		int x,y;
		for( x=y=0 ; x < k1 && y < k2 ; ){
			if( c1[x] < c2[y] ) y++;
			else if( c1[x] > c2[y] ) x++;
			else {
				c1[x] = c2[y] = 1;
				x++; y++;
			}
		}
		sort( c1, c1+k1, cmp );
		sort( c2, c2+k2, cmp );
		while( c1[k1-1] == 1 ) k1--;
		while( c2[k2-1] == 1 ) k2--;

		ans = 1.0;
		for( x=y=0 ; x < k1 && y < k2 ; x++,y++)
			ans *= c1[x]/c2[y];
		while( x < k1 ) ans *= c1[x++];
		while( y < k2 ) ans /= c2[y++];

		printf("%.5lf\n", ans);
	}
	return 0;
}