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
#include <cassert>
using namespace std;
#define SZ(v) ((int)(v).size())
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPF(i, a, b) for (int i = (a); i <= (b); ++i)
#define REPD(i, a, b) for (int i = (a); i >= (b); --i)
const int maxint = -1u>>1;
const int maxn = 100 + 4;
const int maxm = 1000 + 5;
const double eps = 1e-8;

int sgn(double x) {
    return (x > eps) - (x < -eps);
}

struct P {
    double x, y;
    P() {}
    P(double _x, double _y): x(_x), y(_y) {}
    double cross(const P &a, const P &b) const {
        return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
    }
    void input() {
        scanf("%lf%lf", &x, &y);
        assert(sgn(fabs(x) - 100000) <= 0);
        assert(sgn(fabs(y) - 100000) <= 0);
    }
};

const P ori(0, 0);
int n, m;
P hs[maxn], gs[maxm];
int area[maxn][maxn];

int main() {
  //  freopen("data.in", "r", stdin);
   // freopen("data.out", "w", stdout);
    int ca = 0;
    while (scanf("%d%d", &n, &m) == 2) {
        printf("Case %d: ", ++ca);
        for (int i = 0; i < n; ++i) {
            hs[i].input();
        }
        for (int i = 0; i < m; ++i) {
            gs[i].input();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int cnt = 0, type = 1;
                if (sgn(ori.cross(hs[i], hs[j])) < 0) type = -1;
                for (int k = 0; k < m; ++k) {
                    double s1 = ori.cross(hs[i], gs[k]), s2 = hs[i].cross(hs[j], gs[k]), s3 = hs[j].cross(ori, gs[k]);
                    if (sgn(s1) == 0 && sgn(s2) * sgn(s3) >= 0) ++cnt;
                    else if (sgn(s3) == 0 && sgn(s1) * sgn(s2) >= 0) ++cnt;
                    else if (sgn(s1) == sgn(s2) && sgn(s2) == sgn(s3)) cnt += 2;
                }
                area[i][j] = type * cnt;
                //printf("area[%d][%d] = %d\n", i, j, area[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < j; ++k) {
                    int cnt = abs(area[i][j] + area[j][k] + area[k][i]);
                    assert(cnt % 2 == 0);
                    cnt /= 2;
                    if (cnt % 2) ++ans;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

