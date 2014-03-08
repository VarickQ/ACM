#include <stdio.h>
#include <string.h>
const int maxn=201000;
const int maxm=4*maxn;

int id[maxn],low[maxn],stack[maxn];
bool visit[maxn],flag[maxn],cut[maxn],bridge[maxm],visite[maxm];
int cnt,box[maxn],trcnt,trbox[maxn];
struct edge{
    int to,next;
} e[maxm],tre[maxm];

int we[maxn],st[maxn],de[maxn];
int usen,n,m,root,top,Bei;

int fa[maxn][20],sum[maxn],dep[maxn];

void ckmin(int &x,int y)
{
    if (x>y) x=y;
}

void add(int u,int v)
{
    e[cnt].to=v;e[cnt].next=box[u];box[u]=cnt++;
}

void tradds(int u,int v)
{
    tre[trcnt].to=v;
    tre[trcnt].next=trbox[u];
    trbox[u]=trcnt++;
}

void tradd(int u,int v)
{
    tradds(u,v);
    tradds(v,u);
}

void dfs1(int u,int fa,int time)
{
    int num=0,first=0;

    id[u]=low[u]=++time;
    visit[u]=1;
    for(int p=box[u];p!=-1;p=e[p].next)
    {
        int v=e[p].to;

        if (v==fa)
        {
            first++;
            if (first==1) continue;
        }
        if (!visit[v])
        {
            num++;
            dfs1(v,u,time);
            ckmin(low[u],low[v]);
            if (low[v]==id[v]&&u!=root)
                cut[u]=1;
            if (id[u]==low[v]&&u!=root)
                cut[u]=1;
        } else
        {
            ckmin(low[u],id[v]);
        }
        if (id[u]<low[v])
        {
            bridge[p]=1;
        }
    }
    if (u!=root&&id[u]==low[u])
        cut[u]=1;
    if (u==root&&num>1) cut[u]=1;
}

void precut()
{
    memset(visit,0,sizeof(visit));
    memset(visite,0,sizeof(visite));
    memset(bridge,0,sizeof(bridge));
    memset(cut,0,sizeof(cut));
    for(int i=0;i<n;i++)
     if (!visit[i])
     {
         root=i;
         dfs1(i,-1,0);
     }
    memset(de,0,sizeof(de));
    for(int i=0;i<cnt;i++)
        de[e[i].to]++;
    for(int i=0;i<n;i++)
        if (de[i]==1) cut[i]=1;
}

void dfs2(int u,int fa,int time)
{
    int num=0,first=0;

    id[u]=low[u]=++time;
    visit[u]=1;
    for(int p=box[u];p!=-1;p=e[p].next)
    {
        int v=e[p].to;
        if (visite[p]) continue;
        visite[p]=visite[p^1]=1;

        stack[top++]=p;
        if (!visit[v])
        {
            num++;
            dfs2(v,u,time);
            ckmin(low[u],low[v]);
        } else
        {
            ckmin(low[u],id[v]);
        }
        if (id[u]<=low[v])
        {
            if (id[u]<low[v])
            {
                top--;
                continue;
            }
            int nume=0;
            we[usen]=0;
            do
            {
                top--;
                v=e[ stack[top] ].to;
                nume++;
                if (!flag[v])
                {
                    we[usen]++;
                    if (cut[ v ])
                    {
                        we[st[v]]=-1;
                        tradd(usen,st[v]);
                    } else
                        st[v]=usen;
                }
                flag[v]=1;
            } while(stack[top]!=p);
            for(int i=top;i<=top+nume;i++)
                flag[e[stack[i]].to]=0;

            usen++;
        }
    }
}

void pretree()
{
    trcnt=0;
    memset(trbox,-1,sizeof(trbox));
    memset(visit,0,sizeof(visit));
    memset(visite,0,sizeof(visite));
    memset(flag,0,sizeof(flag));
    memset(st,-1,sizeof(st));
    usen=1;we[0]=0;
    for(int i=0;i<n;i++)
     if (cut[i])
     {
         we[usen]=1;
         st[i]=usen++;
     }
    top=0;
    for(int i=0;i<n;i++)
     if (!visit[i])
     {
         root=i;
         dfs2(i,-1,0);
         if (st[i]==-1)
         {
             we[usen]=1;
             st[i]=usen++;
         }
         tradd(0,st[i]);
     }
}

void prebridge()
{
    //printf("usen=%d \n",usen);
    for(int i=0;i<cnt;i++)
     if (bridge[i])
     {
         int u=e[i].to;
         int v=e[i^1].to;
         if (we[st[u]]==-1&&we[st[v]]==-1)
         {
             tradd(st[u],usen);
             tradd(st[v],usen);
             we[usen]=2;
             usen++;
         } else
         if (we[st[u]]+we[st[v]]==0)
         {
             tradd(st[u],usen);
             tradd(st[v],usen);
             we[usen]=1;
             usen++;
         } else
         {
             tradd(st[u],st[v]);
         }
     }
}

void dfs3(int u,int fas,int deps)
{
    if (fas==-1)
    {
        for(int i=0;i<=Bei;i++)
            fa[u][i]=u;
        sum[u]=we[u];
    } else
    {
        fa[u][0]=fas;
        for(int i=1;i<=Bei;i++)
            fa[u][i]=fa[ fa[u][i-1] ][i-1];
        sum[u]=sum[fas]+we[u];
    }
    dep[u]=deps;
    for(int p=trbox[u];p!=-1;p=tre[p].next)
        if (tre[p].to!=fas)
            dfs3(tre[p].to,u,deps+1);
}

int lca(int u,int v)
{
    int t=dep[u]-dep[v];
    int *x=&u;
    if (dep[u]<dep[v])
    {
        t=dep[v]-dep[u];
        x=&v;
    }
    int k=0;
    while(t)
    {
        if (t&1)
        {
            *x=fa[*x][k];
        }
        t>>=1;
        k++;
    }
    if (u==v) return u;
    for(int i=Bei;i>=0;i--)
     if (fa[u][i]!=fa[v][i])
     {
         u=fa[u][i];
         v=fa[v][i];
     }
    return fa[u][0];
}

void prelca()
{
    dfs3(0,-1,0);
}


void debug()
{
    for(int i=0;i<n;i++)
     printf("%d ",cut[i]);puts("cut");
    for(int i=0;i<cnt;i++)
     printf("%d ",bridge[i]);puts("bridge");
    for(int i=0;i<n;i++)
     printf("%d ",st[i]);puts("st");
    for(int i=0;i<usen;i++)
     printf("%d ",we[i]);puts("we");
}

int main()
{
    int cas=0,u,v;
    int S,T;

    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    Bei=18;
    while(scanf("%d%d",&n,&m)==2)
    {
        //scanf("%d%d",&S,&T);
        cnt=0;
        memset(box,-1,sizeof(box));
        while(m--)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        precut();
        pretree();
        prebridge();
        prelca();
        //debug();

        printf("Case #%d:\n",++cas);
        int q;
        u=S;v=T;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&u,&v);
            int ans;
            if (u==v) ans=n-1;
            else
            {
                u=st[u];v=st[v];
                int t=lca(u,v);
               // printf("u=%d v=%d t=%d\n",u,v,t);
                if (t==0) ans=n;
                else
                {
                    ans=sum[u]+sum[v]-2*sum[t]+we[t];
                    if (we[u]==-1) ans++;
                    if (we[v]==-1) ans++;
                    ans=n-ans;
                }
            }
            printf("%d\n",ans);
        }
        puts("");
    }
    return 0;
}
