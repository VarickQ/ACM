#include <cstdio>
#include <cstdlib>
#include <cstring>

const int INF = 1000000100;
const int T = 20;
const int MAXN = 150;
int mp[MAXN+1][MAXN+1];
int deg[MAXN];
struct EE {int u, v;} e[MAXN*MAXN];

int main() {
    freopen("data.in","w",stdout);
    srand(0xdead);
    int ca, n;
    for (ca = 0 ; ca < T ; ++ca) {
        memset(mp, 0, sizeof(mp));
        if (ca < T/2) n = 20;
        else n = MAXN;
        memset(deg, 0, sizeof(deg));
        int num_edge = 0;
        while (true) {
            int mind = INF, mini, i;
            for (i = 0 ; i < n ; i++)
                if (deg[i] < mind) {mind = deg[i]; mini = i;}
            if (mind >= (n+1) / 2) break;
            while (true) {
                int t = rand() % n;
                if (t == mini || mp[mini][t]) continue;
                mp[mini][t] = mp[t][mini] = 1;
                ++deg[mini]; ++deg[t];
                e[num_edge].u = mini;
                e[num_edge].v = t;
                ++num_edge;
                break;
            }
        }
        printf("%d %d\n", n, num_edge);
        for (int i = 0 ; i < num_edge ; ++i)
            printf("%d %d\n", e[i].u+1, e[i].v+1);
    }
    return 0;
}
