#pragma comment(linker, "/STACK:102400000,102400000")

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>

using namespace std;

#define MAXN 200010
#define MAXM 600010

struct Edge {
	int v;
	Edge *link;
} edge[MAXM], *adj[MAXN];

int totE;

void addEdge(int u, int v) {
	Edge *p = &edge[totE++];
	p->v = v;
	p->link = adj[u];
	adj[u] = p;
}

struct BCCEdge {
	int u, v;
} bccEdge[MAXM];

bool cmp(BCCEdge b1, BCCEdge b2) {
	if (b1.u != b2.u)
		return b1.u < b2.u;
	return b1.v < b2.v;
}

int totBCCE;
int timeStamp, top, top1, root, comp, cut, block;
int dfn[MAXN], lowlink[MAXN], label[MAXN], cluster[MAXN], dep[MAXN],
		fa[MAXN][19];
int st1[MAXM], st2[MAXM], st3[MAXM], st4[MAXM], num[MAXN], points[MAXN],
		flag[MAXN];
bool isCut[MAXN], island[MAXN];

void solve() {
	flag[comp] = 1;
	for (int i = 0; i < top1; ++i) {
		int u = st3[i], v = st4[i];
		if (isCut[u])
			bccEdge[totBCCE].u = label[u], bccEdge[totBCCE++].v = comp;
		else
			label[u] = comp;
		if (isCut[v])
			bccEdge[totBCCE].u = label[v], bccEdge[totBCCE++].v = comp;
		else
			label[v] = comp;
	}
	++comp;
}

void dfs(int u) {
	dfn[u] = lowlink[u] = ++timeStamp;
	isCut[u] = false;
	int d = 0;
	Edge *p = adj[u];
	while (p) {
		if (!dfn[p->v]) {
			++d;
			dfs(p->v);
			lowlink[u] = min(lowlink[u], lowlink[p->v]);
			if (lowlink[p->v] >= dfn[u])
				isCut[u] = true;
		} else
			lowlink[u] = min(lowlink[u], dfn[p->v]);
		p = p->link;
	}
	if (isCut[u] && u == root && d == 1)
		isCut[u] = false;
}

void tarjan(int u) {
	cluster[u] = block;
	dfn[u] = lowlink[u] = ++timeStamp;
	Edge *p = adj[u];
	if (!p) {
		island[u] = true;
		return;
	}
	island[u] = false;
	while (p) {
		if (!dfn[p->v]) {
			st1[top] = u;
			st2[top++] = p->v;
			tarjan(p->v);
			lowlink[u] = min(lowlink[u], lowlink[p->v]);
			if (lowlink[p->v] >= dfn[u]) {
				top1 = 0;
				while (true) {
					st3[top1] = st1[--top];
					st4[top1++] = st2[top];
					if (st1[top] == u && st2[top] == p->v)
						break;
				}
				solve();
			}
		} else {
			if (dfn[u] > dfn[p->v]) {
				st1[top] = u;
				st2[top++] = p->v;
			}
			lowlink[u] = min(lowlink[u], dfn[p->v]);
		}
		p = p->link;
	}
}

void solve(int u, int cnt, int depth) {
	dep[u] = depth;
	dfn[u] = 1;
	points[u] = cnt + num[u];
	Edge *p = adj[u];
	while (p) {
		if (!dfn[p->v]) {
			fa[p->v][0] = u;
			solve(p->v, points[u], depth + 1);
		}
		p = p->link;
	}
}

int LCA(int u, int v) {
	if (dep[u] > dep[v])
		swap(u, v);
	for (int i = 0, diff = dep[v] - dep[u]; diff; diff >>= 1, ++i)
		if (diff & 1)
			v = fa[v][i];
	if (u == v)
		return u;

	int res = u;
	for (int i = 18; i >= 0; --i) {
		if (fa[u][i] == fa[v][i])
			res = fa[u][i];
		else {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return res;
}

int main() {
//	int t1 = clock();
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int n, m, cas = 1;
	while (scanf("%d%d", &n, &m) != EOF) {
		totE = 0;
		memset(adj, NULL, sizeof(adj));
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v);
			addEdge(v, u);
		}

		timeStamp = 0;
		memset(dfn, 0, sizeof(dfn));
		memset(isCut, false, sizeof(isCut));

		for (int i = 0; i < n; ++i)
			if (!dfn[i]) {
				root = i;
				dfs(i);
			}

		comp = 0;
		for (int i = 0; i < n; ++i)
			if (isCut[i]) {
				flag[comp] = 0;
				label[i] = comp++;
			}
		cut = comp;

		timeStamp = top = block = totBCCE = 0;
		memset(dfn, 0, sizeof(dfn));
		for (int i = 0; i < n; ++i)
			if (!dfn[i]) {
				root = i;
				tarjan(i);
				++block;
			}

		totE = 0;
		memset(adj, NULL, sizeof(adj));
		sort(bccEdge, bccEdge + totBCCE, cmp);
		memset(num, 0, sizeof(num));

		for (int i = 0; i < n; ++i)
			if (!island[i] && !isCut[i])
				++num[label[i]];

		if (totBCCE > 0) {
			int u = bccEdge[0].u, v = bccEdge[0].v;
			addEdge(u, v);
			addEdge(v, u);
			if (!flag[u])
				++num[v];
		}
		for (int i = 1; i < totBCCE; ++i) {
			int u = bccEdge[i].u, v = bccEdge[i].v;
			if (u != bccEdge[i - 1].u || v != bccEdge[i - 1].v) {
				addEdge(u, v);
				addEdge(v, u);
				if (!flag[u])
					++num[v];
			}
		}

		memset(dfn, 0, sizeof(dfn));
		for (int i = 0; i < comp; ++i)
			fa[i][0] = -1;
		for (int i = 0; i < comp; ++i)
			if (!dfn[i])
				solve(i, 0, 0);
		for (int l = 1; l <= 18; ++l)
			for (int i = 0; i < comp; ++i)
				if (fa[i][l - 1] != -1)
					fa[i][l] = fa[fa[i][l - 1]][l - 1];
				else
					fa[i][l] = -1;

		int q;
		scanf("%d", &q);
		printf("Case #%d:\n", cas++);
		for (int i = 0; i < q; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			if(u == v)
				printf("%d\n", n - 1);
			else if (island[u] || island[v] || cluster[u] != cluster[v])
				printf("%d\n", n);
			else {
				u = label[u], v = label[v];
				int lca = LCA(u, v);
				int res = points[u] + points[v] - points[lca];
				if (fa[lca][0] != -1)
					res -= points[fa[lca][0]];
				int nodeInTree = dep[u] + dep[v] - 2 * dep[lca] + 1;

				if (nodeInTree % 2 == 0)
					res -= nodeInTree / 2 - 1;
				else if (flag[u] == 0)
					res -= nodeInTree / 2 - 1;
				else
					res -= nodeInTree / 2;
				printf("%d\n", n - res);
			}
		}
		puts("");
	}
//	int t2 = clock();
//	printf("%d\n", t2 - t1);
	return 0;
}
