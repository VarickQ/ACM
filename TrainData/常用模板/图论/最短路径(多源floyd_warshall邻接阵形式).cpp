//多源最短路径,floyd_warshall算法,复杂度O(n^3)
//求出所有点对之间的最短路经,传入图的大小和邻接阵
//返回各点间最短距离min[]和路径pre[],pre[i][j]记录i到j最短路径上j的父结点
//可更改路权类型,路权必须非负!
#define MAXN 200
#define inf 1000000000
typedef int elem_t;

void floyd_warshall(int n,elem_t mat[][MAXN],elem_t min[][MAXN],int pre[][MAXN]){
	int i,j,k;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			min[i][j]=mat[i][j],pre[i][j]=(i==j)?-1:i;
	for (k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (min[i][k]+min[k][j]<min[i][j])
					min[i][j]=min[i][k]+min[k][j],pre[i][j]=pre[k][j];
}