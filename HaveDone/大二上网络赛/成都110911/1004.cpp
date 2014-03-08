#include <iostream>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define inf 10000000
#define N 110

int mat[N][N];
bool mark[N][N];
int main()
{
	int T,i,j,k,n,cs=0,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans = 0;
		for(i=0 ; i < n ; ++i)
			for(j=0 ; j < n ; ++j){
				scanf("%d",&mat[i][j]);
				if(i!=j) ans++;
			}

		bool f = false;
		for(k=0 ; k < n ; ++k)
			for(i=0 ; i < n ; ++i)
				for(j=0 ; j < n ; ++j)
					if(mat[i][j] > mat[i][k]+mat[k][j]){
						f = true; break;
					}
		printf("Case %d: ",++cs);
		if(f){
			printf("impossible\n");
			continue;
		}
		memset(mark,0,sizeof(mark));
		for(k=0 ; k < n ; ++k)
			for(i=0 ; i < n ; ++i)
				for(j=0 ; j < n ; ++j){
					if(i==k || k==j) continue;
					if(mat[i][j]==mat[i][k]+mat[k][j] && !mark[i][j]){
						mark[i][j] = true;
						ans--;
					}
				}
		printf("%d\n",ans);
	}
    return 0;
}