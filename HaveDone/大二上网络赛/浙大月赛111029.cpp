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
const int M = 1000000007;
const int N = 100005;

int main(){
	int T;
	double n,p,zs,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf",&n,&p);
		zs = n*(n-1)/2;
		ans = 0;
		for(int i=1 ; i < n ; ++i)
			ans += 1/(p*i*(n-i)/zs);
		printf("%.3lf\n",ans);
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
const long long M = 1000000007;
const int N = 100005;

long long sPow(long long x,long long n,long long M){
	long long sum = 1;
	while(n){
		if(n&1)sum = sum*x%M;
		x = x*x%M;
		n /= 2;
	}
	return sum;
}
int main(){
	long long p,n,k;
	while(scanf("%lld%lld",&n,&k) != EOF){
		p = (sPow(2,k,M)-1+M)%M;
		printf("%lld\n",sPow(p,n,M));
	}
	return 0;
}

//滚动数组DP 补
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
const int N = 121;

bool dp[2][N][N][N];
int a[N],b[N],c[N];
int main(){
	int n,x,y,z;
	while(scanf("%d",&n) == 1){
		memset(dp,0,sizeof(dp));
		x = y = z = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			x += a[i];
			y += b[i];
			z += c[i];
		}
		int t = 1;//int u,v;
		dp[1][0][0][0] = true;
		for(int w=0 ; w < n ; ++w){
			t = 1-t;//u = w&1; v = u^1;
			memset(dp[t],0,sizeof(dp[t]));//dp[u]
			for(int i=0 ; i <= x ; ++i)
				for(int j=0 ; j <= y ; ++j)
					for(int k=0 ; k <= z ; ++k){
						if(i>=a[w]&&dp[1-t][i-a[w]][j][k]||//dp[v]
							j>=b[w]&&dp[1-t][i][j-b[w]][k]||
							k>=c[w]&&dp[1-t][i][j][k-c[w]])
							dp[t][i][j][k] = true;//dp[u]
					}
		}
		int res = 0;
		for(int i=1 ; i <= 120 ; ++i)
			if(dp[t][i][i][i]){//dp[u]
				res = i; break;
			}
		if(res) printf("%d\n",res);
		else printf("NO\n");
	}
	return 0;
}

//Lucas定理 补
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
const int M = 105555;
const int N = 121;

ll n,m,p;
ll sPow(ll x,ll n,ll p){
	ll sum=1;
	while(n){
		if(n&1) sum=(sum%p)*(x%p)%p;
		x = (x%p)*(x%p)%p;
		n >>= 1;
	}
	return sum%p;
}

ll C(ll n,ll r,ll p){
	ll i,res=1,t;
	for(i=1 ; i <= r ; i++){
		res = (res%p)*((n-i+1)%p)%p;
		t = sPow(i,p-2,p);
		res = (res%p)*(t%p)%p;
	}
	return res;
}

ll lucas(ll n,ll r,ll p){
	if(n<r)	return 0;
	return C(n,r,p);
}
int main(){
	ll res,x,y;
	while(scanf("%lld%lld%lld",&n,&m,&p) != EOF){
		res = 1;
		x = n-m+1;
		y = m;
		if(x < y){
			printf("0\n"); continue;
		}
		while(x&&y){
			res = res*lucas(x%p,y%p,p)%p;
			if(res == 0) break;
			x /= p;
			y /= p;
		}
		printf("%lld\n",res);
	}
	return 0;
}