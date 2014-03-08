//G
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
const int N   = 105;
typedef long long ll;

int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T;
	char s[N];
	scanf("%d", &T);
	while( T-- ){
		scanf("%s", s);
		bool f = false;
		for(int i=0 ; s[i] ; ++i)
			if( s[i] == 'D' )
				f = true;
		if( f ) puts("You shall not pass!");
		else puts("Possible");
	}
	return 0;
}
//E
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
const int M   = 2010;
const int N   = 1050;
typedef long long ll;

bool su[M];
int prime[N],cnt;
int ans[N];
void getprime(){
	su[1] = su[0] = true;
	for(ll i=2 ; i <= M-100 ; i++)
		if(!su[i]){
			for(ll j=i*i ; j <= M-100 ; j+=i)
				su[j] = true;
		}
	cnt = 0;
	for(int i=2 ; i <= M-100 ; ++i)
		if(!su[i]) prime[cnt++] = i;
}
bool check(int x){
	int k = 0, num = 0;
	while( k < cnt ){
		if( x%prime[k]==0 ){
			while(x%prime[k]==0)
				x /= prime[k];
			num ++;
		}
		k++;
	}
	if( num >= 3 ) return true;
	else return false;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T,cc=0,n;
	getprime();
	for(int i=30 ; cc <= 1005 ; ++i)
		if( check(i) )
			ans[cc++] = i;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		printf("%d\n", ans[n-1]);
	}
	return 0;
}
//A
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
const int M   = 2010;
const int N   = 505;
typedef long long ll;

int n,m,mat[N][N],dp[N][N];
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= m ; ++j){
				scanf("%d", &mat[i][j]);
				dp[i][j] = inf;
			}
		dp[n][m] = 1;
		for(int i=n ; i >= 1 ; --i)
			for(int j=m ; j >= 1 ; --j){
				dp[i-1][j] = min(dp[i-1][j],dp[i][j]-mat[i-1][j]);
				if( dp[i-1][j] <= 0 )
					dp[i-1][j] = 1;
				dp[i][j-1] = min(dp[i][j-1],dp[i][j]-mat[i][j-1]);
				if( dp[i][j-1] <= 0 )
					dp[i][j-1] = 1;
			}
		////////////////
		//for(int i=1 ; i <= n ; ++i){
		//	for(int j=1 ; j <= m ; ++j)
		//		printf("%d ", dp[i][j]);
		//	printf("\n");
		//}
		////////////////////
		printf("%d\n", dp[1][1]);
	}
	return 0;
}
//B
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
#define eps 1e-8
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
#define abs(x) ((x)>0?(x):-(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 2010;
const int N   = 255;
typedef long long ll;

struct point{
	double x,y;
}a,b[3],mm1,mm2;

