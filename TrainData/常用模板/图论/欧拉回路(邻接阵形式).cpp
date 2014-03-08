//��ŷ����·��ŷ��·,�ڽ�����ʽ,���Ӷ�O(n^2)
//����·������,path����·��
//����ͼ�Ĵ�Сn���ڽ���mat,�����ڵ��Ȩ0
//�������Ի����ر�,��Ϊ����ͼ������ͼ

#define MAXN 100

void find_path_u(int n,int mat[][MAXN],int now,int& step,int* path){
	int i=0;
	for (;i>=0;)
		for (i=n-1;i>=0;i--)
			if (mat[now][i]){
				mat[now][i]--,mat[i][now]--;
				find_path_u(n,mat,i,step,path);
				break;
			}
	path[step++]=now;
}

void find_path_d(int n,int mat[][MAXN],int now,int& step,int* path){
	int i=0;
	for (;i>=0;)
		for (i=n-1;i>=0;i--)
			if (mat[now][i]){
				mat[now][i]--;
				find_path_d(n,mat,i,step,path);
				break;
			}
	path[step++]=now;
}

int euclid_path(int n,int mat[][MAXN],int start,int* path){
	int ret=0;
	find_path_u(n,mat,start,ret,path);
//	find_path_d(n,mat,start,ret,path);
	return ret;
}