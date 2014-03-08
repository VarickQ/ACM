#include <cstdio>
#include <cassert>

const int MAXN = 20;
double p[MAXN];

int main() {
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int n;
    while (scanf("%d",&n) != EOF) {
        assert(n >= 1 && n <= 20);
        double tot_p = .0;
        for (int i = 0 ; i < n ; i++) {
            scanf("%lf",&p[i]);
            assert(p[i] > 0);
            tot_p += p[i];
        }
        assert(tot_p <= 1.0);
        double ans = .0;
        for (int mask = 1 ; mask < (1<<n) ; ++mask) {
            double tmp = .0;
            int cnt = 0;
            for (int i = 0 ; i < n ; i++)
                if (mask & (1<<i)) {
                    tmp += p[i];
                    ++cnt;
                }
            if (cnt & 1) ans += 1 / tmp;
            else ans -= 1 / tmp;
        }
        printf("%.6lf\n", ans);
    }
    return 0;
}
