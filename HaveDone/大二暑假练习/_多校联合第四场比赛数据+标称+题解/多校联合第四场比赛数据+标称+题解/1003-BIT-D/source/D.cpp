#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX 200010

using namespace std;

char x[MAX];
int next[MAX];

void getNext(const char *p, int *next) {
    int l = 1, r = -1, i, j;

    for (next[0] = 0, i = 1; p[i]; ++i) {
        if (i + next[i - l] - 1 < r) next[i] = next[i - l];
        else {
            for (j = max(r - i + 1, 0); p[i + j] && p[i + j] == p[j]; ++j);
            next[i] = j; l = i; r = i + j - 1;
        }
    }
    next[0] = i;
}

int main() {
    int t, ct = 0, n, up, i, l, e, g;

    scanf("%d", &t);
    while (t--) {
        scanf("%s", x);
        n = strlen(x);
        for (i = 0; i < n; ++i) x[i + n] = x[i];
        x[2 * n] = 0;
        getNext(x, next);
        for (i = 1; i < n && i + next[i] < n; ++i);
        up = n % i ? n : i;
        l = e = g = 0;
        for (i = 0; i < up; ++i) {
            if (next[i] >= n) ++e;
            else if (x[i + next[i]] < x[next[i]]) ++l;
            else ++g;
        }
        printf("Case %d: %d %d %d\n", ++ct, l, e, g);
    }

    return 0;
}
