#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int N = 100005;
typedef long long ll;

/*===========================================*\
 * RMQ_LCA �㷨 (�����㷨)
 * ���Ӷ� O(NlogN + Q)
 * �÷������main()
\*===========================================*/
typedef int LL;
const int MAXN = 400005;
const int MAXM = 2000005;
int n,Ncnt; // ʱ���(���������ܽڵ���)
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
void mark(int u) // ��ͨ��Ⱦɫ(Ϊ�˰�ɭ�ֻ�Ϊ��)
{
    vis[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (!vis[v])
            mark(v);
    }
}
void dfs(int u, int fa, int dep, int len)
{
    if (dnf[u] == -1)
    {
        dnf[u] = Ncnt;
        dis[u] = len;
    }
    node[Ncnt] = u;
    deep[Ncnt++] = dep;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != fa)
        {
            dfs(v, u, dep + 1, len + edge[i].len);
            node[Ncnt] = u;
            deep[Ncnt++] = dep;
        }
    }
}
int H[MAXN<<1][20]; // �����ʱ���
void RMQ(int N)
{
    for (int i = 0; i <= N; ++i)
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
void initTree(){
	int root = 0;
	CLR( vis, 0 );
	for(int i=1 ; i <= n ; ++i){
		if( !vis[i] ){
			mark(i);
			addedge( root, i, 0 );
			addedge( i, root, 0 );
		}
	}
	CLR( vis, 0 );
	CLR( dnf, -1 );
	Ncnt = 0;
	dfs( root, -1, 0, 0 );
	RMQ( Ncnt );
}
/*===========================================*/

int main(){
	int m,q;
	while( scanf("%d%d", &n, &m) != EOF ){
		int a,b,c;
		char ch[5];
		init();
		while( m-- ){
			scanf("%d%d%d%s", &a, &b, &c, ch);
			addedge( a, b, c );
			addedge( b, a, c );
		}
		initTree();
		scanf("%d", &q);
		while( q-- ){
			scanf("%d%d", &a, &b);
			c = LCA( a, b );
			printf("%d\n", dis[a]+dis[b]-2*dis[c]);
		}
	}
	return 0;
}