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
const double pi = acos(-1.);
const double eps = 1e-8;

int sgn(double x) {
    return (x > eps) - (x < -eps);
}

struct P {
    double x, y;
    P() {}
    P(double _x, double _y): x(_x), y(_y) {}
    P turn(const double &m) const {
        double c = cos(m), s = sin(m);
        return P(x * c - y * s, x * s + y * c);
    }
    P set(const double &m) const {
        double len = get_length();
        return P(x * m / len, y * m / len);
    }
    double get_length() const {
        return sqrt(x * x + y * y);
    }
    double cross(const P &a, const P &b) const {
        return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
    }
};

vector<P> p, gs;

int random(int n) {
    return ((rand() << 15 | rand())) % n;
}

int range(int x1, int x2) {
    int n = x2 - x1 + 1;
    return random(n) + x1;
}

bool ok(const P &pt) {
    for (int i = 0; i < SZ(p); ++i) {
        for (int j = 0; j < i; ++j) {
            if (sgn(pt.cross(p[i], p[j])) == 0) return false;
        }
    }
    for (int i = 0; i < SZ(gs); ++i) {
        for (int j = 0; j < i; ++j) {
            if (sgn(pt.cross(gs[i], gs[j])) == 0) return false;
        }
    }
    for (int i = 0; i < SZ(p); ++i) {
        for (int j = 0; j < SZ(gs); ++j) {
            if (sgn(pt.cross(p[i], gs[j])) == 0) return false;
        }
    }
    return true;
}

int main() {
    srand(19900709);
    freopen("data.in", "w", stdout);
    int t = 5;
    while (t--) {
        int n = 100, m = 1000;
        printf("%d %d\n", n, m);
        p.resize(n);
        for (int i = 0; i < n; ++i) {
            double angle = pi * 2 / n * i;
            P pt = P(1, 0).turn(angle).set(100000);
            p[i] = P((int)pt.x, (int)pt.y);
            printf("%.0lf %.0lf\n", pt.x, pt.y);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < j; ++k) {
                    assert(sgn(p[i].cross(p[j], p[k])));
                }
            }
        }
        gs.clear();
        for (int i = 0; i < m; ++i) {
            P tmp = P(range(-100000, 100000), range(-100000, 100000));
            while (!ok(tmp)) {
                tmp = P(range(-100000, 100000), range(-100000, 100000));
            }
            gs.push_back(tmp);
            printf("%.0lf %.0lf\n", tmp.x, tmp.y);
        }
    }
    return 0;
}

