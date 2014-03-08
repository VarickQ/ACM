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
const int inf = 2000000000;
const int M = 100000;
const int N = 1005;

int main(){
	int T,a[3],b[3];
	scanf("%d",&T);
	while(T--){
		for(int i=0 ; i < 3 ; ++i)
			scanf("%d",&a[i]);
		sort(a,a+3);
		for(int j=0 ; j < 3 ; ++j)
			scanf("%d",&b[j]);
		sort(b,b+3);
		if(a[2] > b[2]) printf("1\n");
		else printf("2\n");
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
const int inf = 2000000000;
const int M = 1000;
const int N = 1005;

int mat[N][N];
ll sum[N][N];
ll check(int x,int y,int h){
	return sum[x+h][y+h]-sum[x+h][y-1]-sum[x-1][y+h]+sum[x-1][y-1];
}
int main(){
	int T,i,j;
	int n,m;
	ll lim,s;
	scanf("%d",&T);
	while(T--){
		memset(sum,0,sizeof(sum));
		scanf("%d%d%lld",&n,&m,&lim);
		for(i=1 ; i <= n ; ++i)
			for(j=1 ; j <= m ; ++j){
				scanf("%d",&mat[i][j]);
				sum[i][j] = mat[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
			}
		int ans=0;
		s = 0;
		for(i=1 ; i <= n ; ++i){
			for(j=1 ; j <= m ; ++j){
				int l,r,mid;
				l = 1; r = min(n-i+1,m-j+1);
				while(l <= r){
					mid = (l+r)/2;
					s = check(i,j,mid-1);
					if(s <= lim){
						if(ans < mid*mid)
							ans = mid*mid;
						l = mid+1;
					}
					else r = mid-1;
				}
			}
		}
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
typedef long long ll;
const int inf = 2000000000;
const int M = 1000;
const int N = 1005;

ll f[32],n;
int main(){
	int i;
	f[0] = 0;
	f[1] = 2;
	for(i=2 ; i <= 31 ; ++i)
		f[i] = (1LL<<i);
	while(scanf("%d",&n) == 1){
		for(i=0 ; i <= 31 ; ++i)
			if(n < f[i]){
				printf("%d\n",i);
				break;
			}
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
const int inf = 2000000000;
const int M = 1000;
const int N = 105;

char str[N][M],a[M],b[M];
int main(){
	int T,n,m,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=0 ; i < n ; ++i)
			scanf("%s",str[i]);
		for(i=0 ; i < m ; ++i){
			scanf("%s %s",a,b);
			for(j=0 ; j < n ; ++j){
				bool f = false;
				for(k=0 ; a[k] ; ++k)
					if(a[k] != str[j][k]){
						f = true; break;
					}
				if(!f){
					f = false;
					int len = strlen(str[j]);
					for(k=len-1 ; str[j][k] ; --k)
						if(str[j][k]=='.') break;
					f = false;
					int p;
					for(p=0 ; str[j][k]&&b[p] ; ++k,++p)
						if(b[p] != str[j][k]){
							f = true; break;
						}
					if(str[j][k] || b[p]) f=true;
					if(!f)printf("%s\n",str[j]);
				}
			}
		}
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
const int inf = 2000000000;
const int M   = 1000000000;
const int N   = 100005;

int a[N],b[N];
int main()
{
	int n,m;
	ll ans;
	while(scanf("%d%d",&n,&m) == 2){
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		for(int i=1 ; i <= n ; ++i)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		b[1] = 1;
		for(int i=2 ; i <= n ; ++i){
			if(a[i] == a[i-1]) b[i]=b[i-1]+1;
			else b[i] = 1;
		}
		for(int i=n ; i >= 2 ; --i)
			if(a[i] == a[i-1]) b[i-1] = b[i];
		ans = 0;
		for(int i=1 ; i <= n ; ++i){
			int l,r,mid;
			l = 1; r = n;
			while(l <= r){
				mid = (l+r)/2;
				if(a[i]+a[mid] == m) break;
				if(a[i]+a[mid] < m)
					l = mid+1;
				else r = mid-1;
			}
			if(a[i]+a[mid]==m){
				ans += b[mid];
				if(a[i] == a[mid]) ans--;
			}
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}

//H
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

long long a[55];

int main()
{
	long long n,t,m,i;
	a[1] = 1;
	for(i = 2;i < 33;++i)
		a[i] = a[i-1]*3;
	while(scanf("%lld",&n) == 1)
	{
		int ans = 0;
		while(n > 0)
			n -= a[++ans];
		printf("%d\n",ans);
	}
	return 0;
}