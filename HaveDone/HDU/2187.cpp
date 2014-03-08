#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-10
#define zero(x) (((x)>0?(x):-(x))<eps)
const int M = 10000;
const int N = 10002;

int main(){
	int T,n,m,p[26],h,k;
	scanf("%d",&T);
	while(T--){
		memset(p,0,sizeof(p));
		scanf("%d%d",&n,&m);
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d",&k,&h);
			p[k] += h;
		}
		double ans=0;
		for(int i=1 ; i <= 25 ; ++i){
			double t = 1.0*n/i;
			if(t <= p[i]){
				ans += t;
				break;
			} else {
				ans += p[i];
				n -= i*p[i];
			}
			if(n < 0) break;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}