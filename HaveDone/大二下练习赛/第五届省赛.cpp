//E
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const int N = 1005;

int main(){
	int T,n,c;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=n ; i >= 0 ; --i){
			scanf("%d", &c);
			if(i>1) printf("%d ",c*i);
			if(i==1) printf("%d\n",c*i);
		}
		if( n == 0 ) puts("0");
	}
	return 0;
}
//F
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const int N = 2100;

int c[N];
char str[20];
int main(){
	int T,n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%s", str);
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &c[i]);
		sort( c, c+n );
		if( !strcmp(str,"Faster") ){
			printf("%d\n", c[0]);
		}
		else if( !strcmp(str,"Higher") ){
			printf("%d\n", c[n-1]);
		}
		else if( !strcmp(str,"Stronger") ){
			printf("%d\n", c[n-1]);
		}
	}
	return 0;
}
//A
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const int N = 1005;

bool c[N];
bool check(int x){
	while(x){
		if(x%10==7) return true;
		x /= 10;
	}
	return false;
}
int main(){
	int T,n;
	scanf("%d", &T);
	for(int i=7 ; i <= 799 ; ++i){
		if(i%7==0) c[i] = true;
		else if( check(i) )
			c[i] = true;
	}
	while( T-- ){
		scanf("%d", &n);
		int j,ans;
		for(int i=7 ; i < 800 ; ++i)
		{
			bool f = false;
			for( ans=j=i ; j < i+n ; ++j )
				if( !c[j] ){
					f = true; break;
				}
			if( !f ) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
//B
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const int inf = 1000000000;
const int N = 505;

int n,m;
int mat[N][N],d[N];
bool vis[N];
void Prim(){
	int i,j,Min,mi,sum=0;
	for( i=0 ; i <= n ; ++i )
		d[i] = mat[1][i];
	CLR( vis, false );
	vis[1] = true;
	for( i=2 ; i <= n ; ++i ){
		Min = inf; mi = i;
		for( j=2 ; j <= n ; ++j ){
			if( !vis[j] && d[j] < Min ){
				Min = d[j];
				mi = j;
			}
		}
		sum += Min;
		vis[mi] = true;
		for( j=2 ; j <= n ; ++j )
			if( !vis[j] && d[j] > mat[mi][j] )
				d[j] = mat[mi][j];
	}
	printf("%d\n", sum);
}
int main(){
	int T,a,b,c;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				mat[i][j] = inf;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d",&a,&b,&c);
			a++; b++;
			mat[a][b] = mat[b][a] = c;
		}
		Prim();
	}
	return 0;
}
//G
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const int inf = 1000000000;
const int N = 1265;

char str[N],s[N][50];
map<string,int> ma;
char c[21][20]={"zero","one","two","three","four",
	"five","six","seven","eight","nine","ten",
	"eleven","twelve","thirteen","fourteen","fifteen",
	"sixteen","seventeen","eighteen","nineteen"};
char tttt[20][10]={"twenty","thirty","forty","fifty",
	"sixty","seventy","eighty","ninety" };
int main(){
	for(int i=0 ; i <= 19 ; ++i)
		ma[c[i]] = i;
	for(int i=2,j=0 ; i <= 9 ; ++i,++j)
		ma[tttt[j]] = i*10;

	int T;
	scanf("%d\n", &T);
	while( T-- ){
		gets(str);
		int n = 0,t = 0;
		for(int i=0 ; str[i] ; ++i){
			if( str[i] == ' '){
				s[n][t] = '\0';
				t = 0;
				n++;
			}
			else s[n][t++] = str[i];
		}
		s[n][t] = '\0';
		n++;
		ll ans=0,now=0;
		int p;
		bool mi=false,th=false,bi=false;
		for( p=n-1 ; p >= 0 ; --p ){
			if( !strcmp(s[p],"and") ) continue;
			if( !strcmp(s[p],"thousand"))break;
			if( !strcmp(s[p],"million") )break;
			if( !strcmp(s[p],"hundred") ){
				now += ma[s[p-1]]*100;
				p-=2;
				ans += now;
				now = 0;
				break;
			}
			now += ma[s[p]];
		}
		if( now != 0 ){
			ans += now; now = 0;
		}
		if( !strcmp(s[p],"thousand") ){
			p--;
			for( ; p >= 0 ; --p ){
				if( !strcmp(s[p],"and") ) continue;
				if( !strcmp(s[p],"million") )break;
				if( !strcmp(s[p],"hundred") ){
					now += ma[s[p-1]]*100000;
					p-=2;
					ans += now;
					now = 0;
					break;
				}
				now += ma[s[p]]*1000;
			}
		}
		if( now != 0 ){
			ans += now; now = 0;
		}
		if( !strcmp(s[p],"million") ){
			p--;
			for( ; p >= 0 ; --p ){
				if( !strcmp(s[p],"and") ) continue;
				if( !strcmp(s[p],"hundred") ){
					now += ma[s[p-1]]*100000000;
					p-=2;
					ans += now;
					now = 0;
					break;
				}
				now += ma[s[p]]*1000000;
			}
		}
		if( now != 0 ){
			ans += now; now = 0;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
//K
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const int inf = 1000000000;
const int N = 265;

int n,m,ans;
char mat[N][N];
void check(int i,int j,char ch){
	int cnt = 0;
	for(int k=0 ; k < m ; ++k)
		if(mat[i][k]==ch && mat[j][k]==ch)
			cnt ++;
	ans += cnt*(cnt-1)/2;
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=0 ; i < n ; ++i)
			scanf("%s", mat[i]);
		ans = 0;
		for(int i=0 ; i < n ; ++i)
			for(int j=i+1 ; j < n ; ++j){
				check(i,j,'B');
				check(i,j,'J');
				check(i,j,'H');
				check(i,j,'Y');
				check(i,j,'N');
			}
		printf("%d\n", ans);
	}
	return 0;
}
//H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const int inf = 1000000000;
const int N = 120;

int dp[N][N],t1[N],t2[N],t3[N],f1[N],f2[N];
int main(){
	int T,n,m;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n,&m);
		for(int i=1 ; i <= n ; ++i)
			scanf("%d%d%d%d%d",&t1[i],&t2[i],&t3[i],&f1[i],&f2[i]);
		for(int i=1 ; i <= n ; ++i)
			for(int j=0 ; j <= m ; ++j)
				dp[i][j] = inf;
		dp[0][m] = 0;
		for(int i=1 ; i <= n ; ++i)
			for(int j=0 ; j <= m ; ++j){
				if( dp[i-1][j] != inf ){
					if( j >= f1[i] )
						dp[i][j-f1[i]] = min(dp[i-1][j]+t1[i],dp[i][j-f1[i]]);
					
					dp[i][j] = min(dp[i-1][j]+t2[i],dp[i][j]);

					if( j+f2[i] > m )
						dp[i][m]=min(dp[i][m],dp[i-1][j]+t3[i]);
					else dp[i][j+f2[i]] = min(dp[i-1][j]+t3[i],dp[i][j+f2[i]]);

				}
			}
		int ans = inf;
		for(int i=0 ; i <= m ; ++i)
			if( dp[n][i] < ans )
				ans = dp[n][i];
		printf("%d\n", ans);

	}
	return 0;
}
//L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const int inf = 1000000000;
const int N = 120;

