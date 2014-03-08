//单源最短路径,bellman_ford算法,正向表形式,复杂度O(n*m)
//求出源s到所有点的最短路经,传入图的大小n和正向表list,buf
//返回到各点最短距离min[]和路径pre[],pre[i]记录s到i路径上i的父结点,pre[s]=-1
//可更改路权类型,路权可为负,若图包含负环则求解失败,返回0
//优化:先删去负边使用dijkstra求出上界,加速迭代过程
#define MAXN 200
#define inf 1000000000
typedef int elem_t;
struct edge_t{
	int to;
	elem_t len;
};

int bellman_ford(int n,int* list,edge_t* buf,int s,elem_t* min,int* pre){
	int v[MAXN],i,j,k,tag,t;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[s]=0,j=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,t=list[k];t<list[k+1];t++)
			if (!v[buf[t].to]&&buf[t].len>=0&&min[k]+buf[t].len<min[buf[t].to])
				min[buf[t].to]=min[k]+buf[t].len,pre[buf[t].to]=k;
	}
	for (tag=1,j=0;tag&&j<=n;j++)
		for (tag=k=0;k<n;k++)
			for (t=list[k];t<list[k+1];t++)
				if (min[k]+buf[t].len<min[buf[t].to])
					min[buf[t].to]=min[k]+buf[t].len,pre[buf[t].to]=k,tag=1;
	return j<=n;
}
