#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 1005

struct Node
{
	double left,right;
	//once：表示该节点表示的长度中，被覆盖的长度。。
	//more：表示该节点表示的长度中，被覆盖2次以上的长度。
	double oncelen,morelen;
	//cover：表示该节点被覆盖多少次。
	int cover;
}node[N*10];

struct Line
{
	double x,y1,y2;
	int f;//f标志是左边还是右边,做用1表示入，右是0表示出
}l[N*2];
double y[N*2];

bool cmp(Line a,Line b){
	return a.x < b.x;
}
void createTree(int l,int r,int id)
{
	node[id].left = y[l];
	node[id].right= y[r];
	node[id].morelen=node[id].oncelen=node[id].cover=0;
	node[2*id].morelen=node[2*id].oncelen=node[2*id].cover=0;
	node[2*id+1].morelen=node[2*id+1].oncelen=node[2*id+1].cover=0;
	
	if(r-l==1)return ;
	int mid=(l+r)/2;
	createTree(l,mid,2*id);
	createTree(mid,r,2*id+1);
}
void updateOnce(int id)
{
	if(node[id].cover>=1)
		node[id].oncelen = node[id].right-node[id].left;
	else
		node[id].oncelen = node[2*id].oncelen+node[id*2+1].oncelen;
}
void updateMore(int id)
{
	if(node[id].cover==0)
		node[id].morelen=node[id*2].morelen+node[id*2+1].morelen;
	else if(node[id].cover==1)
		node[id].morelen=node[id*2].oncelen+node[id*2+1].oncelen;
	else
		node[id].morelen=node[id].right-node[id].left;
}
void update(Line l,int id)
{
	if(node[id].left==l.y1 && node[id].right==l.y2)
	{
		node[id].cover += l.f;
		updateOnce(id);
		updateMore(id);
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
	updateOnce(id);
	updateMore(id);
}
int main()
{
	int T,n,ls,ys,i;
	double x1,x2,y1,y2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ls = 0;
		double tempy[N*2];
		for(i=1 ; i <= n ; i++)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
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
		double ans=0;
		for(i=0 ; i < ls-1 ; i++)
		{
			update(l[i],1);
			ans += node[1].morelen*(l[i+1].x-l[i].x);
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}