double ans,x[N],y[N],z[N],I[N];
double getDis(double x,double y,double z,int i,int j){
	return sqrt(z*z+(x-i)*(x-i)+(y-j)*(y-j));
}
int main(){
	int T,n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		ans = 0;
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf%lf%lf", &x[i],&y[i],&z[i],&I[i]);

		for(int i=-100 ; i <= 100 ; ++i)
			for(int j=-100 ; j <= 100 ; ++j){
				double r,Max = 0;
				for(int k=0 ; k < n ; ++k){
					r = getDis(x[k],y[k],z[k],i,j);
					double ii = z[k]/r;
					double temp = I[k]/(r*r)*ii;
					Max += temp;
				}
				if( Max > ans ) ans = Max;
			}
		printf("%.2lf\n", ans);
	}
	return 0;
}
//J
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int N = 25;
typedef long long ll;

int n;
double c[N];
struct mat{
	double data[N][N];
	mat(){
		memset( data, 0, sizeof( data ) );
	}
}ma,d;
mat mul(const mat a,const mat b){
	int i,j,k;
	mat c;
	memset(c.data,0,sizeof(c.data));
	for (i=0 ; i < n ; i++)
		for (j=0 ; j < n ; j++)
			for (k=0 ; k < n ; k++)
				c.data[i][j]+=a.data[i][k]*b.data[k][j];
	return c;
}
mat sPow(mat x,int t){
	mat s,temp;
	memset(s.data,0,sizeof(s.data));
	if(t == 0){
		for(int i=0 ; i < n ; ++i)
			s.data[i][i] = 1;
		return s;
	} else {
		temp = sPow(x,t/2);
		if(t&1)
			return mul(mul(temp,temp),x);
		else return mul(temp,temp);
	}
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
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%lf", &c[i]);
		CLR( ma.data , 0 );
		for(int i=0 ; i < n ; ++i){
			int k,t;
			scanf("%d", &k);
			if(k==0) ma.data[i][i] = 1.0;
			for(int j=0 ; j < k ; ++j){
				scanf("%d", &t); t--;
				ma.data[i][t] += 1.0/k;
			}
		}
		int m;
		scanf("%d", &m);
		d = sPow(ma,m);
		for(int i=0 ; i < n ; ++i){
			double res = 0;
			for(int j=0 ; j < n ; ++j)
				res += d.data[j][i]*c[j];
			if(i<n-1) printf("%.2lf ", res);
			else printf("%.2lf\n", res);
		}
	}
	return 0;
}