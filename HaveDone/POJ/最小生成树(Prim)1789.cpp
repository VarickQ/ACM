/*���⣺n�Ŀ�����ÿ����ӵ��Ψһ��7λ���ƺš�
����֮�䳵�ƺŵ��м�λ����ͬ�ͱ�ʾ�ж��Ĳ��
������֮��ľ����ж�Զ������ͨ���д�����̾���͡�
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll __int64
const int inf = 2000000000;
const int N = 2010;

int n,mat[N][N];
//Prim��С������
void Prim()
{
    int i,j,min_i,min,sum=0;
    int dis[N];
    int flag[N];
    for( i=1 ; i <= n ; i++ )
		dis[i] = mat[i][1];
    memset( flag, 0, sizeof(flag));
	flag[1] = 1;
    for( i=2 ; i <= n ; i++ )
    {
        min = inf; min_i=i;
        for( j=2 ; j <= n ; j++ )
            if(flag[j]==0 && dis[j]<min)
            {
                min = dis[j];
                min_i = j;
            }
		if(min == inf) break;
		sum += min;
        flag[min_i] = 1;
        for( j=2 ; j <= n ; j++ )
        {
            if(flag[j]==0 && dis[j]>mat[min_i][j])
                dis[j] = mat[min_i][j];
        }
    }
	printf("The highest possible quality is 1/%d.\n", sum);
}
char a[N][10];
int main()
{
	while(scanf("%d",&n) && n)
	{
		memset(mat,0,sizeof(mat));
		for(int i=1 ; i <= n ; ++i){
			scanf("%s",a[i]);
			for(int j=1 ; j < i ; ++j){
				int cnt = 0;
				for(int k=0 ; k < 7 ; ++k)
					if(a[i][k] != a[j][k])
						cnt++;
				mat[i][j]=mat[j][i]=cnt;
			}
		}
		Prim();
	}
	return 0;
}