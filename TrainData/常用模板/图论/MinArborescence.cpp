//MinArborescence.cpp
//��С����ͼ

//���Ӷ�O(n^2*m)
//3x magicpig

//�������˵����
//g��������ڽӾ���ע����������û��ֵΪ-1 
//���ı����0
//ans�Ǳ�ʾ��С����ͼ��Ȩֵ��
 
#include<stdio.h>
#include<string.h>

#define MAXN 10000
//��С����ͼ���
int g[MAXN][MAXN];
int w[MAXN][MAXN];
int p[MAXN],parent[MAXN],path[MAXN],circle[MAXN],maxmax[MAXN],map[MAXN],inv[MAXN];
int ans; //the result

bool Minimum_Arborescence(int n);//��С����ͼ��������
inline int minval(int x, int y){return x>y?y:x;}

bool Minimum_Arborescence(int n)
{
	int i,j,k,t,x,m,s;
	bool flag[MAXN],mark[MAXN];
	while(1){
		for(i=0;i<n;i++) parent[i]=i;
		s=0;
		memset(flag,0,sizeof(flag));
		memset(p,-1,sizeof(p));
		p[0]=0;
		//������, ƽ��
		for(i=1;i<n;i++)
			for(j=0;j<n;j++){
				if((k=g[j][i])==-1)continue;
				if (p[i]==-1 || k<g[ p[i] ][i]) p[i]=j;
			}
			
			for(i=1;i<n;i++)if(p[i]==-1)break;
			if(i<n)return false;
			memset(mark,0,sizeof(mark));
			mark[0]=1;
			//��Ȧ ����
			for(i=1;i<n;i++) if (!mark[i]){
				mark[i]=1;
				j=1,path[0]=i;
				k=p[i];
				while(!mark[k]){
					mark[k]=1;
					path[j++]=k;
					k=p[k];
				}
				for(t=0;t<j;t++) if (path[t]==k) break; 
				if (t==j) continue;
				circle[s++]=k,flag[k]=1;
				for(t++;t<j;t++){
					ans += g[ path[t] ][ path[t-1] ];
					parent[path[t]]=k; //��¼
				}
				ans += g[ k ][ path[j-1] ];
			}
			if (s>0){
				memset(maxmax,0,sizeof(maxmax));
				//��Ȧ�����
				for(i=0;i<n;i++){
					j=parent[i];
					if (flag[j]&&(k=g[ p[i] ][i])>maxmax[j]) maxmax[j]=k;
				}
				//��¼��
				for(m=0,i=0;i<n;i++) if (!flag[parent[i]]) inv[i]=m,map[m++]=i;
				for(x=m,i=0;i<s;i++) inv[circle[i]]=m,map[m++]=circle[i], ans -= maxmax[ circle[i] ];
				//�޸ı�
				for(i=0;i<n;i++)
					for(j=0;j<n;j++){
						w[i][j]=g[i][j];
						if (w[i][j]==-1) continue;
						if (flag[parent[j]]&&parent[i]!=parent[j]){
							w[i][j]+=maxmax[parent[j]]-g[p[j]][j];
							
						}
					}
					for(i=0;i<m;i++)
						for(j=0;j<m;j++)
							g[i][j]=w[map[i]][map[j]];
						
						for(i=0;i<n;i++)
							for(j=0;j<n;j++)if(w[i][j]!=-1){
								k=inv[ parent[i] ],t=inv[ parent[j] ];
								if (k!=t&&(w[i][j]<g[k][t] || g[k][t] == -1)) g[k][t]=w[i][j];
							}
							n = m;
			}
			else {
				for(i=1;i<n;i++)
                    ans+=g[p[i]][i];
				return true;
			}
	}
}

int main()
{
    int i,j,n,m,a,b,c;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            g[i][j]=-1;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=c;
    }    
    Minimum_Arborescence(n);
    printf("%d\n",ans);
    int cici;
    scanf("%d",&cici);
    return 0;
}

/*
5 8
0 1 3
0 2 5
1 3 2
2 0 5
2 1 4
2 3 6
2 4 7
4 3 3
*/
