#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,m;
int mat[505][505],match[505];
bool vis[505];
bool find(int i){
	for(int j=1 ; j <= n ; j++)
		if(mat[i][j] && !vis[j])
		{
			vis[j] = true;
			if(match[j]==0 || find(match[j]))
			{
				match[j]=i;
				return true;
			}
		}
	return false;
}
int main()
{
	int a,b;
	while(scanf("%d%d",&n,&m) == 2)
	{
		if(n==0 && m==0) break;
		memset(mat,0,sizeof(mat));
		for(int i=0 ; i < m ; i++){
			scanf("%d%d",&a,&b);
			mat[a][b] = 1;
		}
		for(int k=1 ; k <= n ; k++)
			for(int i=1 ; i <= n ; i++)
				for(int j=1 ; j <= n ; j++)
					if(mat[i][k]==1 && mat[k][j]==1)
						mat[i][j] = 1;
		int ans=0;
		memset(match,0,sizeof(match));
		for(int i=1 ; i <= n ; i++)
		{
			memset(vis,false,sizeof(vis));
			if(find(i)) ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}