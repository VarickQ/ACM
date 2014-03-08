#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 200001

struct Node
{
	int left,right;
	int max;
};
Node node[N*3];
int s[N];
inline int GetMax(int a,int b){
	if(a>b) return a;
	return b;
}
void creatTree(int l,int r,int id)
{
	node[id].left=l;
	node[id].right=r;
	if(l==r)node[id].max = s[r];

	if(node[id].left == node[id].right) return;

	int mid = (l+r)/2;
	creatTree(l,mid,2*id);
	creatTree(mid+1,r,2*id+1);
	node[id].max = GetMax(node[2*id].max,node[2*id+1].max);

}
void modify(int x,int y,int id)
{
	node[id].max = GetMax(node[id].max,y);
	if(node[id].left==x && node[id].right==x){
		node[id].max = y;
		return ;
	}
	int mid=(node[id].left+node[id].right)/2;

	if(x <= mid) modify(x,y,2*id);
	else modify(x,y,2*id+1);

}
int search(int l,int r,int id)
{
	if(node[id].left==l && node[id].right==r)
		return node[id].max;
	if(node[id].left < node[id].right)
	{
		int mid = (node[id].left+node[id].right)/2;
		if(l > mid)
			return search(l,r,2*id+1);
		else
		{
			if(r <= mid)
				return search(l,r,2*id);
			else
				return GetMax(search(l,mid,2*id),search(mid+1,r,2*id+1));
		}
	}
	return node[id].max;
}
int main()
{
	int T,n,m,i,a,b;
	char ch[5];
	while(scanf("%d%d",&n,&m)==2){
		for(i=1 ; i <= n ; i++)
			scanf("%d",&s[i]);
		creatTree(1,n,1);
		while(m--){
			scanf("%s",ch);
			if(ch[0]=='U'){
				scanf("%d%d",&a,&b);
				modify(a,b,1);
			}
			else if(ch[0]=='Q'){
				scanf("%d%d",&a,&b);
				printf("%d\n",search(a,b,1));
			}
		}
	}
	return 0;
}