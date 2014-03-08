/*
	最大m子段和问题：
	b(i,j) = max{b(i,j-1)+a[j],max{ b(i-1,t), i-1<=t<j} + a[j] }
	DP 
*/
#include <iostream>
using namespace std;

int MaxSum(int m, int n,int*a)
{
	if(n<m || m<1) return 0;
	int i,j,k;	
	int **table = new int* [m+1];
	for(i=0; i<= m; i++)
	{
		table[i] = new int[n+1];
	}
	for(i=0; i<=m; i++) table[i][0] = 0;
	for(j=1; j<=n; j++) table[0][j] = 0;
	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n-m+i; j++)
		{
			if(j>i)
			{
				table[i][j] = table[i][j-1]	+ a[j];
				for(k=i-1; k<j; k++)
				{
					if(table[i][j] < table[i-1][k]+a[j])
						table[i][j] = table[i-1][k] + a[j];
				}
			}
			else
				table[i][j] = table[i-1][j-1] + a[j];
		}
	}
	int sum = 0;
	for(j=m; j<=n; j++)
		if(sum < table[m][j]) sum = table[m][j];
	return sum;
}

// 算法改进 ;

int MaxSum(int m, int n,int*a)
{
	if(n<m||m<1)return 0;
	int *b = new int[n+1];
	int *c = new int[n+1];
	int i,j;
	b[0] = 0;
	c[1] = 0;
	for(i=1; i<=m; i++)
	{
		b[i] = b[i-1] + a[i];
		c[i-1] = b[i];
		int max = b[i];
		for(j=i+1; j<=i+n-m; j++)
		{
			b[j] = b[j-1] > c[j-1] ? b[j-1] + a[j] : c[j-1] + a[j];
			c[j-1] = max;
			if(max < b[j])
				max = b[j];
		}
		c[i+n-m] = max;
	}
	int sum = INT_MIN;
	for(j=m; j<=n; j++)
	{
		if(sum < b[j])
			sum = b[j];
	}
	return sum;
}