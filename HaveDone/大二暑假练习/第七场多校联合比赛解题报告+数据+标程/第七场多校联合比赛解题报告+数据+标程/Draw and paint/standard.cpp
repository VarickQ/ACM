#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
#define M 40

const int MOD=1000000007;

int f[M+5][M+5][5][5][5][5][2];
int cs[5][5][5][5];
int n,m;

void init(void);
void fz(int i,int j,int a,int b,int c,int d,int st);

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int ca;
	int i,j,k,a,b,c,d,e;
	init();
	for (i=1;i<=M;i++)
		for (j=1;j<=M;j++)
		{
			for (a=0;a<5;a++)
				for (b=0;b<5;b++)
					for (c=0;c<5;c++)
						for (d=0;d<5;d++)
						{
							if (f[i][j][a][b][c][d][0]==-1)
							{
								f[i][j][a][b][c][d][0]=cs[a][b][c][d];
								//====================================
								for (k=1;k<i;k++)
								{
									for (e=1;e<5;e++)
									{
										if (e!=a && e!=b && e!=d)
										{
											f[i][j][a][b][c][d][0]+=f[i-k][j][e][b][c][d][1];
											f[i][j][a][b][c][d][0]%=MOD;
										}
										if (e!=b && e!=c && e!=d)
										{
											f[i][j][a][b][c][d][0]+=(f[k][j][a][b][e][d][1]+MOD-cs[a][b][e][d])%MOD;
											f[i][j][a][b][c][d][0]%=MOD;
										}
									}
								}
								fz(i,j,a,b,c,d,0);
							}
							if (f[i][j][a][b][c][d][1]==-1)
							{
								f[i][j][a][b][c][d][1]=cs[a][b][c][d];
								//====================================
								for (k=1;k<j;k++)
								{
									for (e=1;e<5;e++)
									{
										if (e!=a && e!=b && e!=c)
										{
											f[i][j][a][b][c][d][1]+=f[i][j-k][a][e][c][d][0];
											f[i][j][a][b][c][d][1]%=MOD;
										}
										if (e!=a && e!=c && e!=d)
										{
											f[i][j][a][b][c][d][1]+=(f[i][k][a][b][c][e][0]+MOD-cs[a][b][c][e])%MOD;
											f[i][j][a][b][c][d][1]%=MOD;
										}
									}
								}
								//====================================
								fz(i,j,a,b,c,d,1);
							}
						}
		}
	scanf("%d",&ca);
	while (ca--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",f[n][m][0][0][0][0][0]%MOD);
	}
	return 0;
}

void init(void)
{
	int a,b,c,d,e;
	memset(f,-1,sizeof(f));
	memset(cs,0,sizeof(cs));
	for (a=0;a<5;a++)
		for (b=0;b<5;b++)
			for (c=0;c<5;c++)
				for (d=0;d<5;d++)
				{
					for (e=1;e<5;e++)
						if (e!=a && e!=b && e!=c && e!=d)
							cs[a][b][c][d]++;
				}
}

void fz(int i,int j,int a,int b,int c,int d,int st)
{
	f[i][j][c][b][a][d][st]=f[i][j][a][b][c][d][st];
	f[i][j][a][d][c][b][st]=f[i][j][a][b][c][d][st];
	f[i][j][c][d][a][b][st]=f[i][j][a][b][c][d][st];
	//======================================
	f[j][i][b][c][d][a][1-st]=f[i][j][a][b][c][d][st];
	f[j][i][d][c][b][a][1-st]=f[i][j][a][b][c][d][st];
	f[j][i][d][a][b][c][1-st]=f[i][j][a][b][c][d][st];
	f[j][i][b][a][d][c][1-st]=f[i][j][a][b][c][d][st];
}
