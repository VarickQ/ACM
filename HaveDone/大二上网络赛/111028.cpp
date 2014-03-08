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
#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int inf = 2000000000;
const int M = 10100;
const int N = 100010;

ll c[N];
int main(){
	int n,m,d;
	ll ans,temp;
	while(scanf("%d%d",&n,&m) == 2){
		if(n==-1&&m==-1) break;
		ans = 0;
		memset(c,0,sizeof(c));
		for(int i=1 ; i <= n ; ++i){
			scanf("%d",&d);
			c[i] = c[i-1]+d;
		}
		for(int i=1 ; i <= n ; ++i)
			ans += c[i]*m;
		printf("%lld\n",ans);
	}
	return 0;
}

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
#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int inf = 2000000000;
const int M = 10100;
const int N = 510;

char s[N],t[N];
int main(){
	int i,j,ans;
	while(scanf("%s%s",s,t) != EOF){
		if(s[0]=='*' && t[0]=='*') break;
		int len = strlen(s);
		bool f = false;
		ans = 0;
		for(int i=0 ; i < len ; ++i){
			if(s[i] != t[i]){
				f = true; continue;
			}
			if(f){
				ans++; f = false;
			}
		}
		if(f) ans++;
		printf("%d\n",ans);
	}
	return 0;
}

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
#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif
#define eps 1e-6
const int M = 10100;
const int N = 110;

struct A{
	double x,y,f;
}c[N];
double mat[N][N];
int n;
double dis(A a,A b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	int i,j,k;
	double px,py,lx,ly;
	while(scanf("%d%lf%lf%lf%lf",&n,&px,&py,&lx,&ly) != EOF){
		if(n==-1&&px==-1&&py==-1&&lx==-1&&ly==-1) break;
		n++;
		for(i=1 ; i < n ; ++i)
			scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].f);
		c[0].x = px;
		c[0].y = py;
		c[0].f = 0;
		c[n].x = lx;
		c[n].y = ly;
		c[n].f = 0;
		for(i=0 ; i <= n ; ++i)
			for(j=0 ; j <= n ; ++j)
				mat[i][j] = min(dis(c[i],c[j]),fabs(dis(c[i],c[j])-c[i].f));

		for(k=0 ; k <= n ; ++k)
			for(i=0 ; i <= n ; ++i)
				for(j=0 ; j <= n ; ++j)
					if(mat[i][k]+mat[k][j] < mat[i][j])
						mat[i][j] = mat[i][k]+mat[k][j];
		printf("%.2lf\n",mat[0][n]);
	}
	return 0;
}

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

typedef long long ll;

const int M = 10100;
const int N = 505;

int main(){
	int n,ans;
	ll sum,l,r,a[N],x,i,j;
	while(scanf("%d",&n) == 1){
		if(n == -1) break;
		sum = ans = 0;
		for(i=0 ; i < n-1 ; ++i){
			scanf("%lld",&a[i]);
			sum += a[i];
		}
		sort(a,a+n-1);
		l = (n-1)/2-1;
		r = (n-1)/2;
		x = a[l]*n-sum;
		if(x < a[l]){
			bool f = false;
			for(i=0 ; i < n ; ++i)
				if(x == a[i]){
					f = true; break;
				}
			if((sum+x)%n == 0 && !f)
				ans++;
		}
		x = a[r]*n-sum;
		if(x > a[r]){
			bool f = false;
			for(i=0 ; i < n ; ++i)
				if(x == a[i]){
					f = true; break;
				}
			if((sum+x)%n == 0 && !f)
				ans++;
		}
		if(sum%(n-1)==0){
			x = sum/(n-1);
			if(a[l] < x && a[r] > x)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}