//joseph模拟,传入人数n,每次数的人数k,返回最后一个人的序号1..n

int joseph(int n,int k){
	int ret=-1,i;
	for (i=1;i<=n;i++)
		ret=(ret+k)%i;
	return ret+1;
}