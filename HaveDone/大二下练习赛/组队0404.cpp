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
const int inf = 1000000000;
const int M   = 100000;
const int N   = 10005;
//typedef long long ll;
struct A{
	int l,r,c;
}node[N];
int k,a[N];
void insert(int n,int id){
	if(node[id].c < n){//right
		if(node[id].r == -1){
			node[id].r = k;
			node[k++].c = n;
		} else {
			insert(n,node[id].r);
		}
	} else {
		if(node[id].l == -1){
			node[id].l = k;
			node[k++].c = n;
		} else {
			insert(n,node[id].l);
		}
	}
}
void fun(int n){
	if(node[n].l != -1)
		fun(node[n].l);
	if(node[n].r != -1)
		fun(node[n].r);
	printf("%d\n",node[n].c);
}
int main(){
	int n,m=0,i;
	memset(node,-1,sizeof(node));
	while(scanf("%d",&n) == 1){
		a[m++] = n;
	}
	k = 0;
	node[k++].c = a[0];
	for(int i=1 ; i < m ; ++i)
		insert(a[i],0);
	if(node[0].l != -1)
		fun(node[0].l);
	if(node[0].r != -1)
		fun(node[0].r);
	printf("%d\n",node[0].c);
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
const long long inf = (1LL<<60);
const int M   = (1<<20);
const int N   = 10005;
typedef long long ll;

struct A{
	ll f,c;
}a[25];
int main(){
	int n,m;
	ll v,t,ans;
	while( scanf("%d", &n) == 1 ){
		for(int i=0 ; i < n ; ++i)
			scanf("%lld%lld", &a[i].f, &a[i].c);
		scanf("%d", &m);
		for(int i=0 ; i < m ; ++i){
			scanf("%lld%lld",&v,&t);
			ans = inf;
			for(int i=1 ; i < M ; ++i){
				int s = i;
				ll totF = 0,totC = 0;
				for(int j=0 ; j < n ; ++j){
					if( s&1 ){
						totF += a[j].f;
						totC += a[j].c;
					}
					s >>= 1;
				}
				if( v < totF*t )
					ans = min(ans,totC);
			}

			printf("Case %d: ",i+1);
			if( ans == inf ) printf("IMPOSSIBLE\n");
			else printf("%lld\n",ans);
		}
	}
	return 0;
}
//D
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

const int maxn = 88888;
bool vis[maxn];
int prime[maxn];
int tprime[maxn];
int ansprime[maxn];

void initPrime () {
	for (int i = 3; i < maxn; i += 2) {
		vis[i] = 1;
		vis[i - 1] = 0;
	}
	vis[2] = 1;
	for (int i = 3; i * i < maxn; i += 2) {
		if (vis[i]) {
			int k = i * 2;
			int t = k + i;
			while (t < maxn) {
				vis[t] = 0;
				t += k;
			}
		}
	}
	prime[0] = prime[1] = 2;
	for (int i = 3; i < maxn; i += 2) {
		if (vis[i]) prime[prime[0]++] = i;
	}
}

int numOfAnsPrime (int x, int &sum) {
	int res = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
		res ++;
	}
	return res;
}

int main () {
	initPrime ();
	int cnt = 1;
	for (int i = 1; i < prime[0] - 1; ++i) {
		if (prime[i + 1] - prime[i] == 2) {
			tprime[cnt++] = prime[i];
		}
	}
	int k = 1;
	/** 所有的孪生素数*/
	for (int i = 2; i < 8888 && k < cnt; ++i) {
		if (i >= tprime[k]) k++;
		ansprime[i] = tprime[k];
	}
	int n, t;
	while (scanf ("%d%d", &n, &t) == 2) {
		if (n == 0 && t == 0) break;
		int sum = 0;
		int num = numOfAnsPrime (ansprime[t], sum);
		for (int i = 1; i < n - num + 1; ++i) {
			if (i == 1) {
				if ((sum + 1) % 3 == 0) printf ("2");
				else printf ("1");
			}
			else
			printf ("0");
		}
		printf ("%d\n", ansprime[t]);
	}
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
const int M = (1<<22);

int num[125];
struct S{
	int l,co[125];
	S(){
		l = 0;
		memset( co, 0, sizeof( co ) );
	}
}s[1125];
bool vis[25];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T,n,m;
	char ch[1000];
	while( scanf("%d", &T) != EOF ){
		while(T--){
			memset( num, 0, sizeof( num ) );
			memset( s, 0, sizeof( s ) );

			scanf("%d%d\n", &n, &m);
			for(int i=1 ; i <= m ; ++i){
				gets(ch);
				int now = 0;
				for(int j=0 ; ch[j] ; ++j){
					if( ch[j] == ' ' ){
						if( now != 0 ){
							num[now]++;
							s[i].co[s[i].l++] = now;
							now = 0;
						}
						continue;
					}
					if( ch[j] <= '9' && ch[j] >= '0' )
						now = now*10+ch[j]-'0';
				}
				if( now != 0 ){
					num[now]++;
					s[i].co[s[i].l++] = now;
					now = 0;
				}
			}
			bool ans = false;
			for(int i=1 ; i < M ; ++i){
				int sta = i;
				memset( vis, 0, sizeof( vis ) );
				for(int j=1 ; j <= n ; ++j){
					if( sta&1 ) vis[j] = true;
					sta >>= 1;
				}
				bool f = false;
				for(int j=1 ; j <= m ; ++j){
					if( s[j].l == 1 ) continue;
					int cnt = 0;
					for(int t=0 ; t < s[j].l ; ++t)
						cnt += vis[s[j].co[t]]?1:0;
					if( cnt == s[j].l || cnt == 0 ){
						f = true; break;
					}
				}
				if( !f ){
					ans = true; break;
				}
			}
			if( ans ) printf("Y");
			else printf("N");
		}
	}
	return 0;
}