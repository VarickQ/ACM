//求网络最大流,邻接阵形式
//回返最大流量,flow返回每条边的流量
//传入网络节点数n,容量mat,源点source,汇点sink
#define MAXN 100
#define inf 1000000000
typedef double elem_t;

elem_t maxflow(int n,elem_t mat[][MAXN],int source,int sink,elem_t flow[][MAXN]){
	int pre[MAXN],que[MAXN],p,q,t,i,j;
	elem_t d[MAXN],s;
	if (source==sink)
		return inf;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			flow[i][j]=0;
	for (pre[sink]=1;pre[sink];){
		for (i=0;i<n;pre[i++]=0);
		pre[t=source]=source+1,d[t]=inf;
		for (p=0,q=1;p<q&&!pre[sink];t=que[++p])
			for (i=0;i<n;i++)
				if (!pre[i]&&mat[t][i]&&(s=mat[t][i]-flow[t][i])>0)
					pre[que[q++]=i]=t+1,d[i]=d[t]<s?d[t]:s;
				else if (!pre[i]&&mat[i][t]&&(s=flow[i][t])>0)
					pre[que[q++]=i]=-t-1,d[i]=d[t]<s?d[t]:s;
		for (i=sink;pre[i]&&i!=source;)
			if (pre[i]>0)
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}
	for (s=i=0;i<n;i++)
		s+=flow[source][i];
	return s;
}
