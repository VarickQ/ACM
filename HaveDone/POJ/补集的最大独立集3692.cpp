#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define N 205

bool vis[N];
int match[N],mat[N][N];
int g,b;
bool find(int i){
	for(int j=1 ; j <= b ; j++)
		if(mat[i][j] && !vis[j]){
			vis[j] = true;
			if(match[j]==0 || find(match[j])){
				match[j] = i;
				return true;
			}
		}
	return false;
}
int main()
{
	int i,j,m,x,y,cs=1;
	while(scanf("%d%d%d",&g,&b,&m) != EOF)
	{
		if(g==0&&b==0&&m==0) break;
		memset(mat,1,sizeof(mat));
		for(i=1 ; i <= m ; i++){
			scanf("%d%d",&x,&y);
			mat[x][y] = 0;
		}

		int ans=0;
		memset(match,0,sizeof(match));
		for(i=1 ; i <= g ; i++)
		{
			memset(vis,false,sizeof(vis));
			if(find(i)) ans++;
		}
		printf("Case %d: %d\n",cs++,b+g-ans);
	}
	return 0;
}