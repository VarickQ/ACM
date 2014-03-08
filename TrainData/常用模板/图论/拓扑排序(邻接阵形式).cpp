//拓扑排序,邻接阵形式,复杂度O(n^2)
//如果无法完成排序,返回0,否则返回1,ret返回有序点列
//传入图的大小n和邻接阵mat,不相邻点边权0
#define MAXN 100

int toposort(int n,int mat[][MAXN],int* ret){
	int d[MAXN],i,j,k;
	for (i=0;i<n;i++)
		for (d[i]=j=0;j<n;d[i]+=mat[j++][i]);
	for (k=0;k<n;ret[k++]=i){
		for (i=0;d[i]&&i<n;i++);
		if (i==n)
			return 0;
		for (d[i]=-1,j=0;j<n;j++)
			d[j]-=mat[i][j];
	}
	return 1;
}
