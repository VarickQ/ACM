#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef __int64 ll;
const int N = 100005;

ll a[N],b[25];
int main(){
	int n;
	for(int i=1 ; i <= 20 ; ++i)
		b[i] = (1<<i);
	while( scanf("%d", &n) != EOF ){
		CLR( a, 0 );
		for(int i=1 ; i <= n ; ++i)
			scanf("%I64d", &a[i]);
		if( n <= 1 ) continue;
		ll pos,now=a[1];
		printf("%I64d\n", a[1]);
		if(a[1] > 0){
			for(int i=1 ; i <= 20 ; ++i){
				ll x = 1+b[i];
				if( x > n ){
					a[1+b[i-1]] += a[1];
					pos = i-1;
					break;
				}
			}
		}
		for(int i=2 ; i <= n-1 ; ++i){
			if( a[i] > 0 ){
				if( i+b[pos] > n )
					pos--;
				if(b[pos] > 0) a[i+b[pos]] += a[i];
			}
			now = now+a[i];
			a[i] = 0;
			printf("%I64d\n", now);
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef __int64 ll;
const int N = 20;

int a[N],ans[N][N];
int main(){
	int n;
	while( scanf("%d", &n) != EOF ){
		for(int i=1 ; i <= n*n ; ++i)
			scanf("%d",&a[i]);
		if( n==1 )
			printf("%d\n%d\n",a[1],a[1]);
		else if( n==2 ){
			printf("%d\n", a[1]+a[2]);
			printf("%d %d\n%d %d\n",a[1],a[2],a[3],a[4]);
		}
		else if( n==3 ){
			bool f = false;
			int k,c,num;
			//sort( a+1, a+10 );
			do{
				f = false;
				c = 0;
				k = 1;
				for(int i=1 ; i <= 3 ; ++i)
					for(int j=1 ; j <= 3 ; ++j)
						ans[i][j] = a[k++];

				c = ans[1][1]+ans[2][2]+ans[3][3];

				if(c == ans[1][3]+ans[2][2]+ans[3][1]){
					for(int i=1 ; i <= 3 ; ++i){
						num = 0;
						for(int j=1 ; j <= 3 ; ++j)
							num += ans[i][j];
						if(num != c){
							f = true; break;
						}

						num = 0;
						for(int j=1 ; j <= 3 ; ++j)
							num += ans[j][i];
						if(num != c){
							f = true; break;
						}
					}
				}
				else f = true;
				next_permutation(a+1,a+10);
			}while( f );
			printf("%d\n", c);
			for(int i=1 ; i <= 3 ; ++i){
				for(int j=1 ; j < 3 ; ++j)
					printf("%d ", ans[i][j]);
				printf("%d\n",ans[i][3]);
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
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef __int64 ll;
const int N = 2005;

int n,m,fa[N],k;
struct A{
	int x,y;
}e[N];

int find(int x){//²¢²é¼¯
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void Union(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) fa[fx] = fy;
}
int main(){
	int a,b,q;
	while(scanf("%d%d", &n, &m) != EOF){
		k = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &a, &b);
			e[k].x = a;
			e[k].y = b;
			k++;
		}
		scanf("%d", &q);
		int ans;
		for(int i=0 ; i < q ; ++i){
			scanf("%d%d", &a, &b);
			ans = 0;
			for(int j=0 ; j < k ; ++j){
				for(int tt=1 ; tt <= n ; ++tt)
					fa[tt] = tt;
				for(int tt=0 ; tt < k ; ++tt){
					if( tt == j ) continue;
					Union(e[tt].x,e[tt].y);
				}
				if( find(a) != find(b) ) ans++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}