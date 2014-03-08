#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int inf = 2000000000;
const int M = 55;
const int N = 25;

set<int> ans;
int a[5][5],v[4][2]={{1,0},{0,1},{-1,0},{0,-1}};;
void dfs(int u,int b,int step,int val){
	if(step == 0){
		ans.insert(val); return ;
	}
	for(int i=0 ; i < 4 ; ++i){
		int x = u+v[i][0];
		int y = b+v[i][1];
		if(x<0 || y<0 || x>4 || y>4) continue;
		dfs(x,y,step-1,val*10+a[x][y]);
	}
}
int main(){
	for(int i=0 ; i < 5 ; ++i)
		for(int j=0 ; j < 5 ; ++j)
			scanf("%d",&a[i][j]);
	for(int i=0 ; i < 5 ; ++i)
		for(int j=0 ; j < 5 ; ++j)
			dfs(i,j,5,a[i][j]);
	printf("%d\n",ans.size());
	return 0;
}