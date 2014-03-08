#include <iostream>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define inf 10000000
#define N 500001
int in[N],res;
struct Node
{
	int left,right;
	int num;
}node[N*3];
void creatTree(int l,int r,int id)
{
	node[id].left=l;
	node[id].right=r;
	if(l==r)node[id].num=in[r];

	if(node[id].left == node[id].right) return;

	int mid = (l+r)/2;
	creatTree(l,mid,2*id);
	creatTree(mid+1,r,2*id+1);
	node[id].num=node[2*id].num+node[2*id+1].num;

}
void add(int num,int n,int id)
{
	node[id].num += n;
	if(node[id].left==num && node[id].right==num)
		return;
	int mid = (node[id].left+node[id].right)/2;

	if(mid < num) add(num,n,2*id+1);//at right
	else add(num,n,2*id);//at left

}
void sub(int num,int n,int id)
{
	node[id].num -= n;
	if(node[id].left==num && node[id].right==num)
		return ;
	int mid = (node[id].left+node[id].right)/2;

	if(mid < num) sub(num,n,2*id+1);
	else sub(num,n,2*id);

}
void query(int l,int r,int id)
{
	if(node[id].left>=l && node[id].right<=r)
		res += node[id].num;
	else {
		int mid = (node[id].left+node[id].right)/2;
		if(r <= mid) query(l,r,2*id);
		else{
			if(l > mid) query(l,r,2*id+1);
			else{
				query(l,mid,2*id);
				query(mid+1,r,2*id+1);
			}
		}
	}
}
int main()
{
	int T,n,i,cs=1,a,b;
	char str[10];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1 ; i <= n ; i++)
			scanf("%d",&in[i]);
		printf("Case %d:\n",cs++);
		creatTree(1,n,1);
		while(scanf("%s",str)!=EOF){
			if(strcmp(str,"Add") == 0){
				scanf("%d%d",&a,&b);
				add(a,b,1);
			}
			else if(strcmp(str,"Sub") == 0){
				scanf("%d%d",&a,&b);
				sub(a,b,1);
			}
			else if(strcmp(str,"Query") == 0){
				res = 0;
				scanf("%d%d",&a,&b);
				query(a,b,1);
				printf("%d\n",res);
			}
			else if(strcmp(str,"End") == 0)
				break;
		}
	}
	return 0;
}