bool mark[N][N];
double getdis(int x,int y,point a){
	return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
}
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//判点在凸多边形内或多边形边上,顶点按顺时针或逆时针给出
int inside_convex(point q,int n,point* p){
	int i,s[3]={1,1,1};
	for (i=0;i<n&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
	return s[1]|s[2];
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T,n,l;
	char str[5];
	scanf("%d", &T);
	while( T-- ){
		mm1.x = mm1.y = 1000.0;
		mm2.x = mm2.y = -1000.0;
		scanf("%d", &n);
		CLR( mark, false );
		while( n-- ){
			scanf("%s", str);
			if( str[0] == 'C' ){
				int r;
				scanf("%lf%lf%d",&a.x,&a.y,&r);
				if(mm1.x > a.x-r) mm1.x = a.x-r;
				if(mm1.y > a.y-r) mm1.y = a.y-r;
				if(mm2.x < a.x+r) mm2.x = a.x+r;
				if(mm2.y < a.y+r) mm2.y = a.y+r;
				for(int i=(int)a.x-r ; i <= (int)a.x+r ; ++i)
					for(int j=(int)a.y-r ; j <= (int)a.y+r ; ++j)
						if( getdis(i,j,a) <= r+0.0 )
							mark[i+50][j+50] = true;
			}
			else if( str[0] == 'T' ){
				point a1,a2;
				a1.x = a1.y = 1000.0;
				a2.x = a2.y = -100.0;
				for(int i=0 ; i < 3 ; ++i){
					scanf("%lf%lf",&b[i].x,&b[i].y);
					if( a1.x > b[i].x )a1.x = b[i].x;
					if( a1.y > b[i].y )a1.y = b[i].y;
					if( a2.x < b[i].x )a2.x = b[i].x;
					if( a2.y < b[i].y )a2.y = b[i].y;
				}
				if(mm1.x > a1.x) mm1.x = a1.x;
				if(mm1.y > a1.y) mm1.y = a1.y;
				if(mm2.x < a2.x) mm2.x = a2.x;
				if(mm2.y < a2.y) mm2.y = a2.y;
				for(int i=(int)a1.x ; i <= (int)a2.x ; ++i)
					for(int j=(int)a1.y ; j <= (int)a2.y ; ++j){
						point tt;
						tt.x = i+0.0;
						tt.y = j+0.0;
						if( inside_convex(tt,3,b) )
							mark[i+50][j+50] = true;
					}
			}
			else if( str[0] == 'S' ){
				scanf("%lf%lf%d",&a.x,&a.y,&l);
				if(mm1.x > a.x) mm1.x = a.x;
				if(mm1.y > a.y) mm1.y = a.y;
				if(mm2.x < a.x+l) mm2.x = a.x+l;
				if(mm2.y < a.y+l) mm2.y = a.y+l;
				for(int i=(int)a.x ; i <= (int)a.x+l ; ++i)
					for(int j=(int)a.y ; j <= (int)a.y+l ; ++j)
						mark[i+50][j+50] = true;
			}
		}
		int ans = 0;
		for(int i=(int)mm1.x ; i <= (int)mm2.x ; ++i)
			for(int j=(int)mm1.y ; j <= (int)mm2.y ; ++j){
				if( mark[i+50][j+50] ){
					//cout<<"("<<i<<","<<j<<")"<<endl;
					ans++;
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}
//J
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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int M   = 2010;
const int N   = 505;
typedef long long ll;

int n,m;
struct point{
	int x,y,t;
	char id;
}a[30];
queue<point> qu;
char map[N][N];
int zl[N][N];
int v[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool check( int x, int y ){
	if( x>=0 && x<n && y>=0 && y<m )
		return true;
	return false;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T;
	scanf("%d", &T);
	while( T-- ){
		CLR( zl, 0 );
		while(!qu.empty()) qu.pop();
		scanf("%d%d", &n, &m);
		for(int i=0 ; i < n ; ++i){
			scanf("%s", map[i]);
			for(int j=0 ; map[i][j] ; ++j){
				if( map[i][j]<='z' && map[i][j]>='a' ){
					point temp;
					temp.id = map[i][j];
					temp.t = 0;
					temp.x = i;
					temp.y = j;
					qu.push(temp);
				}
			}
		}
		point ff,f;
		while( !qu.empty() ){
			ff=qu.front(); qu.pop();
			if(map[ff.x][ff.y]=='*') continue;
			for(int i=0 ; i < 4 ; ++i){
				f.id = ff.id;
				f.x = ff.x+v[i][0];
				f.y = ff.y+v[i][1];
				f.t = ff.t+1;
				if( check(f.x,f.y) ){
					if( map[f.x][f.y] == '.' ){
						map[f.x][f.y] = f.id;
						zl[f.x][f.y] = f.t;
						qu.push(f);
					}
					else if(map[f.x][f.y]>='a' && map[f.x][f.y]<='z'){
						if(map[f.x][f.y]!=f.id && zl[f.x][f.y]==f.t)
							map[f.x][f.y] = '*';
					}
				}
			}
		}
		for(int i=0 ; i < n ; ++i)
			printf("%s\n",map[i]);
		printf("\n");
	}
	return 0;
}