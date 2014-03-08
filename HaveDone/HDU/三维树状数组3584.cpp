#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 105

int c[N][N][N],n;
int Lowbit(int t){return t&(-t);}

void update(int x,int y,int z,int num){
	while(x <= n){
		int i=y;
		while(i <= n){
			int j=z;
			while(j <= n){
				c[x][i][j] += num;
				j += Lowbit(j);
			}
			i += Lowbit(i);
		}
		x += Lowbit(x);
	}
}
int Sum(int x,int y,int z){
	int s = 0;
	while(x > 0){
		int i=y;
		while(i > 0){
			int j=z;
			while(j > 0){
				s += c[x][i][j];
				j -= Lowbit(j);
			}
			i -= Lowbit(i);
		}
		x -= Lowbit(x);
	}
	return s;
}
int main()
{
	int m,f,x2,y2,z2,x1,y1,z1;
	while(scanf("%d%d",&n,&m) == 2)
	{
		memset(c,0,sizeof(c));
		while(m--){
			scanf("%d",&f);
			if(f==1){
				scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
				update(x2+1,y2+1,z2+1,1);

				update(x1,y2+1,z2+1,-1);
				update(x2+1,y1,z2+1,-1);
				update(x2+1,y2+1,z1,-1);

				update(x2+1,y1,z1,1);
				update(x1,y2+1,z1,1);
				update(x1,y1,z2+1,1);

				update(x1,y1,z1,-1);
			}
			else if(f==0){
				scanf("%d%d%d",&x1,&y1,&z1);
				int num = Sum(x1,y1,z1);
				if(num%2==0)
					printf("0\n");
				else printf("1\n");
			}
		}
	}
	return 0;
}