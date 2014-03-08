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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 100005;
typedef long long ll;

ll h[N],ans;
struct stack{
	ll high;
	int pos;
}s[N];
int top;
int main(){
	int n;
	while( scanf("%d", &n) && n ){
		for(int i=0 ; i < n ; ++i)
			scanf("%lld", &h[i]);
		h[n] = 0;
		ans = h[0];
		top = 0;
		s[top].high = h[0];
		s[top].pos = 0;
		top++;
		for(int i=1 ; i <= n ; ++i){
			if( h[i] <= s[top-1].high ){
				while( h[i] <= s[top-1].high && top>=1 ){
					ll temp = s[top-1].high*(i-s[top-1].pos);
					if(ans < temp) ans = temp;
					top--;
				}
				s[top].high = h[i];
				top++;
			} else {
				s[top].high = h[i];
				s[top].pos = i;
				top++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}