/*********************************************\
*                                             *
*         单源最短路径 Dijkstra 算法          *
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


#define input "Dijkstra.in"      //Input file name
#define output "Dijkstra.out"    //Output file name

FILE *fin,*fout;
int probN,n,s,t=0;
Graph G;

int read_case()
{
   int i,j,k,m,tmp;
   if (feof(fin)) return 0;
   fscanf(fin,"%d %d",&n,&m);
   if (n==0) return 0;
   probN++;
   fscanf(fin,"%d %d",&s,&t);
   s--;t--;
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
   int i;
   int path[max_vertexes];

    fprintf(fout,"Case %d:\n",probN);
    fprintf(fout,"Shortest way cost %d\n",Dijkstra(G,n,s,t,path));
    fprintf(fout,"the shortest way is :");
    i=t;
    while (i!=s)
    {
    fprintf(fout,"%d<--",i+1);
    i=path[i];
    }
    fprintf(fout,"%d\n",s+1);
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
	File Info:
	
	Dijkstra.in :
	5 7
	1 5
	1 2 10
	1 5 100
	1 4 30
	2 3 50
	3 5 10
	4 3 20
	4 5 60

    Case 1:
	Shortest way cost 60
	the shortest way is :5<--3<--4<--1
*/