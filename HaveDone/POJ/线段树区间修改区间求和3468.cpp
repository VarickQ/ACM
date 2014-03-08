#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;
#define ll long long
const int inf = (1<<30);
const ll M = 1000000007;
const int N = 100010;

struct Node{
	int left,right;
	ll val,add;
}node[N*3];
int in[N];

void CreateTree(int l,int r,int id){
	node[id].left = l;
	node[id].right = r;
	node[id].add = 0;
	if(l == r){
		node[id].val = in[l];
		return ;
	}

	int mid = (l+r)>>1;
	CreateTree(l,mid,2*id);
	CreateTree(mid+1,r,2*id+1);
	node[id].val = node[2*id].val+node[2*id+1].val;
}
void modify(int l,int r,int id,int val){
	if(node[id].left>=l && node[id].right<=r){
		//覆盖这个区间 add增加 同时更新sum 这时add表示子树要增加的增量
		node[id].val += val*(node[id].right-node[id].left+1);
		node[id].add += val;
		return ;
	}
	int mid = (node[id].left+node[id].right)>>1;

	if(node[id].add != 0){
		//如果增量不为空,向下传递，同时更新儿子的sum值,最后清空自己的增量
		node[2*id].val += (node[2*id].right-node[2*id].left+1)*node[id].add;
		node[2*id+1].val += (node[2*id+1].right-node[2*id+1].left+1)*node[id].add;
		node[2*id].add += node[id].add;
		node[2*id+1].add += node[id].add;
		node[id].add = 0;
	}

	if(r <= mid) modify(l,r,2*id,val);
	else {
		if(l > mid) modify(l,r,2*id+1,val);
		else {
			modify(l,mid,2*id,val);
			modify(mid+1,r,2*id+1,val);
		}
	}
	//递归回来后 由左右孩子的sum值更新父亲的sum值
	node[id].val = node[2*id].val+node[2*id+1].val;
}
ll Getans(int l,int r,int id){
	if(node[id].left>=l && node[id].right<=r)
		return node[id].val;

	if(node[id].add != 0){
		node[2*id].val += (node[2*id].right-node[2*id].left+1)*node[id].add;
		node[2*id+1].val += (node[2*id+1].right-node[2*id+1].left+1)*node[id].add;
		node[2*id].add += node[id].add;
		node[2*id+1].add += node[id].add;
		node[id].add = 0;
	}

	int mid=(node[id].left+node[id].right)>>1;
	if(r <= mid) return Getans(l,r,2*id);
	else {
		if(l > mid) return Getans(l,r,2*id+1);
		else return Getans(l,mid,2*id)+Getans(mid+1,r,2*id+1);
	}
}
int main() {
	int n,m,a,b,c;
	char ch;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		for(int i=1 ; i <= n ; ++i)
			scanf("%d",&in[i]);
		CreateTree(1,n,1);
		for(int i=0 ; i < m ; ++i){
			scanf(" %c",&ch);
			if(ch == 'C'){
				scanf("%d%d%d",&a,&b,&c);
				modify(a,b,1,c);
			}
			else if(ch == 'Q'){
				scanf("%d%d",&a,&b);
				printf("%lld\n",Getans(a,b,1));
			}
		}
	}
	return 0;
}