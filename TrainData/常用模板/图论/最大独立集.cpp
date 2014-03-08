//最大独立集
//返回最大独立集大小,传入图的大小n和邻接阵mat
//使用前条用init初始化
//mat[i][j]为布尔量
#ifdef WIN32
typedef __int64 i64;
#else
typedef long long i64;
#endif

#define MAXN 60
int bitcount[1<<20];
#define cmask ((i64)((1<<20)-1))
#define numbits(x) (bitcount[(x)&cmask]+bitcount[((x)>>20)&cmask]+bitcount[(x)>>40])
int max;

void search(int n,i64 vec[MAXN],int step,int now,i64 mymask){
	i64 newmask;
	if (step<0){
		max=now;
		return;
	}
	if (mymask&(((i64)1)<<step)){
		newmask=mymask&~vec[step];
		if (now+1+numbits(newmask)>max)
			search(n,vec,step-1,now+1,newmask);
	}
	newmask=mymask&~(((i64)1)<<step);
	if (now+numbits(newmask)>max)
		search(n,vec,step-1,now,newmask);
}

void sort(int n,int mat[MAXN][MAXN]){
	int tmp[MAXN][MAXN],d[MAXN],o[MAXN],i,j,t;
	for (i=0;i<n;i++)
		for (d[o[i]=i]=j=0;j<n;j++)
			d[i]+=mat[i][j];
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			if (d[i]>d[j]){
				t=d[i],d[i]=d[j],d[j]=t;
				t=o[i],o[i]=o[j],o[j]=t;
			}
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			tmp[i][j]=mat[o[i]][o[j]];
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			mat[i][j]=tmp[i][j];
}

void mat2vec(int n,int mat[MAXN][MAXN],i64 vec[MAXN]){
	int i,j;
	for (i=0;i<n;i++)
		for (vec[i]=j=0;j<n;j++)
			if (mat[i][j])
				vec[i]|=((i64)1)<<j;
}

int independent(int n,int mat[MAXN][MAXN]){
	i64 vec[MAXN];
	int i;
	max=1;
	sort(n,mat);
	for (i=0;i<n;i++)
		mat[i][i]=1;
	mat2vec(n,mat,vec);
	search(n,vec,n-1,0,(((i64)1)<<n)-1);
	return max;
}

void init(){
	int i,t;
	for (i=0;i<(1<<20);i++)
		for (bitcount[0],t=i;t;t>>=1)
			bitcount[i]+=t&1;
}