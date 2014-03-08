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
typedef __int64 ll;
const int inf = 2000000000;
const int M = 100000;
const int N = 1005;

//讲n(10)转化为a进制，并且存在tmp中，并返回数组长度
int tmp[3][10];
int Tento(int n,int a,int f){
	int i=0;
	while(n){
		tmp[f][i++]=n%a; //i=i*10+n%a;
		n/=a;
	}
	return i;
}
int main()
{
	int t,cs=1,h,m,s;
	scanf("%d\n",&t);
	while(t--)
	{
		memset(tmp,0,sizeof(tmp));
		scanf("%d:%d:%d",&h,&m,&s);
		printf("%d ",cs++);
		Tento(h,2,0);
		Tento(m,2,1);
		Tento(s,2,2);
		for(int i=5 ; i >= 0 ; i--)
			for(int j=0 ; j < 3 ; j++)
				printf("%d",tmp[j][i]);
		printf(" ");
		for(int i=0 ; i < 3 ; i++)
			for(int j=5 ; j >= 0 ; j--)
				printf("%d",tmp[i][j]);
		printf("\n");
	}
	return 0;
}