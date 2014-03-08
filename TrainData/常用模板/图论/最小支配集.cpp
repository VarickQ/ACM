//最小支配集
//返回最小支配集大小,传入图的大小n和邻接阵mat
//mat[i][j]为布尔量
#define MAXN 60
#define DP 20
char dp[1<<DP];

int search(int n,int mat[][MAXN],int* v,int now){
	int mask=-1,i,j,ret=MAXN,t;
	if (now<0)
		return 0;
	if (now<DP){
		for (mask=i=0;i<=now;i++)
			if (!v[i])
				mask|=1<<i;
		if (dp[mask]||!mask)
			return dp[mask];
	}
	if (v[now])
		return search(n,mat,v,now-1);
	for (i=0;i<n;i++)
		if (mat[now][i]){
			for(j=0;j<n;j++)
				v[j]+=mat[i][j];
			if ((t=search(n,mat,v,now-1)+1)<ret)
				ret=t;
			for (j=0;j<n;j++)
				v[j]-=mat[i][j];
		}
	if (mask>0)
		dp[mask]=ret;
	return ret;
}

int dominate(int n,int mat[][MAXN]){
	int v[MAXN],i;
	for (i=0;i<n;mat[i][i]=1,v[i++]=0);
	for (i=0;i<(1<<DP);dp[i++]=0);
	return search(n,mat,v,n-1);
}