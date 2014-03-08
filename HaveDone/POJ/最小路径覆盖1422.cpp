#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define N 130

bool vis[N];
int match[N],mat[N][N];
int n,m;
bool find(int i){
	for(int j=1 ; j <= n ; j++)
		if(mat[i][j] && !vis[j])
		{
			vis[j] = true;
			if(match[j]==0 || find(match[j]))
			{
				match[j] = i;
				return true;
			}
		}
	return false;
}
int main()
{
	int T,i,j,k,x,y;
	scanf("%d",&T);
	while(T--)
	{
		memset(mat,0,sizeof(mat));
		scanf("%d%d",&n,&m);
		for(i=0 ; i < m ; i++){
			scanf("%d%d",&x,&y);
			mat[x][y] = 1;
		}
		
		int ans=0;
		memset(match,0,sizeof(match));
		for(i=1 ; i <= n ; i++)
		{
			memset(vis,false,sizeof(vis));
			if(find(i)) ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}