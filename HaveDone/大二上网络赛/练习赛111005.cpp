#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 1000000000;
const int M = 100000;
const int N = 50005;

struct A{
	int allo[4];
	int req[4];
	bool success;
}a[N];
int canu[4],n,m;
bool check(int i){
	for(int j=0 ; j < m ; ++j)
		if(a[i].req[j] > canu[j])
			return false;
	return true;
}

int main(){
	int i,j;
	while(scanf("%d%d",&n,&m) != EOF){
		memset(a,0,sizeof(a));
		for(i=0 ; i < m ; ++i)
			for(j=0 ; j < n ; ++j)
				scanf("%d",&a[j].allo[i]);
		for(i=0 ; i < m ; ++i)
			for(j=0 ; j < n ; ++j)
				scanf("%d",&a[j].req[i]);
		for(i=0 ; i < m ; ++i)
			scanf("%d",&canu[i]);

		while(1){
			for(i=n-1 ; i >= 0 ; --i){
				if(check(i)){
					for(j=0 ; j < m ; ++j)
						canu[j] += a[i].allo[j];
					a[i].success = true;
				}
			}
			for(i=0,j=0 ; i < n ; ++i)
				if(!a[i].success)
					a[j++] = a[i];
			if(j == 0){
				printf("Yes\n"); break;
			}
			else if(j == n){
				printf("No\n"); break;
			}
			n = j;
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 1000000000;
const int M = 100000;
const int N = 310;

int mat[N][N],sum[N][N];
bool check(int x,int y,int k){
	if(sum[x][y+k-1]-sum[x-1][y+k-1]-sum[x][y-1]+sum[x-1][y-1]!=k)
		return false;
	if(sum[x+k-1][y+k-1]-sum[x+k-2][y+k-1]-sum[x+k-1][y-1]+sum[x+k-2][y-1]!=k)
		return false;
	if(sum[x+k-1][y]-sum[x+k-1][y-1]-sum[x-1][y]+sum[x-1][y-1]!=k)
		return false;
	if(sum[x+k-1][y+k-1]-sum[x+k-1][y+k-2]-sum[x-1][y+k-1]+sum[x-1][y+k-2]!=k)
		return false;
	return true;
}
bool check2(int x,int y,int k){
	int one=sum[x+k-1][y+k-1]-sum[x-1][y+k-1]-sum[x+k-1][y-1]+sum[x-1][y-1];
	if(abs(k*k-2*one) <= 1) return true;
	return false;
}
int main(){
	int T,n,m,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1 ; i <= n ; ++i)
			for(j=1 ; j <= m ; ++j)
				scanf("%d",&mat[i][j]);

		memset(sum,0,sizeof(sum));
		for(i=1 ; i <= n ; ++i)
			for(j=1 ; j <= m ; ++j)
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i][j];

		int len=n<m?n:m,ans = 0;
		for(k=2 ; k <= len ; ++k)
			for(i=1 ; i <= n ; ++i)
				for(j=1 ; j <= m ; ++j)
					if(check(i,j,k) && check2(i+1,j+1,k-2))
						ans++;

		printf("%d\n",ans);
	}
	return 0;
}