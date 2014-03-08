#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 1000000000;
const int M = 110;
const int N = 55;

int n,mat[N][N],map[M][M];
bool vis[N][N];
int v[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct Node{
	int x,y,e;
}cu;
void bfs(int x,int y){
	int i,j,num=n-1;
	queue<Node> qu;
	memset(vis,0,sizeof(vis));
	vis[x][y] = true;
	cu.x=x; cu.y=y; cu.e=0;
	qu.push(cu);
	while(!qu.empty()){
		Node f = qu.front(); qu.pop();
		Node ff;
		for(i=0 ; i < 4 ; ++i){
			ff.x = f.x+v[i][0];
			ff.y = f.y+v[i][1];
			ff.e = f.e+1;
			if(mat[ff.x][ff.y] != -1 && !vis[ff.x][ff.y]){
				vis[ff.x][ff.y] = true;
				if(mat[ff.x][ff.y] > 0){
					map[mat[x][y]][mat[ff.x][ff.y]]=ff.e;
					num--;
					if(num == 0) return ;
				}
				qu.push(ff);
			}
		}
	}
}
void Prim(){
	int i,j,now,min_node,Min,sum=0;
	int dis[M];
	for(i=1 ; i <= n ; ++i)
		dis[i] = inf;
	now = 1;
	for(i=1 ; i < n ; ++i){
		dis[now] = -1;
		Min = inf;
		for(j=1 ; j <= n ; ++j){
			if(j!=now && dis[j] >= 0){
				dis[j] = min(dis[j],map[now][j]);
				if(dis[j] < Min){
					Min = dis[j];
					min_node = j;
				}
			}
		}
		now = min_node;
		sum += Min;
	}
	printf("%d\n",sum);
}
int main(){
	int T,r,c;
	char ch,str[N];
	scanf("%d",&T);
	while(T--){
		memset(map,0,sizeof(map));
		memset(mat,0,sizeof(mat));
		scanf("%d%d",&c,&r);
		gets(str);
		n = 0;
		for(int i=1 ; i <= r ; ++i){
			for(int j=1 ; j <= c ; ++j){
				scanf("%c",&ch);
				if(ch=='#') mat[i][j] = -1;
				else if(ch==' ')mat[i][j] = 0;
				else mat[i][j] = ++n;
			}
			getchar();
		}
		for(int i=1 ; i <= r ; ++i)
			for(int j=1 ; j <= c ; ++j)
				if(mat[i][j] > 0)
					bfs(i,j);
		Prim();
	}
	return 0;
}