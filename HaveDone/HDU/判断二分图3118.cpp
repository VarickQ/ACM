#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 310;

struct A{
	int u,v;
}e[N];
int n,m;
int heade[N],k;
int c[17],ans;
void add(int u,int v){
	e[k].u = u;
	e[k].v = v;
	k++;
}
void dfs(int star,int s){
	c[star] = s;
	if(star == n){//全部染色
		int cnt = 0;
		for(int i=0 ; i < k ; ++i)
			if(c[e[i].u] == c[e[i].v])
				cnt++;
		if(ans > cnt) ans = cnt;
	}
	else if(star < n){
		if(c[star+1]==0 || c[star+1]==2)
			dfs(star+1,1);//染色1
		if(c[star+1]==0 || c[star+1]==1)
			dfs(star+1,2);//染色2
	}
}
int main(){
	int T,u,v;
	scanf("%d",&T);
	while(T--){
		memset(heade,-1,sizeof(heade));
		memset(c,0,sizeof(c));
		scanf("%d%d",&n,&m);
		ans = inf;
		k = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d",&u,&v);
			u++; v++;
			add(u,v);
		}
		if(n == 0){
			printf("0\n");
		} else {
			dfs(1,1);
			dfs(1,2);
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
6
3 3
0 1
1 2
2 0

4 5
0 1
1 2
2 0
0 3
1 3

5 6
0 1
1 2
2 0
0 3
1 3
3 4
*/