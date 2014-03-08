#include<iostream>
using namespace std;
#include<algorithm>
#include<string.h>
const __int64 inf=200000000000;
#define N 5010
#define M 1000010
struct edge
{
	__int64 from,to,val,next;
}e[M];
__int64 w[N],que[N],dis[N],edge,cur[N];
void add(__int64 from,__int64 to,__int64 va)
{
    e[edge].from=from;
	e[edge].to=to;
	e[edge].val=va;
    e[edge].next=w[from];
	w[from]=edge++;

    e[edge].from=to;
	e[edge].to=from;
	e[edge].val=0;
    e[edge].next=w[to];
	w[to]=edge++;
}
__int64 bfs(__int64 n,__int64 s,__int64 t)
{
    __int64 head,tail,id;
    head=tail=0;que[tail++]=s;
    memset(dis,-1,sizeof(__int64)*n);
	dis[s]=0;
	while(head<tail) // bfs,得到顶点i的距s的最短距离dis[i]
	{
		for(id=w[que[head++]];id!=-1;id=e[id].next)
			if(e[id].val>0&&dis[e[id].to]==-1)
            {
				dis[e[id].to]=dis[e[id].from]+1;
                que[tail++]=e[id].to;
                if(e[id].to==t) return 1;
            }
	}
    return 0;
}
__int64 Dinic(__int64 n,__int64 s,__int64 t)
{
    __int64 Mflow=0,tmp,i;
    while(bfs(n,s,t))
    {
        __int64 u=s,tail=0;
        for(i=0;i<n;i++) cur[i]=w[i];
        while(cur[s]!=-1)
        {
			if(u!=t&&cur[u]!=-1&&e[cur[u]].val>0&&dis[u]!=-1&&dis[u]+1==dis[e[cur[u]].to])
            {
				que[tail++]=cur[u];
				u=e[cur[u]].to;
			}
            else if(u==t)
            {
                for(tmp=inf,i=tail-1;i>=0;i--)
					tmp=min(tmp,e[que[i]].val);
                for(Mflow+=tmp,i=tail-1;i>=0;i--)
                {
                    e[que[i]].val-=tmp;
                    e[que[i]^1].val+=tmp;
                    if(e[que[i]].val==0) tail=i;
                }
                u=e[que[tail]].from;
            }
            else
            {
                while(tail>0&&u!=s&&cur[u]==-1) u=e[que[--tail]].from;
                cur[u]=e[cur[u]].next;
            }
		}
    }
    return Mflow;
}
__int64 use[110][35];
__int64 a[110][35],b[110][35],c[110][35],m[N],d1[110][35][55],d2[110][35][55];
int main()
{
	__int64 T,ans,k,cs=0,n,s,t;
	scanf("%I64d",&T);
	while(T--)
	{
		memset(w,-1,sizeof(w));
		edge=0;
		ans=0;
		s=0;t=1;
		k=2;
		scanf("%I64d",&n);
		for(__int64 i=1;i<=n;++i){
			scanf("%I64d",&m[i]);
			for(__int64 j=1;j<=m[i];++j){
				use[i][j]=k++;
				scanf("%I64d%I64d%I64d",&a[i][j],&b[i][j],&c[i][j]);
				for(__int64 k=0;k<c[i][j];++k)
					scanf("%I64d%I64d",&d1[i][j][k],&d2[i][j][k]);
			}
		}
		for(__int64 i=1;i<=n;++i)
		{
			for(__int64 j=1;j<=m[i];++j){
				a[i][j]=b[i][j]-a[i][j];
				if(a[i][j]>0){
					add(s,use[i][j],a[i][j]);
					ans+=a[i][j];
				}
				else add(use[i][j],t,-a[i][j]);
				for(__int64 k=0;k<c[i][j];++k){
					add(use[i][j],use[d1[i][j][k]][d2[i][j][k]],inf);
				}
			}
		}
		printf("Case #%I64d: %I64d\n",++cs,ans-Dinic(k,s,t));
	}
	return 0;
}