#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 1055
int a[N][N],n,c[N][N];
int Lowbit(int t){
    return t & ( -t );
}
void Plus(int x,int y,int num){
	while(x <= n){
		int j=y;
		while(j <= n){
			c[x][j] += num;
			j += Lowbit(j);
		}
		x += Lowbit(x);
	}
}
__int64 Sum(int x,int y){
	__int64 sum = 0;
	while(x > 0){
		int j=y;
		while(j > 0){
			sum += c[x][j];
			j -= Lowbit(j);
		}
		x -= Lowbit(x);
	}
	return sum;
}
int main()
{
	int f,x,y,s,l,b,r,t;
	while(scanf("%d",&f)!=EOF)
	{
		if(f==3) break;
		if(f==0){
			scanf("%d",&n);
		}else if(f==1){
			scanf("%d%d%d",&x,&y,&s);
			Plus(x+1,y+1,s);
		}else if(f==2){
			scanf("%d%d%d%d",&l,&b,&r,&t);
			l++; b++; r++; t++;
			__int64 ans;
			ans=Sum(r,t)-Sum(l-1,t)-Sum(r,b-1)+Sum(l-1,b-1);
			printf("%I64d\n",ans);
		}
	}
	return 0;
}