#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 1010
#define LL(x) ((x) << 1)
#define RR(x) (((x) << 1) | 1)
#define LB(x) ((x) & -(x))

using namespace std;

struct BIT {
    int c[MAX << 2], sz;

    void init(int n) {
        memset(c, 0, sizeof(c));
        sz = n;
    }

    void update(int x, int v) {
        int i;
        for (i = x; i <= sz; i += LB(i)) c[i] += v;
    }

    int query(int x) {
        int i, ret = 0;
        for (i = x; i; i -= LB(i)) ret += c[i];
        return ret;
    }
} bit;

struct Point {
    int x, id;
    bool isLeft;

    bool operator <(const Point &p) const {
        return x == p.x ? p.isLeft : x < p.x;
    }
} p[MAX << 1];

int mat[MAX][MAX], l[MAX][MAX], r[MAX][MAX], u[MAX][MAX], d[MAX][MAX];
int a[MAX << 1], q[MAX << 1];

void init(int n) {
    int i, j;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            l[i][j] = mat[i][j] ? (j ? l[i][j - 1] + 1 : 1) : 0;
            u[i][j] = mat[i][j] ? (i ? u[i - 1][j] + 1 : 1) : 0;
        }
    }
    for (i = n - 1; ~i; --i) {
        for (j = n - 1; ~j; --j) {
            r[i][j] = mat[i][j] ? (j == n - 1 ? 1 : r[i][j + 1] + 1) : 0;
            d[i][j] = mat[i][j] ? (i == n - 1 ? 1 : d[i + 1][j] + 1) : 0;
        }
    }
}

int count(int n, int m) {
    int i, j, ret = 0;

    bit.init(2 * n);
    sort(p, p + 2 * m);
    for (i = 0; i < 2 * m; ++i) {
        if (p[i].isLeft) ret -= bit.query(q[p[i].id]);
        else ret += bit.query(q[p[i].id]);
        for (j = p[i].x; i < 2 * m - 1 && j < p[i + 1].x; ++j) bit.update(a[j], 1);
    }

    return ret;
}

int solve(int n) {
    int i, j, x, y, m, ll, rr, ret = 0;

    for (i = n - 1; i >= 1 - n; --i) {
        ll = max(0, -i); rr = min(n, n - i);
        m = 0;
        for (j = ll; j < rr; ++j) {
            x = i + j; y = j;
            a[j - ll] = j - ll - min(l[x][y], u[x][y]) + 1 + n;
            if (mat[i + j][j]) {
                p[LL(m)].x = j - ll; p[LL(m)].id = m; p[LL(m)].isLeft = true;
                p[RR(m)].x = j - ll + min(r[x][y], d[x][y]); p[RR(m)].id = m; p[RR(m)].isLeft = false;
                q[m++] = j - ll + n;
            }
        }
        ret += count(n, m);
    }

    return ret;
}

int main() {
    int t, ct = 0, n, i, j;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                scanf("%d", &mat[i][j]);
            }
        }
        init(n);
        printf("Case %d: %d\n", ++ct, solve(n));
    }

    return 0;
}
