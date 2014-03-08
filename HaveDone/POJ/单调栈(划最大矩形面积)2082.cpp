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
const int N   = 50005;
typedef long long ll;

struct node{
	int wi,hi;
}b[N];
struct stack{
	int h,pos;
}s[N];
int top,w[N];

int main(){
	int n;
	while( scanf("%d", &n) != EOF ){
		if( n == -1 ) break;
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d", &b[i].wi, &b[i].hi);
		b[n].hi = b[n].wi = 0;
		w[0] = b[0].wi;
		for(int i=1 ; i <= n ; ++i)
			w[i] = w[i-1]+b[i].wi;
		top = 0;
		s[top].h = b[0].hi;
		s[top].pos = 0;
		top++;
		int ans = b[0].hi*b[0].wi;
		for(int i=1 ; i <= n ; ++i){
			if( b[i].hi <= s[top-1].h ){
				while( b[i].hi <= s[top-1].h && top>=1 ){
					int temp = s[top-1].h*(w[i-1]-w[s[top-1].pos-1]);
					if( temp > ans ) ans = temp;
					top--;
				}
				s[top].h = b[i].hi;
				top++;
			} else {
				s[top].h = b[i].hi;
				s[top].pos = i;
				top++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}