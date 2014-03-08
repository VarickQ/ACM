#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPF(i, a, b) for (int i = (a); i <= (b); ++i)
#define REPD(i, a, b) for (int i = (a); i >= (b); --i)
const int maxint = -1u>>1;
const int maxn = 100 + 4;
const int maxm = 1000 + 5;
const double eps = 1e-8;

struct P {
    double x, y;
    P() {}
    P(double _x, double _y): x(_x), y(_y) {}
    double cross(const P &a, const P &b) const {
        return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
};

const P ori(0, 0);
int n, m;
P hs[maxn], gs[maxm];
int area[maxn][maxn];

int sgn(double x) {
    return (x > eps) - (x < -eps);
}

int main() {
    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    int ca = 0;
    while (scanf("%d%d", &n, &m) == 2) {
        printf("Case %d: ", ++ca);
        for (int i = 0; i < n; ++i) {
            hs[i].input();
        }
        for (int i = 0; i < m; ++i) {
            gs[i].input();
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < j; ++k) {
                    int cnt = 0;
                    for (int c = 0; c < m; ++c) {
                        double s1 = hs[i].cross(hs[j], gs[c]);
                        double s2 = hs[j].cross(hs[k], gs[c]);
                        double s3 = hs[k].cross(hs[i], gs[c]);
                        if (sgn(s1) == sgn(s2) && sgn(s2) == sgn(s3) && sgn(s3) == sgn(s1)) ++cnt;
                    }
                    if (cnt % 2) ++ans;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

