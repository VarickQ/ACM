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
const int N   = 850;
const int M   = 200010;
const int inf = 2000000000;
typedef __int64 LL;

int num[N],n,k,p[N];
bool vis[N];
struct Node{
	int nn[N],len;
}a[N];
void gao(){
	int id = 0;
	for(int i=1 ; i <= n ; ++i){
		a[id].nn[a[id].len++] = num[i];
		id = (id+1)%k;
	}
	id = 0;
	for(int i=0 ; i < k ; ++i){
		for(int j=a[i].len-1 ; j >= 0 ; --j)
			num[++id] = a[i].nn[j];
		a[i].len = 0;
	}
}
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
int main(){
	while( scanf("%d%d", &n, &k) && (n+k) ){
		if( n <= k ) printf("1\n");
		else {
			for(int i=1 ; i <= n ; ++i)
				num[i] = i;
			gao();
			for(int i=1 ; i <= n ; ++i)
				p[num[i]] = i;
			LL ans = 1;
			memset( vis, 0, sizeof( vis ) );
			for(int i=1 ; i <= n ; ++i){
				int tmp = i,l = 0;
				while( !vis[tmp] ){
					vis[tmp] = true;
					tmp = p[tmp];
					l++;
				}
				if(l) ans = ans/gcd(ans,l)*l;
			}
			printf("%I64d\n", ans);
		}
	}
	return 0;
}