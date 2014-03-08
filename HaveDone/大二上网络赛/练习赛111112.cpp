#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 2000000000;
const int M = 100000;
const int N = 61;

int main(){
	int n,s;
	while(scanf("%d%d",&n,&s) == 2){
		printf("%d\n",s/(n+1));
	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

double a[100100];

int main()
{
	int i,j,n;
	while(scanf("%d",&n) == 1)
	{
		for(i = 0;i < n;++i)
			scanf("%lf",&a[i]);
		int ans = 0;
		for(i = 0;i < n;++i)
		{
			double temp = a[i];
			while(temp+1 > a[i+1] && i < n)
				i++;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
import java.util.*;
import java.math.*;

public class Main {
/*
	public static boolean isprim[] = new boolean[10100];
	public static BigInteger prim[] = new BigInteger[10000];
	public static int intprim[] = new int[10000];
	public static int p;

	public static void judge()
	{
		prim[0] = new BigInteger("2");
		intprim[0] = 2;
		p = 1;
		for(int i = 3;i < 10000;i += 2)
			isprim[i] = true;
		BigInteger two = new BigInteger("2");
		int k = 3;
		for(BigInteger i = new BigInteger("3");k < 10000;i = i.add(two),k+=2)
		{
			if(isprim[k])
			{
				intprim[p] = k;
				prim[p++] = i;
				for(int j = k*3;j < 10000;j += k+k)
					isprim[j] = false;
			}
		}
	}
	*/
	public static void main(String[] args) {
		////////////////////////////////////////////////////////
		Scanner cin = new Scanner(System.in);
		BigInteger [][]a = new BigInteger[1111][22];
		while(cin.hasNext())
		{
			int m = cin.nextInt();
			int n = cin.nextInt();
			for(int i = 0;i < n;++i)
			{
				for(int j = 0;j < m;++j)
					a[i][j] = cin.nextBigInteger();
			}
			int ans = 1;
			BigInteger Ma = BigInteger.ZERO,temp;
			for(int j = 0;j < m;++j)
			{
				temp = BigInteger.ONE;
				for(int i = 0;i < n;++i)
					temp = temp.multiply(a[i][j]);
				if(j == 0)
				{
					Ma = temp;
				}
				else if(Ma.compareTo(temp) <= 0)
				{
					Ma = temp;
					ans = j+1;
				}
			}
			System.out.println(ans);
		}
	}
}
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1005
using namespace std;

int d[N][N][2];
int a[N][N];
int sumh[N][N];
int suml[N][N];
int n;

int main()
{
	int i,j;
	while(scanf("%d",&n) == 1)
	{
		for(i = 1;i <= n; i ++)
			for(j = 1; j <= n;j ++)
				scanf("%d",&a[i][j]);

		memset(sumh,0,sizeof(sumh));
		memset(suml,0,sizeof(suml));

		for(i = 1; i <= n ;i ++)
		{
			for(j = 1;j <= n;j ++)
			{
				sumh[i][j] = sumh[i][j - 1] + a[i][j];
				suml[i][j] = suml[i - 1][j] + a[i][j];
			}
		}
		int H = 0;
		int L = 1;
		memset(d,-1,sizeof(d));
		for(i = 0; i <= n;i ++)
		{
			d[0][i][H] = d[0][i][L] = 1;
			d[i][0][H] = d[i][0][L] = 1;
		}
		for(i = 1; i <= n; i ++)
			for(j = 1; j <= n; j ++)
			{
				if(sumh[i][j] % 2 == 0)
				{
					if( d[i - 1][j][H] == 0 || d[i - 1][j][L] == 0)
						d[i][j][H] = 1;
					else if( d[i - 1][j][H] == 1 && d[i - 1][j][L] == 1 )
						d[i][j][H] = 0;
				}
				if(suml[i][j] % 2 == 0)
				{
					if( d[i ][j - 1][H] == 0 || d[i ][j- 1][L] == 0)
						d[i][j][L] = 1;
					else if( d[i ][j- 1][H] == 1 && d[i ][j- 1][L] == 1 )
						d[i][j][L] = 0;
				}
				if(suml[i][j] % 2 != 0 && sumh[i][j] %2 != 0)
					d[i][j][H] = d[i][j][L] = 1;
			}
		if(d[n][n][L] == 0 || d[n][n][H] == 0)
			printf("W\n");
		else
			printf("L\n");
	}
	return 0;
}