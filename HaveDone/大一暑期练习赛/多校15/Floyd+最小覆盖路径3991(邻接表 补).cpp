#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

const int N = 2010;
const __int64 inf = (1LL)<<60;
#define ll __int64

struct C{
	int city;
	ll tim;
}a[N];
struct A{
	int v,next;
}e[2000000];
int heade[N],edge,match[N];
bool vis[N];
int n,m,q;
ll mat[105][105];

void add(int u,int v){
	e[edge].v = v;
	e[edge].next = heade[u];
	heade[u] = edge++;
}
bool find(int u){
	for(int j=heade[u] ; j!=-1 ; j=e[j].next){
		int v = e[j].v;
		if(!vis[v]){
			vis[v] = true;
			if(match[v]==-1 || find(match[v])){
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}
int main(){
	int T,i,j,k,cs=0;
	int u,v;
	ll c;
	scanf("%d",&T);
	while(T--)
	{
		memset(heade,-1,sizeof(heade));
		edge = 0;
		scanf("%d%d%d",&n,&m,&q);
		for(i=0 ; i < n ; ++i){
			for(j=0 ; j < n ; ++j)
				mat[i][j] = inf;
			mat[i][i] = 0;
		}
		for(i=0 ; i < m ; ++i){
			scanf("%d%d%I64d",&u,&v,&c);
			if(mat[u][v] > c)
				mat[u][v] = mat[v][u] = c;
		}
		for(k=0 ; k < n ; ++k)
			for(i=0 ; i < n ; ++i)
				for(j=0 ; j < n ; ++j)
					if(mat[i][k]+mat[k][j] < mat[i][j])
						mat[i][j] = mat[i][k]+mat[k][j];
		for(i=0 ; i < q ; ++i)
			scanf("%d%I64d",&a[i].city,&a[i].tim);
		for(i=0 ; i < q ; ++i)
			for(j=0 ; j < q ; ++j)
				if(i!=j && mat[a[i].city][a[j].city] <= a[j].tim-a[i].tim)
					add(i,j);
		memset(match,-1,sizeof(match));
		int ans = 0;
		for(i=0 ; i < q ; ++i){
			memset(vis,false,sizeof(vis));
			if(find(i)) ans++;
		}
		printf("Case %d: %d\n",++cs,q-ans-1);
	}
	return 0;
}