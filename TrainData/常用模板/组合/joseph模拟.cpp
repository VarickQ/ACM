//josephģ��,��������n,ÿ����������k,�������һ���˵����1..n

int joseph(int n,int k){
	int ret=-1,i;
	for (i=1;i<=n;i++)
		ret=(ret+k)%i;
	return ret+1;
}