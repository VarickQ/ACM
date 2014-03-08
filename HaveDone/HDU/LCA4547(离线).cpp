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
const int inf = 1000000000;
const int N = 200100;
const int M = 500100;

struct A{
	int u, v, next, val;
}e1[M],e2[M];
int head1[N],k1,head2[N],k2;
int fa[N];
int ans[N], n;
bool vis[N], root[N];
void add1(int u,int v,int c){
	e1[k1].u = u;
	e1[k1].v = v;
	e1[k1].val = c;
	e1[k1].next = head1[u];
	head1[u] = k1++;
}
void add2(int u,int v,int c){
	e2[k2].u = u;
	e2[k2].v = v;
	e2[k2].val = c;
	e2[k2].next = head2[u];
	head2[u] = k2++;
}
void init(){
	k1 = k2 = 0;
	memset(head1,-1,sizeof(head1));
	memset(head2,-1,sizeof(head2));
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
	memset(root,true,sizeof(root));
}
int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
int dis[N];
void dfs(int u){
	fa[u] = u;
	vis[u] = true;
	for(int i=head2[u] ; i!=-1 ; i=e2[i].next)
	{
		int son = e2[i].v;
		if (vis[son])
			ans[e2[i].val] = find(son);
	}
	for(int i=head1[u] ; i!=-1 ; i=e1[i].next)
	{
		int son = e1[i].v;
		if (!vis[son]) {
			dis[son] = dis[u] + e1[i].val;
			dfs(son);
			fa[son] = u;
		}
	}
}

char s1[105], s2[105];
map<string,int> ma;
int main(){
    int T, m;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        scanf("%d%d", &n, &m);
		init();
        ma.clear();
        int a, b, c, cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%s%s", s1, s2);
            if (ma.find(s1) == ma.end())
                ma[s1] = ++cnt;
            if (ma.find(s2) == ma.end())
                ma[s2] = ++cnt;
            a = ma[s1];
            b = ma[s2];
            add1( b, a, 1 );
            root[a] = false;
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%s%s", s1, s2);
            a = ma[s1];
            b = ma[s2];
			add2( a, b, i );
			add2( b, a, i );
        }
		for (int i = 1; i <= n; ++i) {
			if (root[i]) {
				dis[i] = 0;
				dfs(i);
				break;
			}
		}
		for (int i = 0; i < k2; i+=2){
			a = e2[i].u;
			b = e2[i].v;
			c = e2[i].val;
			int len = dis[a] - dis[ans[c]];
			if (ans[c] != b) len++;
			printf("%d\n", len);
		}
    }
    return 0;
}