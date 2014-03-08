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
const int inf = 1000000000;
const int M   = 100000;
const int N   = 105;
typedef long long ll;

int p[N];
int main(){
	int T,n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		int Min = -1,pos;
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &p[i]);
			if( Min < p[i] ){
				Min = p[i];
				pos = i;
			}
		}
		sort( p+1, p+n+1 );
		printf("%d %d\n", pos, p[n-1]);
	}
	return 0;
}

//B
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t --)
	{
		double H, h, D;
		cin >> H >> h >> D;

		double y = D - h/H*D;
		double x = sqrt(H*y) - y;

		double x1 = h/H * D;
		//cout << y << endl;
		if ( x > x1 || x < 0)
		{
			printf("%.3lf\n", max(h,x1));
		}
		else
		{
			double x2 = (H*x)/(x+y) + D - y - x;
			printf("%.3lf\n", max(h, max(x1,x2)));
		}
	}
}
//B 三分法
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
const double eps = 1e-10;//1e-8 WA
const int inf = 1000000000;
const int M   = 100000;
const int N   = 105;
typedef long long ll;

double H,h,D;
double getLen( double x ){
	return (x*H+h*D-H*D)/x+(D-x);
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%lf%lf%lf", &H, &h, &D);
		double l = D*(H-h)/H,r = D;
		while( fabs(r-l) >= eps ){
			double mid = (l+r)/2;
			double mmid = (mid+r)/2;
			if( getLen(mid) > getLen(mmid) )
				r = mmid;
			else l = mid;
		}
		printf("%.3lf\n", getLen(l));
	}
	return 0;
}

//C
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
const int inf = 1000000000;
const int M   = 100000;
const int N   = 20005;
typedef long long ll;

int fa[N],n,m,cnt;
struct edge{
	int x,y,value;
}e[N],ans[N];
bool cmp(edge a,edge b){
	if( a.value == b.value ){
		if( a.x == b.x ) return a.y < b.y;
		else return a.x < b.x;
	}
	else return a.value < b.value;
}
bool cmp2(edge a, edge b){
	if( a.x == b.x )
		return a.y < b.y;
	return a.x < b.x;
}
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void Kruskal(){
	for(int i=0 ; i <= n ; ++i) fa[i] = i;
	sort( e, e+m, cmp );
	for(int i=0 ; i < m ; ++i){
		int x = find(e[i].x);
		int y = find(e[i].y);
		if(x != y){
			ans[cnt++] = e[i];
			fa[x] = y;
		}
	}
	if( cnt != n-1 ) printf("-1\n");
	else {
		sort( ans, ans+cnt, cmp2 );
		for(int i=0 ; i < cnt-1 ; ++i)
			printf("%d %d ", ans[i].x,ans[i].y);
		printf("%d %d\n", ans[cnt-1].x,ans[cnt-1].y);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		int c;
		m = cnt = 0;
		for(int i=1 ; i <= n ; ++i){
			for(int j=1 ; j <= n ; ++j){
				scanf("%d", &c);
				if( c != 0 ){
					e[m].x = i;
					e[m].y = j;
					e[m++].value = c;
				}
			}
		}
		Kruskal();
	}
	return 0;
}
//F
#include<stdio.h>
#include<string>
#include<set>
#include<iostream>
using namespace std;
set<string> keywords;
int main()
{
	int N;
	scanf("%d",&N);
    keywords.clear();
	string word;
	while(N--){
	  cin>> word;
	  keywords.insert(word);
	}

	int K;
	scanf("%d",&K);
	while(K--)
	{
		scanf("%d",&N);
		int ans = N;
		while(N--)
		{
			cin>>word;
			if(keywords.find(word) == keywords.end()) {
				ans -- ;
			}
		}

		printf("%d\n",ans);
	}
	return 0;
}
//I
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
const int inf = 1000000000;
const int M   = 100000;
const int N   = 105;
typedef long long ll;

int a[N],b[N];
int main(){
	int T,n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &a[i]);
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &b[i]);
		bool fqu=true,fs=true;
		for(int i=0,j=n-1 ; i<n && j>=0 ; ++i,--j){
			if( a[i] != b[i] )
				fqu = false;
			if( a[i] != b[j] )
				fs = false;
		}
		if( fqu && fs ) puts("both");
		else if( !fqu && !fs ) puts("neither");
		else if( fqu ) puts("queue");
		else if( fs ) puts("stack");

	}
	return 0;
}
//J
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
const double eps = 1e-10;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 255;
typedef long long ll;

struct Tree{
	int have,up;
}a[N];
int n,m,dp[N][N];
bool cmp( const Tree &a, const Tree &b ){
	return a.up < b.up;
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &a[i].have);
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &a[i].up);
		sort( a+1, a+n+1, cmp );

		CLR( dp, 0 );//i天砍前j棵树的最大受益
		for(int i=1 ; i <= m ; ++i){
			dp[i][i] = dp[i-1][i-1]+a[i].have+a[i].up*(i-1);
			for(int j=i+1 ; j <= n ; ++j){
				dp[i][j] = max( dp[i][j-1], dp[i-1][j-1]+a[j].have+a[j].up*(i-1));
			}
		}
		printf("%d\n", dp[m][n]);
	}
	return 0;
}

//K
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
const int inf = 1000000000;
const int M   = 100000;
const int N   = 22;
typedef long long ll;

int mat[N][N];
int main(){
	int T,n,m,k,i,j;
	scanf("%d", &T);
	while( T-- ){
		CLR( mat, 0 );
		scanf("%d%d%d", &n, &m, &k);
		int num = 1;
		for( i=0 ; i < n ; ++i )
			for( j=0 ; j < m ; ++j )
				mat[i][j] = num++;
		for( i=1 ; i < n-1 ; ++i )
			for( j=1 ; j < m-1 ; ++j ){
				if( k > 0 ){
					mat[i][j] = 0;
					mat[i-1][j] = mat[i+1][j] = 0;
					mat[i][j-1] = mat[i][j+1] = 0;
					k--;
				}
			}
		for( i=0 ; i < n ; ++i ){
			for( j=0 ; j < m-1 ; ++j )
				printf("%d ", mat[i][j]);
			printf("%d\n", mat[i][m-1]);
		}

	}
	return 0;
}