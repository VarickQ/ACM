#include <cstdlib>
#include <cstdio>
#include <string>
#define MAX 300
using namespace std;
/*
*  使用说明:
*  MAX为max(|X|,|Y|), 构图的时候建议min(|X|,|Y|)做为列数.
*  vc[][MAX]为输入的二部图.nv1为min(|X|,|Y|),nv2,为max(|x|,|y|)
*  vm1[],vm2保存最大对集
*
*/

int Bipartite(bool vc [][MAX],int nv1,int nv2) {
    int i, j, x, n;
    int q[MAX], prev[MAX], qs, qe;
    int vm1[MAX], vm2[MAX];

    n = 0;
    for( i = 0; i < nv1; i++ ) vm1[i] = -1;
    for( i = 0; i < nv2; i++ ) vm2[i] = -1;
    for( i = 0; i < nv1; i++ ) {
        for( j = 0; j < nv2; j++ ) prev[j] = -2;
        qs = qe = 0;
        for( j = 0; j < nv2; j++ ) if( vc[i][j] ) {
            prev[j] = -1;
            q[qe++] = j;
        }
        while( qs < qe ) {
            x = q[qs];
            if( vm2[x] == -1 ) break;
            qs++;
            for( j = 0; j < nv2; j++ ) if( prev[j] == -2 && vc[vm2[x]][j] ) {
                prev[j] = x;
                q[qe++] = j;
            }
        }
        if( qs == qe ) continue;
        while( prev[x] > -1 ) {
            vm1[vm2[prev[x]]] = x;
            vm2[x] = vm2[prev[x]];
            x = prev[x];
        }
        vm2[x] = i;
        vm1[i] = x;
        n++;
    }
    return n;
}

int main()
{
	int T;
	scanf("%d",&T);
	bool bp[100][300];
	while(T--)
	{
		int p,s;
		scanf("%d %d",&p,&s);
		memset(bp,0,sizeof(bp));
		for(int i = 0; i < p;i++)
		{
			int num;
			scanf("%d",&num);
			for(int j = 0; j < num;j++)
			{
				int temp;
				scanf("%d",&temp);
				bp[i][--temp] = true;
			}
		}
		int n = Bipartite(bp,p,s);
		if(n == p)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
