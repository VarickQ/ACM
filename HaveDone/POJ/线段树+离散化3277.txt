#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 40005

struct Node
{
	int left,right;
	int height;
}node[8*N];
struct Line
{
	int a,b,h;
}in[N];
int temp[N*2];//用于将坐标离散化，用下标来建线段树
int n;
bool cmp(Line a,Line b){
	return a.h < b.h;
}
void createTree(int l,int r,int id)
{
	node[id].left = l;
	node[id].right = r;
	node[id].height = 0;
	if(r-l>1){
		int mid=(l+r)/2;
		createTree(l,mid,2*id);
		createTree(mid,r,2*id+1);
	}
}
int search(int val)//二分查找，将数据离散化后再查找坐标点
{
	int l=0,r=2*n-1,mid;
	while(l <= r)
	{
		mid = (l+r)/2;
		if(temp[mid]==val) return mid;
		else if(temp[mid]<val) l=mid+1;
		else r = mid-1;
	}
}
void insert(int l,int r,int h,int id)
{
	if(node[id].left==l && node[id].right==r)
		node[id].height = h;
	else
	{
		if(node[id].height > 0){//当出现height更大，区间更小的覆盖时，需要特殊处理。
			node[2*id].height=node[id].height;
			node[2*id+1].height=node[id].height;
			node[id].height = 0;
		}
		int mid=(node[id].left+node[id].right)/2;
		if(mid>=r) insert(l,r,h,2*id);
		else if(l>=mid) insert(l,r,h,2*id+1);
		else{
			insert(l,mid,h,2*id);
			insert(mid,r,h,2*id+1);
		}
	}
}
__int64 ans;
void Getans(int id)
{
	if(node[id].height>0){
		ans += (__int64)(temp[node[id].right]-temp[node[id].left])*node[id].height;
	}
	else if(node[id].right-node[id].left>1){
		Getans(2*id);
		Getans(2*id+1);
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0 ; i < n ; i++){
		scanf("%d%d%d",&in[i].a,&in[i].b,&in[i].h);
		temp[i*2] = in[i].a;
		temp[i*2+1] = in[i].b;
	}
	sort(temp,temp+2*n);//排序，将坐标离散化
	createTree(0,n*2-1,1);//以下标作为线段树的划分，大大减小了树的规模
	sort(in,in+n,cmp);
	for(i=0 ; i < n ; i++)
		insert(search(in[i].a),search(in[i].b),in[i].h,1);
	ans = 0;
	Getans(1);
	printf("%I64d\n",ans);
	return 0;
}