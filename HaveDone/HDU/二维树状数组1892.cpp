#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define N 1005

int c[N][N],num[N][N];
int lowbit(int t){
	return t&(-t);
}
void update(int x,int y,int num){
	while(x <= N-2){
		int j=y;
		while(j <= N-2){
			c[x][j] += num;
			j += lowbit(j);
		}
		x += lowbit(x);
	}
}
int Sum(int x,int y){
	int sum=0;
	while(x > 0){
		int j=y;
		while(j > 0){
			sum += c[x][j];
			j -= lowbit(j);
		}
		x -= lowbit(x);
	}
	return sum;
}
int main()
{
	int T,i,j,x1,x2,y1,y2,n1,cs=1,n,t;
	char ch[3];
	scanf("%d",&T);
	while(T--)
	{
		printf("Case %d:\n",cs++);
		for(i=1 ; i < N-2 ; i++)
			for(j=1 ; j < N-2 ; j++){
				num[i][j] = 1;
				c[i][j] = lowbit(i)*lowbit(j);
			}
		scanf("%d",&n);
		for(i=0 ; i < n ; i++)
		{
			scanf("%s",ch);
			if(ch[0]=='S'){
				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				x1++; y1++; x2++; y2++;
				if(x1>x2)swap(x1,x2);
				if(y1>y2)swap(y1,y2);
				int ans=Sum(x2,y2)-Sum(x1-1,y2)-Sum(x2,y1-1)+Sum(x1-1,y1-1);
				printf("%d\n",ans);
			}
			if(ch[0]=='A'){
				scanf("%d %d %d",&x1,&y1,&n1);
				x1++; y1++;
				num[x1][y1] += n1;
				update(x1,y1,n1);
			}
			if(ch[0]=='D'){
				scanf("%d %d %d",&x1,&y1,&n1);
				x1++; y1++;
				if(num[x1][y1] <= n1)
					n1 = num[x1][y1];
				num[x1][y1] -= n1;
				update(x1,y1,-n1);
			}
			if(ch[0]=='M'){
				scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&n1);
				x1++; x2++; y1++; y2++;
				if(num[x1][y1] <= n1)
					n1 = num[x1][y1];
				num[x1][y1] -= n1;
				num[x2][y2] += n1;
				update(x1,y1,-n1);
				update(x2,y2,n1);
			}
		}
	}
	return 0;
}