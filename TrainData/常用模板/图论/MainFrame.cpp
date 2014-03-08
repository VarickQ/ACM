/*********************************************\
*                                             *
*                                             *
*                                             *
*                                             *
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


#define input ".in"      //Input file name
#define output ".out"    //Output file name

FILE *fin,*fout;
int probN=0;

int read_case()
{
   int i,j,k;
   if (feof(fin)) return 0;
   
   return 1;
}



void solve_case()
{
   int i,j,k;



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