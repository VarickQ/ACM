#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Queue{
	int head,tail;//记录队首和队尾
	int X[1000005];//记录元素在原队列中的下标
}Max,Min;
int num[1000005],n,k;
int main()
{
	while(scanf("%d%d",&n,&k) == 2)
	{
		for(int i=1 ; i <= n ; i++)
			scanf("%d",&num[i]);
		Min.X[0]=1;//初始化,队首为第一个元素的下标
		for(int i=1 ; i <= n ; i++)
		{
			//当且仅当队列非空并且队尾元素大于等于当前未入队元素时
			while(Min.head<=Min.tail && num[Min.X[Min.tail]]>=num[i])
				//将队尾元素删除,直到队尾元素比当前元素小
				Min.tail--;
			Min.tail++;//插入
			Min.X[Min.tail]=i;//记录下标

			//控制区间长度,首尾是否在同一个区间
			while(Min.X[Min.tail]-Min.X[Min.head]+1>k)
				//如果不在,队首元素出队
				Min.head++;
			//直到符合区间长度,最小值出现在队首
			if(i==k)printf("%d",num[Min.X[Min.head]]);
			else if(i>k)printf(" %d",num[Min.X[Min.head]]);
		}
		printf("\n");
		Max.X[0]=1;
		for(int i=1 ; i <= n ; i++)
		{
			while(Max.head<=Max.tail && num[Max.X[Max.tail]]<=num[i])
				Max.tail--;
			Max.tail++;
			Max.X[Max.tail]=i;
			while(Max.X[Max.tail]-Max.X[Max.head]+1>k)
				Max.head++;
			if(i==k)printf("%d",num[Max.X[Max.head]]);
			else if(i>k)printf(" %d",num[Max.X[Max.head]]);
		}
		printf("\n");
	}
	return 0;
}

#include <iostream>
using namespace std;
const int N = 1000001;

struct Node
{
	int left,right;//左右边界
	int min,max;//该区间内的最小值，最大值
};

Node node[N*3];
int a[N];//a[i]记录第i个位置上的数字


inline int Min(int a,int b)
{
	return a<b?a:b;
}

inline int Max(int a,int b)
{
	return a>b?a:b;
}

//建树
void createTree(int L,int R,int id)
{
   node[id].left = L;
   node[id].right = R;

   //叶子节点
   if(node[id].left==node[id].right)
   {
       node[id].min = a[L];
	   node[id].max = a[L];
	   return;
   }

   int mid = (node[id].left+node[id].right)>>1;
   
   //左子树
   createTree(L,mid,2*id);
   //右子树
   createTree(mid+1,R,2*id+1);
    
   node[id].min = Min(node[2*id].min,node[2*id+1].min);
   node[id].max = Max(node[2*id].max,node[2*id+1].max);
}

/*求解区间[L,R]之间某个最值*/
int search(int L,int R,int id, int (*function)(int,int))
{
	if(node[id].left>=L&&node[id].right<=R)
		return function(node[id].min,node[id].max);

	int mid = (node[id].left+node[id].right)>>1;

	if(R <= mid)//在左子树
	   return search(L,R,2*id,function);

    if(L > mid)//位于右子树
	   return search(L,R,2*id+1,function);

	//分别位于左右子树
	return function(search(L,mid,2*id,function),search(mid+1,R,2*id+1,function));

}

int main()
{
	int i,n,k;
	scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
		scanf("%d",&a[i]);

	createTree(1,n,1);

	int last = n-k+1;
	for(i=1;i<last;i++)
		printf("%d ", search(i,i+k-1,1,Min));//获取区间[i,i+k-1]的答案
    printf("%d\n",search(i,i+k-1,1,Min));

	for(i=1;i<last;i++)
		printf("%d ",search(i,i+k-1,1,Max));
	printf("%d\n",search(i,i+k-1,1,Max));

	return 0;
}