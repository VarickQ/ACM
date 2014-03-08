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
#define EPS 1e-8
const int N = 55;

struct Point{
	int x,y;
}p[N];
int xmult(const Point &a,const Point &b,const Point &c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int xmult(const Point &b,const Point &c){
	return b.x*c.y-c.x*b.y;
}
int main(){
	int T, n, m, t, a[N];
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d", &p[i].x, &p[i].y);
		int Max = 0, ans;
		scanf("%d", &m);
		for(int i=0 ; i < m ; ++i){
			scanf("%d", &t);
			for(int j=0 ; j < t ; ++j){
				scanf("%d", &a[j]);
				a[j]--;
			}
			int tmp = 0;
			for(int j=0 ; j < t ; ++j)
				tmp += xmult(p[a[j]],p[a[(j+1)%t]]);
			if(tmp > Max){
				Max = tmp;
				ans = i+1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}