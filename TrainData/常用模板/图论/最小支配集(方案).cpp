//最小支配集
//返回最小支配集大小和一个方案,传入图的大小n和邻接阵mat
//mat[i][j]为布尔量
#ifdef WIN32
typedef __int64 i64;
#else
typedef long long i64;
#endif

#define MAXN 60
#define DP 20
struct node{
   int num;
   i64 rec;
}dp[1<<DP];

node search(int n,int mat[][MAXN],int* v,int now){
	int mask=-1,i,j;
	node ret,t;
	if (now<0)
		return dp[0];
	if (now<DP){
		for (mask=i=0;i<=now;i++)
			if (!v[i])
				mask|=1<<i;
		if (dp[mask].num||!mask)
			return dp[mask];
	}
	if (v[now])
		return search(n,mat,v,now-1);
	for (ret.num=MAXN,i=0;i<n;i++)
		if (mat[now][i]){
			for(j=0;j<n;j++)
				v[j]+=mat[i][j];
			t=search(n,mat,v,now-1);
			t.rec|=((i64)1)<<i;
			if (++t.num<ret.num)
				ret=t;
			for (j=0;j<n;j++)
				v[j]-=mat[i][j];
		}
	if (mask>0)
		dp[mask]=ret;
	return ret;
}

node dominate(int n,int mat[][MAXN]){
	int v[MAXN],i;
	for (i=0;i<n;mat[i][i]=1,v[i++]=0);
	for (dp[i=0].rec=0;i<(1<<DP);dp[i++].num=0);
	return search(n,mat,v,n-1);
}
