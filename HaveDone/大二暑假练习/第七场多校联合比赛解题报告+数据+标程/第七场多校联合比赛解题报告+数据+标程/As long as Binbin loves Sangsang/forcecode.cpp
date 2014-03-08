#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
#define N 1315*4
#define ll __int64
const __int64 inf = 1000000000000000LL;
ll c[N][N];
ll d[N];
int p[N];
ll Dijkstra(int n, int s, int t) {
	int j, i, q[N], best_i, u;
	int top = n;
	for (i = 0; i < n; ++i) {
		d[i] = inf, q[i] = i;
		p[i] = 0;
	}
	d[s] = 0;
	for (i = 0; i < n; ++i) {
		best_i = 0;
		for (j = 0; j < top; ++j)
			if (d[q[j]] < d[q[best_i]])
				best_i = j;
		u = q[best_i];
		if (u == t)
			return d[t];
		q[best_i] = q[--top];
		for (j = 0; j < top; ++j) {
			if (d[q[j]] > c[u][q[j]] + d[u]) {
				d[q[j]] = c[u][q[j]] + d[u];
				p[q[j]] = p[u] + 1;
			} else if (d[q[j]] == c[u][q[j]] + d[u] && (p[q[j]] < p[u] + 1))
				p[q[j]] = p[u] + 1;
		}
	}
	return d[t];
}
int main() {
	freopen("data.in", "r", stdin);
	freopen("forcedata.out", "w", stdout);
	int t, x, y, cas = 0;
	ll v;
	int n, m, i, j;
	char s[10];
	scanf("%d", &t);
	while (t--) {
		cas++;
		scanf("%d%d", &n, &m);
		n *= 4;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j)
				c[i][j] = inf;
		}
		while (m--) {
			scanf("%d%d%I64d%s", &x, &y, &v, s);
			x--;
			y--;
			x *= 4;
			y *= 4;
			if (s[0] == 'L') {
				c[x][y + 1] = min(v, c[x][y + 1]);
				c[y][x + 1] = min(v, c[y][x + 1]);
			} else if (s[0] == 'O') {
				c[x + 1][y + 2] = min(v, c[x + 1][y + 2]);
				c[y + 1][x + 2] = min(v, c[y + 1][x + 2]);
			} else if (s[0] == 'V') {
				c[x + 2][y + 3] = min(v, c[x + 2][y + 3]);
				c[y + 2][x + 3] = min(v, c[y + 2][x + 3]);
			} else if (s[0] == 'E') {
				c[x + 3][y] = min(v, c[x + 3][y]);
				c[y + 3][x] = min(v, c[y + 3][x]);
			}
		}
		if (n == 4) {
			if (c[0][1] != inf && c[1][2] != inf && c[2][3] != inf && c[3][0]
					!= inf)
				printf(
						"Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",
						cas, c[0][1] + c[1][2] + c[2][3] + c[3][0], 1);
			else
				printf(
						"Case %d: Binbin you disappoint Sangsang again, damn it!\n",
						cas);
			continue;
		}

		Dijkstra(n, 0, n - 4);
		if (d[n - 4] == inf)
			printf("Case %d: Binbin you disappoint Sangsang again, damn it!\n",
					cas);
		else
			printf(
					"Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",
					cas, d[n - 4], p[n - 4] / 4);
	}
	return 0;
}
