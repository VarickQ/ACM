//����ĸ����
//��m[]����ֵΪw[]�Ļ����ܷ񹹳�value
//�ʺ�m[]�ϴ�w[]��С�����
//���ز�����
//�����������n,����m[],��ֵw[]��Ŀ��ֵvalue
#define MAXV 100000

int genfunc(int n,int* m,int* w,int value){
	int i,j,k,c;
	char r[MAXV];
	for (r[0]=i=1;i<=value;r[i++]=0);
	for (i=0;i<n;i++){
		for (j=0;j<w[i];j++){
			c=w[i]*r[k=j];
			while ((k+=i)<=value)
				if (r[k])
					c=w[i];
				else if (c)
					r[k]=1,c--;
			if (r[value])
				return 1;
		}
	}
	return 0;
}
