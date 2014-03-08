#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>

const int MAXN = 160;
int mp[MAXN][MAXN];
int ans[MAXN], n, deg[MAXN];

void rev(int L, int R) {
    while (L != R) {
        std::swap(ans[L], ans[R]);
        if (++L == n) L = 0;
        if (L == R) break;
        if (--R == -1) R = n - 1;
    }
}

int solve() {
    int i, j;
    for (i = 0 ; i < n ; i++) {
        if (mp[ans[i]][ans[(i+1)%n]] == 0) break;
    }
    if (i == n) return 0; // done
/*
    printf("position %d broken\n", i);
    for (int q = 0 ; q < n ; q++)
         printf(" %d",ans[q]);
    printf("\n");
*/
    for (j = 0 ; j < n ; j++) {
        if (j == i || j == (i+1)%n || (j+1)%n == i) continue;
        if (mp[ans[i]][ans[j]] && mp[ans[(i+1)%n]][ans[(j+1)%n]]) {
            // printf("rev(%d,%d)\n",(i+1)%n,j);
            rev((i+1)%n, j);
            return 1;
        }

    }
    assert(false);
    return 1;
}

int main() {
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int m, ca = 0;
    while (scanf("%d%d",&n,&m) != EOF) {
        memset(mp, 0, sizeof(mp));
        memset(deg, 0, sizeof(deg));
        while (m--) {
            int t1, t2;
            scanf("%d%d",&t1,&t2);
            --t1; --t2;
            assert(t1 != t2 && mp[t1][t2] == 0);
            mp[t1][t2] = mp[t2][t1] = 1;
            ++deg[t1];
            ++deg[t2];
        }
        for (int i = 0 ; i < n ; i++)
            assert(deg[i] >= (n+1) / 2);
        for (int i = 0 ; i < n ; i++)
            ans[i] = i;
        int cnt = 0;
        while (solve());
        for (int i = 0 ; i < n ; i++)
            printf("%d ",ans[i]+1);
        printf("\n");
    }
    return 0;
}
