// RMQ Sparse Table.cpp : 定义控制台应用程序的入口点。
// RMQ RMQ(i,j)从i到j区间的最小值 M[i][k] 表示i开始（包含i）到i-1+1<<k 的最小值
// k=log(j-i+1); RMQ(i,j) = MMIN(M[i][k],M[j+1-(1<<k)][k])
// 即把（i，j）这个区间分成（i，i-1+1<<k)和（j+1-1<<k,j）

#include<iostream>
#include<cmath>
using namespace std;
#define MAXN 310
#define LOGMAXN int(log(1000000+1.0)/log(2.0))
int M1[MAXN][20]; // 20 = LOGMAXN
int A[MAXN];
int N,M;
int A2[MAXN][MAXN];
int M2[MAXN][MAXN][9][9]; //p=9= LOGMAXN_ROW q=9= LOGMAXN_column
// *********** 一维 *************//
inline int MMIN(int a,int b)
{
if(a > b) return b;
else return a;
}
void process1()
{
int i,j;
for(i = 0; i < N; i++)
   M1[i][0] = A[i];
for(j = 1; 1 << j <= N; j++)
{
   for(i = 0; i + (1 << (j-1)) -1 <N ; i++)
   {
    if( M1[i][j-1] < M1[i + (1 << (j - 1))][j-1])
     M1[i][j] = M1[i][j-1];
    else
     M1[i][j] = M1[i + (1 << (j - 1))][j-1];
   }
}
}
int query(int low,int high)
{
    int k=log(high-low+1.0)/log(2.0);
if(M1[low][k] < M1[high + 1 - (1 << k)][k])
   return M1[low][k];
else return M1[high + 1 - (1 << k)][k];
}
// ************** 一维结束 **************//


// ************** 二维 *****************//
void process2()
{
int i,j,p,q;
for(i = 0;i < N;i++)
   for(j = 0;j < M; j++)
    M2[i][j][0][0] = A2[i][j];
for(p = 0;1 << p <= N; p++)
{
   for(q=0; 1 << q <=M; q++)
   {
    if(p == 0 && q == 0) continue;
    for(i = 0; i + (1 << p) - 1 < N ; i++)
    {
     for(j = 0; j + (1 << q) -1 < M ; j++)
     {
      if(p == 0)
      {
       //if(M2[i][j][p][q-1] < M2[i][j + (1 << (q-1))][p][q-1])
       // M2[i][j][p][q] = M2[i][j][p][q-1];
       //else
       // M2[i][j][p][q] = M2[i][j + (1 << (q-1))][p][q-1];
       M2[i][j][p][q] = MMIN(M2[i][j][p][q-1],M2[i][j + (1 << (q-1))][p][q-1]);
      }
      else
      {
          //if(M2[i][j][p-1][q] < M2[i + (1 << (p-1)) ][j][p-1][q])
                        // M2[i][j][p][q] = M2[i][j][p-1][q];
            //else
         // M2[i][j][p][q] = M2[i + (1 << (p-1)) ][j][p-1][q];
       M2[i][j][p][q] = MMIN(M2[i][j][p-1][q],M2[i + (1 << (p-1))][j][p-1][q]);
      
      }
     }
    }
   }
}
}

int query(int low_x,int low_y,int high_x, int high_y)
{
int k_x = log(high_x - low_x + 1.0) / log(2.0);
int k_y = log(high_y - low_y + 1.0) / log(2.0);
    return MMIN( MMIN(    MMIN( M2[low_x][low_y][k_x][k_y] , M2[high_x - (1 << k_x) + 1][high_y - (1 << k_y) + 1][k_x][k_y]) ,    M2[low_x][high_y - (1 << k_y) +1][k_x][k_y]) , M2[high_x - (1 << k_x) +1][low_y][k_x][k_y] );
}
int main()
{
int t,i,j,x,y,x1,y1,q;
scanf("%d",&t);
while(t--)
{
   scanf("%d",&N);
   M = N;
   for(i=0;i<N;i++)
    for(j=0;j<M;j++)
     scanf("%d",&A2[i][j]);
   scanf("%d",&q);
   process2();
   for(i=0;i<q;i++)
   {
    scanf("%d %d %d %d",&x,&y,&x1,&y1);
    printf("%d\n",query(x-1,y-1,x1-1,y1-1));
   }
}
}
