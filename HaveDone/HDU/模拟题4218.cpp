#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-8;
const int inf = 3;
const int M = 6050000;
const int N = 40;
const double PI=1.7320508075688772935274463415058723669428052538103806280558069794519330169088;

int r;
bool check(int x,int y){
	double d = (x-r)*(x-r)+(y-r)*(y-r);
	double temp = sqrt(fabs(d-r*r));
	if( temp-eps < PI )
		return true;
	return false;
}
int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T, cs = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &r);
		printf("Case %d:\n", ++cs);
		for(int i=0 ; i <= 2*r ; ++i){
			for(int j=0 ; j <= 2*r ;++j){
				if( check(i,j) ) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}