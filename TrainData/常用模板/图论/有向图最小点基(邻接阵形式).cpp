//����ͼ��С���,�ڽ�����ʽ,O(n^2)
//���ص缯��С�͵㼯
//����ͼ�Ĵ�Сn���ڽ���mat,�����ڵ��Ȩ0
//��Ҫ����ǿ��ͨ��֧
#define MAXN 100

int base_vertex(int n,int mat[][MAXN],int* sets){
	int ret=0,id[MAXN],v[MAXN],i,j;
	j=find_components(n,mat,id);
	for (i=0;i<j;v[i++]=0);
	for (i=0;i<n;i++)
		if (!v[id[i]-1]){
			for (v[id[i]-1]=1,j=0;j<n;j++)
				if (id[i]!=id[j]&&mat[j][i])
					break;
			if (j==n)
				sets[ret++]=i;
		}
	return ret;
}
