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

int n, k;
int main() {
  //  freopen("data.in", "r", stdin);
   // freopen("data.out", "w", stdout);
    int ca = 0;
    while (scanf("%d%d", &n, &k) == 2) {
        printf("Case %d: ", ++ca);
        if (k == 1 && n % 2 == 1) {
            printf("Bob\n");
        } else if (n / 2 > k) {
            printf("Alice 1\n");
        } else {
            printf("Alice %d\n", k);
        }
    }
    return 0;
}

