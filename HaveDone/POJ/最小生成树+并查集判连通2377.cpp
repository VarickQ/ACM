#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll __int64
const int inf = 2000000000;
const int N = 20100;

int mark[1005][1005];
int fa[N],n,m;
struct edge{
	int x,y,value;
}e[N];
bool cmp(edge a,edge b){
	return a.value > b.value;
}
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void Union(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fy != fx)
       fa[fx] = fy;
}
void Kruskal(){
	int ans = 0;
	for(int i=0 ; i <= n ; ++i) fa[i] = i;
	sort(e,e+m,cmp);
	for(int i=0 ; i < m ; ++i){
		int x = find(e[i].x);
		int y = find(e[i].y);
		if(x != y){
			ans += e[i].value;
			fa[x] = y;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	int i,j,a,b,c;
	while(scanf("%d%d",&n,&m) == 2)
	{
		for(i=0 ; i <= n ; ++i) fa[i] = i;
		memset(mark,0,sizeof(mark));
		for(i=0 ; i < m ; ++i){
			scanf("%d%d%d",&a,&b,&c);
			if(mark[a][b] < c){
				mark[a][b] = c;
				e[i].x = a;
				e[i].y = b;
				e[i].value = c;
				Union(a,b);
			}
		}
		bool f = false;
		int root = find(1);
		for(i=2 ; i <= n ; ++i)
			if(find(i) != root){
				f = true; break;
			}
		if(f) printf("-1\n");
		else Kruskal();
	}
	return 0;
}