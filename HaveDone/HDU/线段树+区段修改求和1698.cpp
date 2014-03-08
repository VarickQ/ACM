#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 1000001

struct Node
{
	int left,right;
	int val;
}node[N*3];
void creatTree(int l,int r,int id)
{
	node[id].left=l;
	node[id].right=r;
	node[id].val = 1;

	if(node[id].left==node[id].right) return ;

	int mid = (l+r)/2;
	creatTree(l,mid,id*2);
	creatTree(mid+1,r,id*2+1);

}
//区段[l,r]修改
void modify(int l,int r,int val,int id)
{
	if(node[id].left>=l && r>=node[id].right){
		node[id].val = val;
		return ;
	}
	int mid=(node[id].left+node[id].right)/2;
	//当前区域被完全覆盖，则其左右子树也被完全覆盖
	if(node[id].val > 0)
	{
		node[id*2].val=node[id].val;
		node[id*2+1].val=node[id].val;
	}
	node[id].val = -1;//没有完全覆盖住

	if(r <= mid)
		modify(l,r,val,id*2);
	else{
		if(l > mid)
			modify(l,r,val,id*2+1);
		else{
			modify(l,mid,val,id*2);
			modify(mid+1,r,val,id*2+1);
		}
	}
}
int res;//统计总和结果
void Getans(int l,int r,int id)
{
	if(node[id].val > 0)
	{
		res += node[id].val*(node[id].right-node[id].left+1);
		return ;
	}
	if(node[id].left==node[id].right) return;

	int mid=(node[id].left+node[id].right)/2;
	if(r <= mid)
		Getans(l,r,id*2);
	else{
		if(l > mid)
			Getans(l,r,id*2+1);
		else{
			Getans(l,mid,id*2);
			Getans(mid+1,r,id*2+1);
		}
	}
}
int main()
{
	int T,n,q,x,y,z,cs=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		creatTree(1,n,1);
		for(int i=1 ; i <= q ; i++){
			scanf("%d%d%d",&x,&y,&z);
			modify(x,y,z,1);
		}
		res = 0;
		Getans(1,n,1);
		printf("Case %d: The total value of the hook is %d.\n",cs++,res);
	}
	return 0;
}