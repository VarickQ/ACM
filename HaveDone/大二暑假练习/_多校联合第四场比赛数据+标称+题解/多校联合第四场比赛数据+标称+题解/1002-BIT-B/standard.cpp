#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 256
#define MASK 255
#define MOD 1000000007
#define BIT(x, y) ((x) & (1 << (y)))

typedef long long i64;

using namespace std;

int id[MAX], tot;
bool vis[MAX];
i64 m[MAX][MAX], a[MAX][MAX], tmp[MAX][MAX], ans[MAX][MAX];
i64 v[MAX], rslt[MAX];

bool check(int x) {
    int i, t = x >> 1, y = 0;
    bool tag = true;

    for (i = 0; i < 7; t >>= 1, ++i) y = (y << 1) | (t & 1);
    y = (y << 1) | (x & 1);
    for (i = 0; i < 8; ++i) {
        if (!BIT(x, i)) continue;
        if (i == 7 || !BIT(x, (i + 1) & 7)) {
            tag = false;
            break;
        }
        ++i;
    }
    if (tag) return true;

    tag = true;
    for (i = 0; i < 8; ++i) {
        if (!BIT(y, i)) continue;
        if (i == 7 || !BIT(y, (i + 1) & 7)) {
            tag = false;
            break;
        }
        ++i;
    }

    return tag;
}

void matMul(i64 a[MAX][MAX], i64 b[MAX][MAX], i64 c[MAX][MAX], int n = 70) {
    int i, j, k;
    for (i = 0; i < n; ++i) fill(c[i], c[i] + n, 0);
    for (k = 0; k < n; ++k) {
        for (i = 0; i < n; ++i) {
            if (!a[i][k]) continue;
            for (j = 0; j < n; ++j) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
}

void matCpy(i64 a[MAX][MAX], const i64 b[MAX][MAX], int n = 70) {
    int i;
    for (i = 0; i < n; ++i) memcpy(a[i], b[i], n * sizeof(a[i][0]));
}

void matPow(i64 a[MAX][MAX], i64 b, i64 c[MAX][MAX], int n = 70) {
    int i;

    for (i = 0; i < n; ++i) fill(c[i], c[i] + n, 0);
    for (i = 0; i < n; ++i) c[i][i] = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            matMul(c, a, tmp, n);
            matCpy(c, tmp, n);
        }
        matMul(a, a, tmp, n);
        matCpy(a, tmp, n);
    }
}

void dfs(int x) {
    int i, c = (~x) & MASK;

    if (vis[x]) return;
    vis[x] = true;
    if (id[x] == -1) id[x] = tot++;
    for (i = 0; i < MAX; ++i) {
        if ((i & c) == c && check(x & i)) {
            if (id[i] == -1) id[i] = tot++;
            ++m[id[i]][id[x]];
            if (!vis[i]) dfs(i);
        }
    }
}

void init() {
    int i;

    memset(vis, 0, sizeof(vis));
    memset(id, -1, sizeof(id));
    tot = 0;
    dfs(255);
    ++m[0][0];
    for (i = 0; i < MAX; ++i) {
        if (~id[i] && check(i)) v[id[i]] = 1;
    }
    ++v[0];
}

i64 solve(i64 n) {
    int i, j;

    memcpy(a, m, sizeof(a));
    matPow(a, n - 1, ans);
    memset(rslt, 0, sizeof(rslt));
    for (i = 0; i < tot; ++i) {
        for (j = 0; j < tot; ++j) {
            rslt[i] = (rslt[i] + v[j] * ans[j][i]) % MOD;
        }
    }

    return rslt[0];
}

int main() {
    int t, ct = 0;
    i64 n;

    init();
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        printf("Case %d: %lld\n", ++ct, solve(n));
    }

    return 0;
}
