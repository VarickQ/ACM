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
const int inf = 1000000000;
const int M = 1000200;
const int N = 10050;

struct A{
	int v,c,next;
}e[N*10];
int k,n,d[N],cnt[N];
int heade[N],qu[N*10];
bool vis[N];
void add(int u,int v,int c){
	e[k].v = v;
	e[k].c = c;
	e[k].next = heade[u];
	heade[u] = k++;
}
int spfa(){
	for(int i=0 ; i <= n ; i++)
		d[i] = inf;
	memset( vis, 0, sizeof( vis ) );
	d[1] = 0;
	int head=0,tail=1;
	qu[0] = 1;
	while(head < tail){
		int u = qu[head++];
		vis[u] = true;
		for(int i=heade[u] ; i!=-1 ; i=e[i].next){
			int v = e[i].v;
			if(d[v] > d[u] + e[i].c){
				d[v] = d[u] + e[i].c;
				if(!vis[v]){
					qu[tail++] = v;
					vis[v] = true;
					if(++cnt[v]>=n) return -1;//判负环
				}
			}
		}
		vis[u] = false;
	}
	return d[n];
}
int main(){
	int ml,md;
	while( scanf("%d%d%d",&n,&ml,&md) != EOF ){
		memset( heade, -1, sizeof( heade ) );
		memset( cnt, 0, sizeof( cnt ) );
		int a,b,d;
		k = 0;
		for(int i=0 ; i < ml ; ++i){
			scanf("%d%d%d",&a,&b,&d);
			add( a, b, d );//b-a<=d
		}
		for(int i=0 ; i < md ; ++i){
			scanf("%d%d%d",&a,&b,&d);
			add( b, a, -d );//b-a>=d,a-b<=-d
		}
		for(int i=2 ; i <= n ; ++i)
			add(i,i-1,0);
		int ans = spfa();
		if(ans==-1)printf("-1\n");
		else if(ans==inf)printf("-2\n");
		else printf("%d\n",ans);
	}
	return 0;
}
//F
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
const int M = 1000200;
const int N = 10050;

struct A{
	int v,c,next;
}e[N*10];
int k,n,d[N],cnt[N];
int heade[N],qu[N*10];
bool vis[N];
void add(int u,int v,int c){
	e[k].v = v;
	e[k].c = c;
	e[k].next = heade[u];
	heade[u] = k++;
}
int spfa(){
	for(int i=0 ; i <= n ; i++)
		d[i] = inf;
	memset( vis, 0, sizeof( vis ) );
	d[1] = 0;
	int head=0,tail=1;
	qu[0] = 1;
	while(head < tail){
		int u = qu[head++];
		vis[u] = true;
		for(int i=heade[u] ; i!=-1 ; i=e[i].next){
			int v = e[i].v;
			if(d[v] > d[u] + e[i].c){
				d[v] = d[u] + e[i].c;
				if(!vis[v]){
					qu[tail++] = v;
					vis[v] = true;
					if(++cnt[v]>=n) return -1;//判负环
				}
			}
		}
		vis[u] = false;
	}
	return d[n];
}
int main(){
	int T,x,y;
	scanf("%d", &T);
	while( T-- ){
		memset( heade, -1, sizeof( heade ) );
		memset( cnt, 0, sizeof( cnt ) );
		k = 0;
		scanf("%d%d%d", &n, &x, &y);
		int a,b,c;
		for(int i=0 ; i < x ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			add( a, b, c );//b-a<=c
		}
		for(int i=0 ; i < y ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			add( b, a, -c );//b-a>=c,a-b<=-c
		}
		for(int i=2 ; i <= n ; ++i)
			add(i,i-1,0);
		int ans = spfa();
		if( ans == -1 ) printf("-1\n");
		else if( ans == inf ) printf("-2\n");
		else printf("%d\n", ans);
	}
	return 0;
}
//H
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
const int M = 1000200;
const int N = 60000;

struct A{
	int u,v,c;
}e[N];
int n,m,w,k,d[N];
void add(int u,int v,int c){
	e[k].c = c;
	e[k].u = u;
	e[k].v = v;
	k++;
}
void bellmanford(){
	int i,j;
	for(i=0 ; i <= n ; i++) d[i]=0;
	bool flag;
	for(i=0 ; i <= n ; i++){
		flag = true;
		for(j=0 ; j < k ; j++){
			if(d[e[j].v] > d[e[j].u]+e[j].c){
				d[e[j].v] = d[e[j].u]+e[j].c;
				flag = false;
			}
		}
		if( flag ) break;
	}
	if( flag ) printf("NO\n");
	else printf("YES\n");
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d", &n, &m, &w);
		k = 0;
		int s,e,t;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &s, &e, &t);
			add( s, e, t );
			add( e, s, t );
		}
		for(int i=0 ; i < w ; ++i){
			scanf("%d%d%d", &s, &e, &t);
			add( s, e, -t );
		}
		bellmanford();
	}
	return 0;
}