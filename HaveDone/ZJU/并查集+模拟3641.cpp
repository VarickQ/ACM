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
const int N   = 100010;

char s[25],na[25],nb[25];
set<int> a[N];
set<int>::iterator it;
map<string,int> ma;
int fa[N],id;
int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
int main(){
	int n;
	while( scanf("%d", &n) != EOF ){
		ma.clear();
		for(int i=0 ; i <= n ; ++i){
			fa[i] = i;
			a[i].clear();
		}
		id = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%s", s);
			if( !strcmp(s,"arrive") ){
				int m,x;
				scanf("%s%d", na, &m);
				if(ma.find(na) == ma.end())
					ma[na] = ++id;
				for(int j=0 ; j < m ; ++j){
					scanf("%d", &x);
					a[ma[na]].insert(x);
				}
			}
			else if( !strcmp(s,"share") ){
				scanf("%s%s", na, nb);
				int x = find(ma[na]);
				int y = find(ma[nb]);
				if( x == y ) continue;
				for(it=a[x].begin() ; it != a[x].end() ; it++)
					a[y].insert(*it);
				a[x].clear();
				fa[x] = y;
			}
			else if( !strcmp(s,"check") ){
				scanf("%s", na);
				printf("%d\n", a[find(ma[na])].size());
			}
		}
	}
	return 0;
}