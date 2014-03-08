int min_cost_max_flow(int n,int mat[][MAXN],int cost[][MAXN],
                      int source,int sink,int flow[][MAXN],int& netcost){
    int pre[MAXN],min[MAXN],d[MAXN],i,j,t,tag;
    if (source==sink) return inf;
    for (i=0;i<n;i++)
        for (j=0;j<n;flow[i][j++]=0);
    for (netcost=0;;){
        for (i=0;i<n;i++)
            pre[i]=0,min[i]=inf;
        for (pre[source]=source+1,min[source]=0,d[source]=inf,tag=1;tag;)
            for (tag=t=0;t<n;t++)
                if (d[t]) for (i=0;i<n;i++)
                     if (j=mat[t][i]-flow[t][i]&&min[t]+cost[t][i]<min[i])
                tag=1,min[i]=min[t]+cost[t][i],pre[i]=t+1,d[i]=d[t]<j?d[t]:j;
                     else if (j=flow[i][t]&&min[t]-cost[i][t]<min[i])
                tag=1,min[i]=min[t]-cost[i][t],pre[i]=-t-1,d[i]=d[t]<j?d[t]:j;
        if (!pre[sink]) break;
        for (netcost+=min[sink]*d[i=sink];i!=source;)
            if (pre[i]>0)
                flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
            else
                flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
    }
    for (j=i=0;i<n;j+=flow[source][i++]);
    return j;
}

