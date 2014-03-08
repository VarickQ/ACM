/**********************************************
*                                             *
*         求最小生成树的Prim算法             *
*                                             *
*         用邻接矩阵表示图，复杂度为O(n^2)    *
*                                             *
*                        copyright starfish   *
*                            2000/10/24       *
*                                             *
***********************************************/

#include <stdio.h>
#include <iostream.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define input "Prim.in"				//Input file name
#define output "Prim.out"			//Output file name

#define infinity 1000000			// a big int
#define max_N 100					// the max count of vertexes

typedef int Graph[max_N][max_N];   //use adjacent matrix to represent graph

FILE *fin,*fout;
int probN=0,n;
Graph G;

int read_case()
{
   int i,j,k,m,w;
   fscanf(fin,"%d %d",&n,&m);
   if (n==0) return 0;
   probN++;
   for (i=0;i<n;i++)
      for (j=0;j<n;j++)
         G[i][j]=infinity;			//initialize the graph
   for (k=0;k<m;k++)
      {
      fscanf(fin,"%d %d %d\n",&i,&j,&w);
      G[i-1][j-1]=G[j-1][i-1]=w;	//the vertexes in the input file are labed from 1 to n
      }
   return 1;
}


void prim(Graph G,int vcount,int father[])
{
   int i,j,k;
   int lowcost[max_N],closeset[max_N],used[max_N];

   for (i=0;i<vcount;i++)
      {
         lowcost[i]=G[0][i];
         closeset[i]=0;				//notice: here vertex 1 is G[0]
         used[i]=0;					//mark all vertexes have not been used
         father[i]=-1;				// that means no father
         }
   used[0]=1;						// mark vertex 1 has been used
   for (i=1;i<vcount;i++)
      {
         j=0;
         while (used[j]) j++;
         for (k=0;k<vcount;k++)
            if ((!used[k])&&(lowcost[k]<lowcost[j])) j=k;  //find the next tree edge
         father[j]=closeset[j];		//record the tree edge using father array
         used[j]=1;					//mark vertex j+1 has been used
         for (k=0;k<vcount;k++)
            if (!used[k]&&(G[j][k]<lowcost[k]))				//modify the lowcost
               {
                  lowcost[k]=G[j][k];
                  closeset[k]=j;
                  }
         }

   }


void solve_case()
{
   int i,j,k;
   int father[max_N];

   fprintf(fout,"Case %d\n",probN);
   prim(G,n,father);
   for (i=0;i<n;i++)
         fprintf(fout,"(%d,%d)\n",father[i]+1,i+1);
}


int main()
{
   assert(fin=fopen(input,"r"));
   assert(fout=fopen(output,"w"));   //if there is no output file, comment this line
   while (read_case()) solve_case();
   fclose(fin);
   fclose(fout);                    //if there is no output file, comment this line
	return 0;
}

/*
File Info :

  Prim.in :
	6 10
	1 2 6
	1 4 5
	1 3 1
	2 3 5
	3 4 5
	2 5 3
	3 5 6
	5 6 6
	3 6 4
	4 6 2
	0 0
  Prim.out :
	Case 1
	(0,1)
	(3,2)
	(1,3)
	(6,4)
	(2,5)
	(3,6)
*/