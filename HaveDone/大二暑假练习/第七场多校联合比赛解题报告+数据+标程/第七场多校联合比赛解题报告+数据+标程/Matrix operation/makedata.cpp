//数据生成
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

int main()
{
	freopen("data.in","w",stdout);
	int t = 20000,i,j,k;
	printf("%d\n",t);
	srand(time(NULL));
	while(t--)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<3;j++)
			{
				k = rand()%256;
				printf("%X%X ",(k>>4),(k&15));
			}
			k = rand()%256;
			printf("%X%X\n",(k>>4),(k&15));
		}
	}
	return 0;
}