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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 105;
const int N   = 105;
typedef long long ll;

int a[N],num[N],d[N];
int main(){
	int n,w,x;
	while( scanf("%d%d", &n, &w) && (n+w) ){
		memset( num, 0, sizeof( num ) );
		memset( d, 0, sizeof( d ) );
		int Max = -1;
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &x);
			num[x]++;
			Max = Max>x?Max:x;
		}
		int duan = Max/w+1;
		for(int i=0 ; i < duan ; ++i){
			int cnt = 0;
			for(int j=i*w ; j < (i+1)*w ; ++j)
				cnt += num[j];
			d[i] += cnt;
		}
		int fm = -1;
		for(int i=0 ; i < duan ; ++i)
			if( d[i] > fm )
				fm = d[i];
		double ans=0;
		for(int i=duan-1,j=0 ; i >= 0 ; --i,++j)
			ans += (d[j]*1.0/fm)*(i*1.0/(duan-1));
		printf("%6lf\n",ans+0.01);
	}
	return 0;
}