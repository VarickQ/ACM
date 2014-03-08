//二分图最大匹配,hungary算法,邻接表形式,邻接阵接口,复杂度O(m*e)s
//返回最大匹配数,传入二分图大小m,n和邻接阵
//match1,match2返回一个最大匹配,未匹配顶点match值为-1

#include <string.h>
#include <vector>
#define MAXN 310
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k,r;
	vector<int> e[MAXN];
	//生成邻接表(只需一边)
	for(i=0;i<m;++i)
		for(j=0;j<n;++j)
			if (mat[i][j]) e[i].push_back(j);
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for(r=0,k=s[p];r<e[k].size()&&match1[i]<0;++r)
				if (t[j=e[k][r]]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}