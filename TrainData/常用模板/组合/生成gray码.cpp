//生成reflected gray code
//每次调用gray取得下一个码
//000...000是第一个码,100...000是最后一个码
void gray(int n,int *code){
	int t=0,i;
	for (i=0;i<n;t+=code[i++]);
	if (t&1)
		for (n--;!code[n];n--);
	code[n-1]=1-code[n-1];
}