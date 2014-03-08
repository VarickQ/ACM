#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-10
#define zero(x) (((x)>0?(x):-(x))<eps)
const int M = 10000;
const int N = 302;

struct node{
	int c,d,e;
}cu;
int mat[N][N];
struct cmp{//从小到大
	bool operator()(const node &x,const node &y){
		return x.e > y.e;
	}
};
priority_queue<node,vector<node>,cmp> q;
int m,n;
int v[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int bfs(int x,int y){
	while(!q.empty()) q.pop();
	cu.c = x; cu.d = y; cu.e = 0;
	q.push(cu);
	while(!q.empty()){
		node ff=q.top(); q.pop();
		node f;
		for(int i=0 ; i < 4 ; ++i){
			f.c = ff.c+v[i][0];
			f.d = ff.d+v[i][1];
			f.e = ff.e+1;
			if(f.c>=0 && f.c<m && f.d>=0 && f.d<n){
				if(mat[f.c][f.d] == 3)
					return f.e;
				if(mat[f.c][f.d] == 2){
					mat[f.c][f.d] = 1;
					f.e ++;
					q.push(f);
				}
				if(mat[f.c][f.d] == 0){
					mat[f.c][f.d] = 1;
					q.push(f);
				}
			}
		}
	}
	return -1;
}
int main(){
	char str[N];
	int x,y;
	while(scanf("%d%d",&m,&n) && (m+n)){
		memset(mat,0,sizeof(mat));
		for(int i=0 ; i < m ; ++i){
			scanf("%s",str);
			for(int j=0 ; str[j] ; ++j){
				if(str[j] == 'Y')x=i,y=j;
				else if(str[j] == 'B')mat[i][j] = 2;
				else if(str[j] == 'T')mat[i][j] = 3;
				else if(str[j]=='S'||str[j]=='R')
					mat[i][j] = 1;
			}
		}
		mat[x][y] = 1;
		printf("%d\n",bfs(x,y));
	}
	return 0;
}