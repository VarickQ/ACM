//B
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 100000000;
const int M   = 35000;
const int N   = 505;
typedef long long ll;

struct node{
	int x,y,val;
	bool operator < (const node &a) const{
		//return c < a.c;//从大到小
		return val > a.val;//从小到大
	}
}a;
int n,m,t;
bool vis[N][N];
char mat[N][N];
int v[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
priority_queue<node> qu;
int bfs()
{
	qu.push(a);
	int i;
	while( !qu.empty() )
	{
		node ff=qu.top(); node f;  qu.pop();
		for( i=0 ; i < 4 ; i++ )
		{
			f.x = ff.x+v[i][0];
			f.y = ff.y+v[i][1];
			f.val = ff.val+1;
			if( f.x<0 || f.x>=n || f.y<0 || f.y>=m )
				return f.val;
			if( f.x>=0&&f.x<n && f.y>=0&&f.y<m && mat[f.x][f.y]!='#')
			{
				if( !vis[f.x][f.y] ){
					vis[f.x][f.y] = true;
					if( mat[f.x][f.y]=='.' ) qu.push(f);
					else if( mat[f.x][f.y]=='@'){
						f.val += t;
						qu.push(f);
					}
				}
			}
		}
	}
    return -1;
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		memset( vis, 0, sizeof( vis ) );
		while( !qu.empty() ) qu.pop();
		scanf("%d%d%d",&n,&m,&t);
		for(int i=0 ; i < n ; ++i)
			scanf("%s", mat[i]);
		for(int i=0 ; i < n ; ++i)
			for(int j=0 ; j < m ; ++j)
				if( mat[i][j] == 'S' ){
					a.x = i;
					a.y = j;
					a.val = 0;
				}
		vis[a.x][a.y] = true;
		printf("%d\n",bfs());
	}
	return 0;
}
//1010
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main () {
	int t;
	scanf ("%d", &t);
	while (t --) {
		int N, b;
		int resx = -1, resy = -1;
		scanf ("%d", &N);
		int k = 1 + (int)sqrt (1.0 * N);
		for (int i = k; i >= 1; --i) {
			if (N % i == 0 && N / i >= i) {
				b = N / i;
				if ((b + i) % 2 || (b - i) % 2) continue;
				resy = (b + i) >> 1;
				resx = (b - i) >> 1;
				break;
			}
		}
		if (resx == -1) printf ("IMPOSSIBLE\n");
		else printf ("%d %d\n", resx, resy);
	}
}
//4203 博弈，找规律
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 ll;

int main () {
	int T, s, k;
	scanf ("%d", &T);
	while (T --) {
		scanf("%d%d", &s, &k);
		if( k&1 ){
			if( s&1 ) printf("1\n");
			else printf("0\n");
		} else {
			if( s < k ) printf("%d\n", s%2);
			else {
				if( s%(k+1) == k ) printf("%d\n", k);
				else printf("%d\n", (s%(k+1))%2);
			}
		}
	}
	return 0;
}
//A 4197补，砍气球
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define PI 3.1415926535897932384626433832795

struct ball{
	double l,r;
}b[1005];
bool cmp(const ball &a, const ball &b){
	return a.r < b.r;
}
bool kill(ball a, double x){
	if( a.l < a.r ){
		if( a.l <= x && x <= a.r ) return true;
	} else {
		if( a.l <= x || x <= a.r ) return true;
	}
	return false;
}
int main () {
	int T,n,x,y,r;
	scanf ("%d", &T);
	while (T --) {
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i){
			scanf("%d%d%d", &x, &y, &r);
			double tr = atan2((double)y,(double)x);
			double d = sqrt((double)(x*x+y*y));
			double th = asin((double)r/d);
			b[i].l = tr - th;
			if( b[i].l < -PI ) b[i].l += 2.0*PI;
			b[i].r = tr + th;
			if( b[i].r >= PI ) b[i].r -= 2.0*PI;
		}
		sort( b, b+n, cmp );
		int ans = n;
		for(int i=0 ; i < n ; ++i){
			int cnt = 1;
			double last = b[i].r;
			for(int j=(i+1)%n ; j!=i ; j=(j+1)%n){
				if( !kill(b[j],last) ){
					cnt++;
					last = b[j].r;
				}
			}
			ans = min( cnt, ans );
		}
		printf("%d\n", ans);
	}
	return 0;
}