#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxint = 0x7FFFFFFF;

int count_one(int x) {
    int cnt = 0;
    while (x) {
        if (x&1) ++cnt;
        x >>= 1;
    }
    return cnt;
}
int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);
    int t, ca = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case %d: ", ++ca);
        int n, ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            ans += count_one(x) - 1;
        }
        if (ans&1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

