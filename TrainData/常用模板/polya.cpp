//ploya by alpc62
//����������double���Ȳ����ͻ���int64����long long�������Լ�д��Ӧ������pow�Ƚϱ���
//����������ã����Լ�д�߾��Ȱ�
#include <memory.h>
#include <math.h>

double ploya1(int c,int n)//��ת�ͷ�ת��Ϊ��ͬ
{
        int i,j,k,x,y;
        double t=0.0;
        memset(b1,0,sizeof(b1));
        memset(b2,0,sizeof(b2));
        for (i=0;i<=n-1;i++)
        {
              for (x=y=j=0;j<=n-1;j++)
              {
                    if (!b1[(i+j)%n])
                          for (x++,k=(i+j)%n;!b1[k];k=(i+k)%n)
                                b1[k]=true;
                    if (!b2[n-1-(i+j)%n])
                          for (y++,k=n-1-(i+j)%n;!b2[k];k=n-1-(i+k)%n)
                                b2[k]=true;
              }
              t=t+pow(c,x)+pow(c,y);
        }
        return t/(2*n);
}

double ploya2(int c,int n)//��ת��Ϊ��ͬ����תΪ��
{
        int i,j,k,x;
        double t=0.0;
        memset(bj,0,sizeof(bj));
        for (i=0;i<=n-1;i++)
        {
              for (x=y=j=0;j<=n-1;j++)
                    if (!bj[(i+j)%n])
                          for (x++,k=(i+j)%n;!bj[k];k=(i+k)%n)
                                bj[k]=true;
              t=t+pow(c,x);
        }
        return t/n;
}

double ploya3(int c,int n)//��ת��Ϊ��ͬ����תΪ��
{
        int x=n/2;
        if (n%2)        x++;
        return (pow(c,n)+pow(c,x))/2;
}
