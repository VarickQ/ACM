//��Դ���·��,bellman_ford�㷨,�ڽӱ���ʽ,���Ӷ�O(n*m)
//���Դs�����е�����·��,����ͼ�Ĵ�Сn���ڽӱ�list
//���ص�������̾���min[]��·��pre[],pre[i]��¼s��i·����i�ĸ����,pre[s]=-1
//�ɸ���·Ȩ����,·Ȩ��Ϊ��,��ͼ�������������ʧ��,����0
//�Ż�:��ɾȥ����ʹ��dijkstra����Ͻ�,���ٵ�������
#define MAXN 200
#define inf 1000000000
typedef int elem_t;
struct edge_t{
	int from,to;
	elem_t len;
	edge_t* next;
};

int bellman_ford(int n,edge_t* list[],int s,elem_t* min,int* pre){
	edge_t* t;
	int v[MAXN],i,j,k,tag;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[s]=0,j=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,t=list[k];t;t=t->next)
			if (!v[t->to]&&t->len>=0&&min[k]+t->len<min[t->to])
				min[t->to]=min[k]+t->len,pre[t->to]=k;
	}
	for (tag=1,j=0;tag&&j<=n;j++)
		for (tag=k=0;k<n;k++)
			for (t=list[k];t;t=t->next)
				if (min[k]+t->len<min[t->to])
					min[t->to]=min[k]+t->len,pre[t->to]=k,tag=1;
	return j<=n;
}