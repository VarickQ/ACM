//最小路径覆盖,O(n^3)
//求解最小的路径覆盖图中所有点,有向图无向图均适用
//注意此问题等价二分图最大匹配,可以用邻接表或正向表减小复杂度
//返回最小路径条数,pre返回前指针(起点-1),next返回后指针(终点-1)
#include <string.h>
#define MAXN 310
#define _clr(x) memset(x,0xff,sizeof(int)*n)

int hungary(int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<n;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}

inline int path_cover(int n,int mat[][MAXN],int* pre,int* next){
	return n-hungary(n,mat,next,pre);
}