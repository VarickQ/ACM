#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 1000000000
const int N = 500005;

int a[N],Max[N][20],Min[N][20],n,q;
void init_rmq(){
	int i,j;
	for(i=0 ; i < n ; i++)
		Max[i][0] = Min[i][0] = a[i];
	for(j=1 ; (1<<j) <= n ; j++)
		for(i=0 ; i+(1<<(j-1)) < n ; i++)
		{
			Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
			Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
		}
}
int rmq_max(int i,int j){
	int k = log(j-i+1.0)/log(2.0);
	return max(Max[i][k],Max[j-(1<<k)+1][k]);
}
int rmq_min(int i,int j){
	int k = log(j-i+1.0)/log(2.0);
	return min(Min[i][k],Min[j-(1<<k)+1][k]);
}
int main()
{
	int i;
	while(scanf("%d%d",&n,&q)==2)
	{
		for(i=0 ; i < n ; i++)
			scanf("%d",&a[i]);
		init_rmq();
		int x,y,mx,mm;
		for(i=0 ; i < q ; i++){
			scanf("%d%d",&x,&y);
			x--; y--;
			mx = rmq_max(x,y);
			mm = rmq_min(x,y);
			printf("%d\n",mx-mm);
		}
	}
	return 0;
}
