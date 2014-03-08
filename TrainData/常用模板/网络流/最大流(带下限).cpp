#define MAXN 256        //MAXNΪ��Ŀ���ڵ���+2 
#define inf 1000000000
typedef int elem_t;

//�����������,�ڽ�����ʽ
//�ط��������,flow����ÿ���ߵ�����
//��������ڵ���n,����mat,Դ��source,���sink
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
//�ж������Ƿ��н�
//matΪ������������,����Ϊ0
//bΪÿ���ڵ�Ĺ����ϵ sum(b) = 0ʱ������н�
//flow����ÿ���ߵ����� 
int feasibleflow(int n,elem_t mat[][MAXN], elem_t b[MAXN], elem_t flow[][MAXN]){
    int i;
    elem_t sum,all;
    for (i=0,sum=0,all=0;i<n;sum+=b[i++])
        if (b[i]>=0)
            mat[n][i]=b[i], mat[n+1][i]=mat[i][n+1]=mat[i][n]=0,all+=b[i];
        else
            mat[i][n+1]=-b[i], mat[n][i]=mat[i][n]=mat[n+1][i]=0; 
	mat[n][n+1]=mat[n+1][n]=0; 
	mat[n][n] = 0;
	mat[n+1][n+1] = 0;
    if (0!=sum)
        return 0;
    if (maxflow(n+2,mat,n,n+1,flow) == all)
        return 1;
    else
        return 0; 
}  
//�����������,�ڽ�����ʽ
//�ط��������,flow����ÿ���ߵ�����
//��������ڵ���n,��������low,��������up,Դ��source,���sink  
//�޽ⷵ��-1 
elem_t maxflow_lu(int n,elem_t low[][MAXN],elem_t up[][MAXN],int source,int sink,elem_t flow[][MAXN]){
    int i,j;
    elem_t mat[MAXN][MAXN],b[MAXN],s;
    elem_t tmp[MAXN][MAXN];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            mat[i][j]=up[i][j]-low[i][j];
    mat[sink][source]=inf;
    for (i=0;i<n;i++)
        for (j=0,b[i]=0;j<n;j++)
            b[i]+=low[j][i]-low[i][j];
    if (!feasibleflow(n,mat,b,flow))
        return -1;
 	mat[sink][source] = 0;
    for (i=0;i<n;++i)
        for(j=0;j<n;++j)
            tmp[i][j]=flow[i][j]+low[i][j], mat[i][j]-=flow[i][j];
    s=maxflow(n,mat,source,sink,flow);
    for(i=0;i<n;s+=tmp[i++][sink]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            flow[i][j] += tmp[i][j];
	
    return s; 
} 


