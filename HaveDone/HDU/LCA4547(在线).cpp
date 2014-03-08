#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int N = 100100;

/*===========================================*\
 * RMQ_LCA �㷨 (�����㷨)
 * ���Ӷ� O(NlogN + Q)
 * �÷������main()
\*===========================================*/
typedef int LL;
const int MAXN = 400005;
const int MAXM = 2000005;
int Ncnt; // ʱ���(���������ܽڵ���)
struct Edge
{
    int v, next;
    LL len;
}edge[MAXM];
int NE, head[MAXN];
int vis[MAXN];
int deep[MAXN<<1]; // deep[i] ��ʾiʱ�����ڽڵ�����
int node[MAXN<<1]; // node[i] ��ʾiʱ�����ڵĽڵ�
int dnf[MAXN];     // dnf[i]  ��ʾu�ڵ��ʱ���(������ʲôʱ���ѵ�)
LL dis[MAXN];      // �Ӹ��ڵ㵽�õ�ľ���
inline void init(){
    NE = 0;
    memset(head, -1, sizeof(head));
}
inline void addedge(int u, int v, LL w){
    edge[NE].v = v;
    edge[NE].len = w;
    edge[NE].next = head[u];
    head[u] = NE++;
}
void dfs(int u, int fa, int dep, int len)
{
    node[++Ncnt] = u;
    deep[Ncnt] = dep;
    if (dnf[u] == -1)
    {
        dnf[u] = Ncnt;
        dis[u] = len;
    }
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != fa)
        {
            dfs(v, u, dep + 1, len + edge[i].len);
            node[++Ncnt] = u;
            deep[Ncnt] = dep;
        }
    }
}
int H[MAXN<<1][20]; // �����ʱ���
void RMQ(int N)
{
    for (int i = 1; i <= N; ++i)
        H[i][0] = i;
    for (int j = 1; (1<<j) <= N; ++j)
        for (int i = 0; i + (1<<j) -1 < N; ++i)
        {
            if (deep[ H[i][j-1] ] > deep[ H[i+(1<<(j-1))][j-1] ])
                H[i][j] = H[i+(1<<(j-1))][j-1];
            else
                H[i][j] = H[i][j-1];
        }
}
int LCA(int u, int v)
{
    int ancestor; // �����������
    // u,v��ʱ���[l, r]
    int l = dnf[u], r = dnf[v];
    if (l > r) swap(l, r);
    // �����͵��Ǹ�ʱ��� ���ڵĽڵ����LCA
    int k = int( log(r - l + 1.0) / log(2.0) );
    int t1 = H[l][k], t2 = H[r - (1<<k) + 1][k];
    if (deep[t1] < deep[t2])
        ancestor = node[t1];
    else
        ancestor = node[t2];
    return ancestor;
}
/*===========================================*/
char s1[105], s2[105];
map<string,int> ma;
int main(){
    int T, n, m;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        init();
        memset ( vis, 0, sizeof ( vis ) );
        scanf("%d%d", &n, &m);
        ma.clear();
        int a, b, c, cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%s%s", s1, s2);
            if (ma.find(s1) == ma.end())
                ma[s1] = ++cnt;
            if (ma.find(s2) == ma.end())
                ma[s2] = ++cnt;
            a = ma[s1];
            b = ma[s2];
            addedge( a, b, 1 );
            addedge( b, a, 1 );
            vis[a]++;
        }
        int root = 1;
        for ( ; root <= n; ++root)
            if (vis[root] == 0) break;
        memset ( vis, 0, sizeof ( vis ) );
        memset( dnf, -1, sizeof ( dnf ) );
        Ncnt = 0;
        dfs( root, -1, 0, 0 );
        RMQ( Ncnt );
        for (int i = 0; i < m; ++i) {
            scanf("%s%s", s1, s2);
            a = ma[s1];
            b = ma[s2];
            int c = LCA( a, b );
            int ans = dis[a] - dis[c];
            if (c != b) ans++;
            printf("%d\n", ans);
        }
    }
    return 0;
}