#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-10
const int inf = 1000000000;
const int MAXN = 30;
#define _clr(x) memset(x,0xff,sizeof(int)*n)

int n, k, m, mat[MAXN][MAXN];
int kuhn_munkras(int m,int n,int mat[][MAXN]){
	int match1[MAXN], match2[MAXN];
	int s[MAXN],t[MAXN],l1[MAXN],l2[MAXN],p,q,ret=0,i,j,k;
	for (i=0;i<m;i++)
		for (l1[i]=-inf,j=0;j<n;j++)
			l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i];
	for (i=0;i<n;l2[i++]=0);
	for (_clr(match1),_clr(match2),i=0;i<m;i++){
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (l1[k]+l2[j]==mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
		if (match1[i]<0){
			for (i--,p=inf,k=0;k<=q;k++)
				for (j=0;j<n;j++)
					if (t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p)
						p=l1[s[k]]+l2[j]-mat[s[k]][j];
			for (j=0;j<n;l2[j]+=t[j]<0?0:p,j++);
			for (k=0;k<=q;l1[s[k++]]-=p);
		}
	}
	for (i=0;i<m;i++)
		ret+=mat[i][match1[i]];
	return ret;
}
char ch[10010];
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d", &n, &k, &m);
		for(int i=0 ; i < n ; ++i)
			scanf(" %c", &ch[i]);
		char c;
		for(int i=0 ; i < m ; ++i){
			memset( mat, 0, sizeof( mat ) );
			for(int j=0 ; j < n ; ++j){
				scanf(" %c", &c);
				mat[c-'A'][ch[j]-'A']++;
			}
			int ans = kuhn_munkras(26,26,mat);
			printf("%.4lf\n", ans*1.0/n);
		}
	}
	return 0;
}