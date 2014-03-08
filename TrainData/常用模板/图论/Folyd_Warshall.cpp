/*********************************************\
*                                             *
*         每对节点间最短路径                  *
*         Floyd-Warshall算法                  *
*                                             *
*                   copyright starfish        *
*                           2000/10/24        *
*                                             *
\*********************************************/


#include <cstdio>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <cmath>
#include <ctime>
#include <bitset>
#include <stdlib.h>
#include <stddef.h>
#include <float.h>
#include "Graph.h"

#define input "Floyd_Warshall.in"      //Input file name
#define output "Floyd_Warshall.out"    //Output file name

FILE *fin,*fout;
int probN,n=0;
Graph G,D,P;

int read_case()
{
   int i,j,k,m,tmp;
   if (feof(fin)) return 0;
   fscanf(fin,"%d %d",&n,&m);
   if (n==0) return 0;
   probN++;
   for (i=0;i<n;i++)
      for (j=0;j<n;j++)
         G[i][j]=infinity;
   for (k=0;k<m;k++)
   { fscanf(fin,"%d %d %d",&i,&j,&tmp);
    G[i-1][j-1]=tmp;
    }
   return 1;
}

void solve_case()
{
    int i,j;
    fprintf(fout,"Case %d\n",probN);
    Floyd_Washall(G,n,D,P);
    fprintf(fout,"Min distance:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++) fprintf(fout,"%d ",D[i][j]);
        fprintf(fout,"\n");
        }
    fprintf(fout,"Path:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++) fprintf(fout,"%d ",P[i][j]);
        fprintf(fout,"\n");
    }
    fprintf(fout,"\n");
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
