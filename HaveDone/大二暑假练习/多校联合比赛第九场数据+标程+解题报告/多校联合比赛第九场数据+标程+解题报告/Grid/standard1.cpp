/*
 * Author: OpenSonata
 * Created Time:  2012/8/15 20:40:48
 * File Name: yixiaohan.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 1000 + 100;
int CS, n, n1, n2, m, ans1, ans2;
int f[maxn][maxn], g[maxn][maxn];
struct node {
    int pos, num;
}a[maxn], b[maxn];

bool cmp1(node a, node b) {
    return a.pos < b.pos;
}
bool cmp2(node a, node b) {
    return a.pos > b.pos;
}

void solve() {
    sort(a + 1, a + n1 + 1, cmp1); sort(b + 1, b + n2 + 1, cmp2);
    memset(f, 127, sizeof(f)); memset(g, 127, sizeof(g));
    f[0][0] = 0;
    for (int i = 1; i <= n1; i++)
        for (int j = 0; j <= a[i].pos; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i].num) 
                f[i][j] = min(f[i][j], f[i - 1][j - a[i].num] + 1);
        }
    g[0][n + 1] = 0;
    for (int i = 1; i <= n2; i++)
        for (int j = n + 1; j >= b[i].pos; j--) {
            g[i][j] = g[i - 1][j];
            if (j + b[i].num <= n + 1) 
                g[i][j] = min(g[i][j], g[i - 1][j + b[i].num] + 1);
        }
    ans1 = 0; ans2 = maxint;
    //for (int i = 1; i <= n; i++) printf("%d %d\n", f[n1][i], g[n2][i]);
    for (int i = n; i >= 0; i--) {
        if (f[n1][i] <= maxint / 2 || g[n2][n - i + 1] <= maxint / 2) {
            //out(f[n1][i]); out(g[n2][n - i + 1]);
            ans1 = i; break;
        }
        for (int j = 1; j < i; j++)
            if (f[n1][j] <= maxint / 2 && g[n2][n - (i - j) + 1] <= maxint / 2) {
                //out(f[n1][j]); out(g[n2][n - (i - j) + 1]);
                ans1 = i; break;
            }
        if (ans1 != 0) break;
    }
    for (int i = 0; i <= ans1; i++) {
        //out(f[n1][i]); out(g[n2][n - (ans1 - i) + 1]);
        if (f[n1][i] <= maxint / 2 && g[n2][n - (ans1 - i) + 1] <= maxint / 2){
            ans2 = min(ans2, f[n1][i] + g[n2][n - (ans1 - i) + 1]);
        }
    }
    if (ans2 == maxint) ans2 = 0;
}

int main() {
    freopen("grid.in","r",stdin);
    freopen("std.out","w",stdout);
    scanf("%d", &CS);
    int cs = 0;
    while (CS--) {
        scanf("%d%d", &n, &m);
        n1 = 0; n2 = 0;
        for (int i = 0; i < m; i++) {
            int c, x, y;
            scanf("%d%d%d", &c, &x, &y);
            if (c == 1) {
                n1++;
                a[n1].pos = x; a[n1].num = y;
            }
            else {
                n2++;
                b[n2].pos = x; b[n2].num = y;
            }
        }
        solve();
        printf("Case %d: %d %d\n", ++cs, ans1, ans2);
    }
    fclose(stdout);
    return 0;
}

