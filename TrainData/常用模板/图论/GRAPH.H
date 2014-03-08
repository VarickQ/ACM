/*********************************************\
*                                             *
*              图论算法                       *
*                                             *
*                   copyright starfish        *
*                           2000/10/24        *
*                                             *
\*********************************************/

#define infinity 1000000							// a big int
#define max_vertexes 5								// the max count of vertexes

typedef int Graph[max_vertexes][max_vertexes];		//use adjacent matrix to represent graph

/*********************************************
         求最小生成树的Prim算法
         用邻接矩阵表示图，复杂度为O(n^2)
         参数G表示图的邻接矩阵，
         vcount表示图的顶点个数，
         father用来记录每个节点的父节点
**********************************************/
void prim(Graph G,int vcount,int father[])
{
	int i,j,k;
	int lowcost[max_vertexes],closeset[max_vertexes],used[max_vertexes];
	for(i=0;i<vcount;i++)
	{
		lowcost[i]=G[0][i];
		closeset[i]=0;    //notice: here vertex 1 is G[0]
		used[i]=0;        //mark all vertexes have not been used
		father[i]=-1;      // that means no father
	}
	used[0]=1;              // mark vertex 1 has been used
	for (i=1;i<vcount;i++)
	{
		j=0;
		while (used[j]) j++;
		for (k=0;k<vcount;k++)
		if ((!used[k])&&(lowcost[k]<lowcost[j])) j=k;  //find the next tree edge
		father[j]=closeset[j];   //record the tree edge using father array
		used[j]=1;               //mark vertex j+1 has been used
		for(k=0;k<vcount;k++)
			if (!used[k]&&(G[j][k]<lowcost[k]))  //modify the lowcost
			{
				lowcost[k]=G[j][k];
				closeset[k]=j;  
			}
	}
}

/*===============================================
                单源最短路径

                Dijkstra 算法

            适用条件：所有边的权非负

            !!注意：
            1.输入的图的权必须非负
            2.顶点标号从0开始
            3.当i,j不相邻时G[i,j]=infinity

================================================*/
int Dijkstra(Graph G,int n,int s,int t, int path[])
{
	int i,j,w,minc,d[max_vertexes],mark[max_vertexes];
	for(i=0;i<n;i++) 
		mark[i] = 0 ;
	for(i=0;i<n;i++)
	{   
		d[i]=G[s][i];
		path[i]=s;	
	}
	mark[s]=1;path[s]=0;d[s]=0;
	for(i=1;i<n;i++)
	{   
		minc=infinity;
		w=0;
		for(j=0;j<n;j++)
		if((mark[j]==0)&&(minc>=d[j])) {minc=d[j];w=j;}
		mark[w]=1;
		for(j=0;j<n;j++)
		if((mark[j]==0)&&(G[w][j]!=infinity)&&(d[j]>d[w]+G[w][j]))
		{   
			d[j]=d[w]+G[w][j];
			path[j]=w;     
		}
	}
	return d[t];
}

/*======================================================

      单源最短路径

   Bellman-Ford 算法

 适用条件：所有情况，边权可以为负
 G为图，n为图的节点数目,s,t分别为源点和终点,
 success用来标示该函数是否成功，
 如果存在一个从源点可达的权为负的回路则success=false;
 返回值为s,t之间的最短路径长度；


            !!注意：
            1.顶点标号从0开始
            2.当i,j不相邻时G[i,j]=infinity

=============================================================*/

int Bellman_Ford(Graph G,int n,int s,int t,int path[],int success)
{
   int i,j,k,d[max_vertexes];
   for (i=0;i<n;i++) {d[i]=infinity;path[i]=0;}
   d[s]=0;
   for (k=1;k<n;k++)
    for (i=0;i<n;i++)
     for (j=0;j<n;j++)
       if (d[j]>d[i]+G[i][j]) {d[j]=d[i]+G[i][j];path[j]=i;}
   success=0;
   for (i=0;i<n;i++)
    for (j=0;j<n;j++)
     if (d[j]>d[i]+G[i][j]) return 0;
   success=1;
   return d[t];
 }

/*==========================================

              每对节点间最短路径
                Floyd-Warshall 算法

    D[i,j]表示从i到j的最短距离；
    P[i,j]表示从i到j的最短路径上j 的父节点

===========================================*/

void Floyd_Washall(Graph G,int n,Graph D,Graph P)
{
    int i,j,k;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            {   D[i][j]=G[i][j];
                P[i][j]=i;       }
    for (i=0;i<n;i++) {   D[i][i]=0;P[i][i]=0; }
    for (k=0;k<n;k++)
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                if (D[i][j]>D[i][k]+D[k][j])
                {   D[i][j]=D[i][k]+D[k][j];
                    P[i][j]=P[k][j];
                    }
}
