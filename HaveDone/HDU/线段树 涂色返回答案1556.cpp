#include <iostream>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define inf 10000000
#define N 100001

struct Node{
	int left,right;
	int colour;
}node[N*3];
void creatTree(int l,int r,int id)
{
	node[id].colour = 0;
	node[id].left = l;
	node[id].right = r;

	if(node[id].left == node[id].right) return;

	int mid = (l+r)/2;
	creatTree(l,mid,2*id);
	creatTree(mid+1,r,2*id+1);
}
void insert(int l,int r,int id)
{
	if(node[id].left==l && node[id].right==r){
		node[id].colour++;
		return ;
	}

	int mid=(node[id].left+node[id].right)/2;

	if(r <= mid) insert(l,r,2*id);
	else{
		if(l > mid)
			insert(l,r,2*id+1);
		else{
			insert(l,mid,2*id);
			insert(mid+1,r,2*id+1);
		}
	}
}
int search(int c,int id,int v)
{
	if(node[id].left==c&&node[id].right==c)
		return node[id].colour+v;
	else{
		int mid=(node[id].left+node[id].right)/2;
		if(c <= mid)
			return search(c,2*id,v+node[id].colour);
		else return search(c,2*id+1,v+node[id].colour);
	}
}
int main()
{
	int n,i,a,b;
	while(scanf("%d",&n) && n)
	{
		creatTree(1,n,1);
		for(i=1 ; i <= n ; i++){
			scanf("%d%d",&a,&b);
			insert(a,b,1);
		}
		for(i=1 ; i <= n ; i++){
			if(i==1)
				printf("%d",search(i,1,0));
			else
				printf(" %d",search(i,1,0));
		}
		printf("\n");
	}
	return 0;
}