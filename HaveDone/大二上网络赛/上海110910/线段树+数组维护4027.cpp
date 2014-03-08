#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
#define ll __int64
#define N 100100

struct Node
{
	int left,right;
	ll val;
}node[N*4];
bool isOne[N*4];
ll a[N];
void creatTree(int l,int r,int id)
{
	node[id].left=l;
	node[id].right=r;
	if(l == r){
		node[id].val = a[l];
		if(node[id].val == node[id].right-node[id].left+1)
			isOne[id] = true;
	} else {
		int mid = (l+r)/2;
		creatTree(l,mid,id*2);
		creatTree(mid+1,r,id*2+1);
		node[id].val = node[2*id].val + node[2*id+1].val;
		if(node[id].val == node[id].right-node[id].left+1)
			isOne[id] = true;
	}
}

void modify(int l,int r,int id)
{
	if(node[id].left > r || node[id].right < l) return ;
	if(isOne[id]) return ;

	if(node[id].left == node[id].right){
		node[id].val = (__int64)sqrt(1.0*node[id].val);
		if(node[id].val == node[id].right-node[id].left+1)
			isOne[id] = true;
	} else {
		int mid = (node[id].left+node[id].right)/2;
		if(r <= mid)
			modify(l,r,id*2);
		else{
			if(l > mid)
				modify(l,r,id*2+1);
			else{
				modify(l,mid,id*2);
				modify(mid+1,r,id*2+1);
			}
		}
		node[id].val = node[2*id].val + node[2*id+1].val;
		if(node[id].val == node[id].right-node[id].left+1)
			isOne[id] = true;
	}
}

ll Getans(int l,int r,int id)
{
	if(node[id].left > r || node[id].right < l) return 0;
	if(node[id].left>=l && node[id].right<=r)
		return node[id].val;

	int mid = (node[id].left+node[id].right)/2;
	if(r <= mid)
		return Getans(l,r,id*2);
	else{
		if(l > mid)
			return Getans(l,r,id*2+1);
		else{
			return Getans(l,mid,2*id)+Getans(mid+1,r,2*id+1);
		}
	}
}
int main()
{
	int n,q,x,y,z,cs=0;
	while(scanf("%d",&n) != EOF)
	{
		memset(isOne,false,sizeof(isOne));
		for(int i=1 ; i <= n ; ++i)
			scanf("%I64d",&a[i]);
		creatTree(1,n,1);
		scanf("%d",&q);
		printf("Case #%d:\n",++cs);
		for(int i=0 ; i < q ; ++i){
			scanf("%d%d%d",&x,&y,&z);
			if(y > z) swap(y,z);
			if(x == 0)
				modify(y,z,1);
			else
				printf("%I64d\n",Getans(y,z,1));
		}
		printf("\n");
	}
	return 0;
}