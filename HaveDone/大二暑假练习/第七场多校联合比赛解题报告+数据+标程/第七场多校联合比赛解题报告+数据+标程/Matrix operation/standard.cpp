///*±Í≥Ã
#include <cstdio>
#include <cstring>

#define MAXN 10

int s_mat[MAXN][MAXN];//stateæÿ’Û
int m_mat[MAXN][MAXN];//mixæÿ’Û
int n_mat[MAXN][MAXN];//newæÿ’Û

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t,i,j,k,a,b;

        //æﬁ¥Ïµƒæÿ’Û≥ı ºªØ
	m_mat[0][2] = m_mat[0][3] = m_mat[1][0] = m_mat[1][3] = 1;
	m_mat[2][0] = m_mat[2][1] = m_mat[3][1]= m_mat[3][2] = 1;
	m_mat[0][0] = m_mat[1][1] = m_mat[2][2] = m_mat[3][3] = 2;
	m_mat[0][1] = m_mat[1][2] = m_mat[2][3] = m_mat[3][0] = 3;

	scanf("%d",&t);
	while(t--)
	{
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 4; j++)
			{
				scanf("%1x%1x",&a,&b);
				s_mat[i][j] = (a << 4) + b;
//				printf("%d\n",s_mat[i][j]);
				n_mat[i][j] = 0;
			}
		}
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 4; j++)
			{
				for(k = 0; k < 4; k++)
				{
					if(m_mat[i][k] != 2)
						n_mat[i][j] ^= s_mat[k][j];
					if(m_mat[i][k] != 1)
					{
						if((s_mat[k][j] & 128))
							n_mat[i][j] ^= 27;
						n_mat[i][j] ^= ((s_mat[k][j] << 1) & 255);
					}
				}
			}
		}
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 3; j++)
			{
				printf("%X%X ",(n_mat[i][j] >> 4),(n_mat[i][j] & 15));
			}
			printf("%X%X\n",(n_mat[i][j] >> 4),(n_mat[i][j] & 15));
		}
		if(t)
			printf("\n");
	}
	return 0;
}

/*in
87 F2 4D 97
6E 4C 90 EC
46 E7 4A C3
A6 8C D8 95
*/

/*out
47 40 A3 4C
37 D4 70 9F
94 E4 3A 42
ED A5 A6 BC
*/