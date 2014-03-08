#define MAXN 100
#define fabs(x) ((x)>0?(x):-(x))
#define eps 1e-10
// 小心 b[i] 中出现-0.0000 ，  b[i] += eps  防止 出现 -0.000000 
//列主元gauss消去求解a[][]x[]=b[]
//返回是否有唯一解,若有解在b[]中
int gauss_cpivot(int n,double a[][MAXN],double b[]){
	int i,j,k,row;
	double maxp,t;
	for (k=0;k<n;k++){
		for (maxp=0,i=k;i<n;i++)
			if (fabs(a[i][k])>fabs(maxp))
				maxp=a[row=i][k];
		if (fabs(maxp)<eps)
			return 0;
		if (row!=k){
			for (j=k;j<n;j++)
				t=a[k][j],a[k][j]=a[row][j],a[row][j]=t;
			t=b[k],b[k]=b[row],b[row]=t;
		}
		for (j=k+1;j<n;j++){
			a[k][j]/=maxp;
			for (i=k+1;i<n;i++)
				a[i][j]-=a[i][k]*a[k][j];
		}
		b[k]/=maxp;
		for (i=k+1;i<n;i++)
			b[i]-=b[k]*a[i][k];

	}
	for (i=n-1;i>=0;i--)
		for (j=i+1;j<n;j++)
			b[i]-=a[i][j]*b[j];
	return 1;
}

//全主元gauss消去解a[][]x[]=b[]
//返回是否有唯一解,若有解在b[]中
int gauss_tpivot(int n,double a[][MAXN],double b[]){
	int i,j,k,row,col,index[MAXN];
	double maxp,t;
	for (i=0;i<n;i++)
		index[i]=i;
	for (k=0;k<n;k++){
        for (maxp=0,i=k;i<n;i++)
			for (j=k;j<n;j++)
				if (fabs(a[i][j])>fabs(maxp))
					maxp=a[row=i][col=j];
        if (fabs(maxp)<eps)
			return 0;
		if (col!=k){
			for (i=0;i<n;i++)
				t=a[i][col],a[i][col]=a[i][k],a[i][k]=t;
			j=index[col],index[col]=index[k],index[k]=j;
		}
		if (row!=k){
			for (j=k;j<n;j++)
                t=a[k][j],a[k][j]=a[row][j],a[row][j]=t;
			t=b[k],b[k]=b[row],b[row]=t;
		}
		for (j=k+1;j<n;j++){
			a[k][j]/=maxp;
			for (i=k+1;i<n;i++)
				a[i][j]-=a[i][k]*a[k][j];
		}
		b[k]/=maxp;
		for (i=k+1;i<n;i++)
			b[i]-=b[k]*a[i][k];
	}
	for (i=n-1;i>=0;i--)
		for (j=i+1;j<n;j++)
			b[i]-=a[i][j]*b[j];
	for (k=0;k<n;k++)
		a[0][index[k]]=b[k];
	for (k=0;k<n;k++)
		b[k]=a[0][k];
	return 1;
}
