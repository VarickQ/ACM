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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 100000;
const int N   = 1000005;
//typedef long long ll;

int sum[N],a[N],dp1[N],dp2[N];
int main(){
	int n;
	while( scanf("%d", &n) && n ){

		memset( sum, 0, sizeof( sum ) );
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &a[i]);

		sum[0] = a[0];
		for(int i=1 ; i < n ; ++i)
			sum[i] = sum[i-1]+a[i];

		memset( dp1, 0, sizeof( dp1 ) );
		dp1[0] = a[0];
		for(int i=1 ; i < n ; ++i)
			dp1[i] = min( dp1[i-1], sum[i]);

		memset( dp2, 0, sizeof( dp2 ) );
		dp2[n-1] = sum[n-1];
		for(int i=n-2 ; i >= 0 ; --i)
			dp2[i] = min( dp2[i+1], sum[i]);

		int ans = 0;
		if(dp2[0] >= 0) ans++;
		for(int k=1 ; k < n ; ++k)
			if( dp2[k]>=sum[k-1] && dp1[k-1]>=sum[k-1]-sum[n-1] )
				ans++;
		printf("%d\n", ans);
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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 100000;
const int N   = 1005;
//typedef long long ll;


struct Node{
	char name[15];
	int books[8];
}a[N];
bool mark[N],vis[N],mat[N][N];
int num[N];

int main(){
	int b,n;
	while( scanf("%d%d", &b, &n) && (n+b) ){
		memset( a, 0, sizeof( a ) );
		memset( mat, 0, sizeof( mat ) );
		memset( vis, 0, sizeof( vis ) );
		memset( num, 0, sizeof( num ) );

		for(int i=1 ; i <= n ; ++i){
			scanf("%s", a[i].name);
			mat[i][i] = true;
			for(int j=1 ; j < i ; ++j)
				if( strcmp(a[j].name,a[i].name) == 0 )
					mat[i][j] = mat[j][i] = true;
			for(int j=1 ; j <= b ; ++j)
				scanf("%d", &a[i].books[j]);
		}

		for(int i=1 ; i <= n ; ++i){//读同一本书多次
			memset( mark, 0, sizeof( mark ) );
			sort( a[i].books+1, a[i].books+b+1 );
			for(int j=1 ; j <= b ; ++j){
				if( mark[a[i].books[j]] && !vis[a[i].books[j]] ){
					vis[a[i].books[j]] = true;
				}
				if( !mark[a[i].books[j]] ){
					mark[a[i].books[j]] = true;
					num[a[i].books[j]]++;
				}
			}
		}

		for(int i=1 ; i <= n ; ++i){
			memset( mark, 0, sizeof( mark ) );
			for(int j=1 ; j <= b ; ++j)
				mark[a[i].books[j]] = true;
			for(int j=1 ; j <= n ; ++j){
				if( mat[i][j] ){//不能读同伙写的书包括自己
					if( mark[j] && !vis[j] )
						vis[j] = true;
				}
			}
		}

		for(int i=1 ; i <= n ; ++i)
			if( num[i] != b && !vis[i] )
				vis[i] = true;
		int ans = 0;
		for(int i=1 ; i <= n ; ++i)
			if( vis[i] ) ans++;
		if( ans == 0 )
			printf("NO PROBLEMS FOUND\n");
		else if( ans == 1 )
			printf("1 PROBLEM FOUND\n");
		else printf("%d PROBLEMS FOUND\n", ans);
	}
	return 0;
}

//D 补
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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 100000;
const int N   = 500005;
typedef long long ll;

int c[N],b,n;
bool ok( int mid ){
	int cnt = 0;
	for(int i=0 ; i < n && cnt <= b ; ++i){
		//cnt += (int)ceil(1.0*c[i]/mid);
		cnt += (c[i]+mid-1)/mid;//向上取整
	}
	return (cnt <= b);
}
int main(){
	int l,r,mid;
	while( scanf("%d%d", &n, &b) != EOF ){
		if( n==-1 && b==-1 ) break;
		r = -1;
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &c[i]);
			r = r>c[i]?r:c[i];
		}
		l = 1;
		while( r > l+1 ){
			mid = (l+r)/2;
			if( ok(mid) ) r = mid;
			else l = mid;
		}
		if( ok(l) ) printf("%d\n", l);
		else printf("%d\n", r);
	}
	return 0;
}