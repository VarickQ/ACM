#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Queue{
	int head,tail;//��¼���׺Ͷ�β
	int X[1000005];//��¼Ԫ����ԭ�����е��±�
}Max,Min;
int num[1000005],n,k;
int main()
{
	while(scanf("%d%d",&n,&k) == 2)
	{
		for(int i=1 ; i <= n ; i++)
			scanf("%d",&num[i]);
		Min.X[0]=1;//��ʼ��,����Ϊ��һ��Ԫ�ص��±�
		for(int i=1 ; i <= n ; i++)
		{
			//���ҽ������зǿղ��Ҷ�βԪ�ش��ڵ��ڵ�ǰδ���Ԫ��ʱ
			while(Min.head<=Min.tail && num[Min.X[Min.tail]]>=num[i])
				//����βԪ��ɾ��,ֱ����βԪ�رȵ�ǰԪ��С
				Min.tail--;
			Min.tail++;//����
			Min.X[Min.tail]=i;//��¼�±�

			//�������䳤��,��β�Ƿ���ͬһ������
			while(Min.X[Min.tail]-Min.X[Min.head]+1>k)
				//�������,����Ԫ�س���
				Min.head++;
			//ֱ���������䳤��,��Сֵ�����ڶ���
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
	int left,right;//���ұ߽�
	int min,max;//�������ڵ���Сֵ�����ֵ
};

Node node[N*3];
int a[N];//a[i]��¼��i��λ���ϵ�����


inline int Min(int a,int b)
{
	return a<b?a:b;
}

inline int Max(int a,int b)
{
	return a>b?a:b;
}

//����
void createTree(int L,int R,int id)
{
   node[id].left = L;
   node[id].right = R;

   //Ҷ�ӽڵ�
   if(node[id].left==node[id].right)
   {
       node[id].min = a[L];
	   node[id].max = a[L];
	   return;
   }

   int mid = (node[id].left+node[id].right)>>1;
   
   //������
   createTree(L,mid,2*id);
   //������
   createTree(mid+1,R,2*id+1);
    
   node[id].min = Min(node[2*id].min,node[2*id+1].min);
   node[id].max = Max(node[2*id].max,node[2*id+1].max);
}

/*�������[L,R]֮��ĳ����ֵ*/
int search(int L,int R,int id, int (*function)(int,int))
{
	if(node[id].left>=L&&node[id].right<=R)
		return function(node[id].min,node[id].max);

	int mid = (node[id].left+node[id].right)>>1;

	if(R <= mid)//��������
	   return search(L,R,2*id,function);

    if(L > mid)//λ��������
	   return search(L,R,2*id+1,function);

	//�ֱ�λ����������
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
		printf("%d ", search(i,i+k-1,1,Min));//��ȡ����[i,i+k-1]�Ĵ�
    printf("%d\n",search(i,i+k-1,1,Min));

	for(i=1;i<last;i++)
		printf("%d ",search(i,i+k-1,1,Max));
	printf("%d\n",search(i,i+k-1,1,Max));

	return 0;
}