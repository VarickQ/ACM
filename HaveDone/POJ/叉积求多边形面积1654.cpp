#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define PI acos(-1.0)
typedef long long LL;
const double eps = 1e-10;
const int N = 1000005;

struct point{
	int x,y;
}p[N];
char s[N];
int xmult(const point &b,const point &c){
	return b.x*c.y-c.x*b.y;
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%s", s);
		int n = 0;
		p[0].x = 0;
		p[0].y = 0;
		for(int i=0 ; s[i]!='5' ; ++i){
			n++;
			if( s[i] == '1' ){
				p[i+1].x = p[i].x-1;
				p[i+1].y = p[i].y-1;
			}
			else if( s[i] == '2' ){
				p[i+1].x = p[i].x;
				p[i+1].y = p[i].y-1;
			}
			else if( s[i] == '3' ){
				p[i+1].x = p[i].x+1;
				p[i+1].y = p[i].y-1;
			}
			else if( s[i] == '4' ){
				p[i+1].x = p[i].x-1;
				p[i+1].y = p[i].y;
			}
			else if( s[i] == '6' ){
				p[i+1].x = p[i].x+1;
				p[i+1].y = p[i].y;
			}
			else if( s[i] == '7' ){
				p[i+1].x = p[i].x-1;
				p[i+1].y = p[i].y+1;
			}
			else if( s[i] == '8' ){
				p[i+1].x = p[i].x;
				p[i+1].y = p[i].y+1;
			}
			else if( s[i] == '9' ){
				p[i+1].x = p[i].x+1;
				p[i+1].y = p[i].y+1;
			}
		}
		LL ans = 0;//精度问题，不能用double
		for(int i=1 ; i < n-1 ; ++i)
			ans += xmult(p[i],p[i+1]);
		if( ans < 0 ) ans = -ans;
		if( ans%2 == 0 ) printf("%lld\n", ans/2);
		else printf("%lld.5\n", ans/2);
	}
	return 0;
}