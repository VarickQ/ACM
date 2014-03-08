#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 1005

struct Node
{
	int left,right;
	int len;
	//cover：表示该节点被覆盖多少次。
	int cover;
}node[N*10];

struct Line
{
	int x,y1,y2;
	int f;//f标志是左边还是右边,做用1表示入，右是0表示出
}l[N*2];
int y[N*2];

bool cmp(Line a,Line b){
	return a.x < b.x;
}
void createTree(int l,int r,int id)
{
	node[id].left = y[l];
	node[id].right= y[r];
	node[id].len=node[id].cover=0;
	node[2*id].len=node[2*id].cover=0;
	node[2*id+1].len=node[2*id+1].cover=0;
	
	if(r-l==1)return ;
	int mid=(l+r)/2;
	createTree(l,mid,2*id);
	createTree(mid,r,2*id+1);
}
void Getlen(int id)
{
	if(node[id].cover>=1)
		node[id].len=node[id].right-node[id].left;
	else
		node[id].len=node[id*2].len+node[id*2+1].len;
}
void update(Line l,int id)
{
	if(node[id].left==l.y1 && node[id].right==l.y2)
	{
		node[id].cover += l.f;
		Getlen(id);
		return ;
	}
	if(l.y2<=node[2*id].right)
		update(l,2*id);
	else if(l.y1>=node[2*id+1].left)
		update(l,2*id+1);
	else{
		Line l1=l;
		Line l2=l;
		l1.y2 = node[2*id].right;
		l2.y1 = node[2*id+1].left;
		update(l1,2*id);
		update(l2,2*id+1);
	}
	Getlen(id);
}
int main()
{
	int n,ls,ys,i;
	int x1,x2,y1,y2;
	while(1)
	{
		ls = 0;
		i = 0;
		int tempy[N*2];
		while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2) == 4)
		{
			if(x1==-1&&x2==-1&&y1==-1&&y2==-1)break;
			if(x1==-2&&x2==-2&&y1==-2&&y2==-2)break;
			if(x1>x2)swap(x1,x2);
			if(y1>y2)swap(y1,y2);
			l[ls].x = x1;
			l[ls].y1= y1;
			l[ls].y2= y2;
			l[ls].f = 1;
			tempy[ls]=y1;

			l[ls+1].x = x2;
			l[ls+1].y1= y1;
			l[ls+1].y2= y2;
			l[ls+1].f = -1;
			tempy[ls+1]=y2;

			ls += 2;
		}
		sort(l,l+ls,cmp);
		sort(tempy,tempy+ls);

		ys = 0;//取出重复的边
		y[ys++] = tempy[0];
		for(i=1 ; i < ls ; i++)
		{
			if(tempy[i]==tempy[i-1])continue;
			y[ys++] = tempy[i];
		}
		createTree(0,ys-1,1);
		int ans=0;
		for(i=0 ; i < ls-1 ; i++)
		{
			update(l[i],1);
			ans += node[1].len*(l[i+1].x-l[i].x);
		}
		printf("%d\n",ans);

		if(x1==-2&&x2==-2&&y1==-2&&y2==-2)break;
	}
	return 0;
}