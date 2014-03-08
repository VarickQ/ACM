/*
 * Author:  xioumu
 * Created Time:  2012/8/15 23:23:00
 * File Name: duipai.cpp
 * solve: duipai.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<vector>
using namespace std;
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clr(x) memset(x,0,sizeof(x))
#define clrs( x , y ) memset(x,y,sizeof(x))
typedef long long lint;
const int maxint = -1u>>1;
const double esp = 1e-8;
const int maxn = 1007;
vector<int> e[maxn];
int lc[maxn], rc[maxn];
int col[maxn], nowcol[maxn], n, m;
int f[maxn][10], v[maxn], mark, ans;
int two(int w){
    return 1 << w;
}
void add(int x, int y){
    e[x].push_back(y);
    e[y].push_back(x);
}
void getch(int w, int fa){
    rep(i, sz(e[w]))
        if(e[w][i] != fa){
            if(lc[w] < 0) lc[w] = e[w][i];
            else rc[w] = e[w][i];
            getch(e[w][i], w);
        }
}
void init(){
    repf(i, 1, n)
        e[i].clear();
    memset(lc, -1, sizeof(lc));
    memset(rc, -1, sizeof(rc));
    rep(i, n - 1){
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    repf(i, 1, n)
        scanf("%d", &col[i]);
    
    getch(1, -1);
    //repf(i, 1, n)
        //printf("%d ", col[i]);
    //printf("\n");
}
int gao(int t, int tast){
    int ct = nowcol[t];
    if(t < 0) return 0;
    if(f[t][tast] >= 0) return f[t][tast];
    rep(j, 2){
        if(j == ct)
            f[t][j] = gao(lc[t], j) + gao(rc[t], j);
        else f[t][j] = gao(lc[t], 1 - j) + gao(rc[t], 1 - j) + 1;
    }
    f[t][0] = min(f[t][0], f[t][1] + 1);
    f[t][1] = min(f[t][1], f[t][0] + 1);
    //if(mark == 0){
        //printf("%d : %d %d : %d\n", t, f[t][0], f[t][1], nowcol[t]);
    //}
    return f[t][tast];
}
bool get_mark(int w){
    return (mark & two(w - 1) ) != 0;
}

int gao2(int t){
    int cost = 0;
    if(t < 0) return 0;
    int h1 = gao2(lc[t]);
    int h2 = gao2(rc[t]);
    v[t] = 0;
    if( get_mark(t) ) {
        if( get_mark(lc[t]) == 1 && get_mark(rc[t]) == 1) {
            if(v[ lc[t] ] && v[ rc[t] ])
                cost = 1;
            else if(!v[ lc[t] ] && !v[ rc[t] ]){
                v[t] = 1;
                cost = -1;
            }
        }
        else if(get_mark(lc[t]) || get_mark(rc[t]) ){
            int ch;
            if( get_mark(lc[t]) ) ch = lc[t];
            else ch = rc[t];
            if(v[ch])
                cost = 1;
        }
        else cost = 1;
    }
    return h1 + h2 + cost;
}
int main(){
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    while(scanf("%d", &n) != EOF){
        init();
        ans = maxint;
        for(mark = 0; mark < two(n); mark++){
            memcpy(nowcol, col, sizeof(col));
            repf(i, 1, n)
                if(two(i - 1) & mark)
                    nowcol[i] = 1 - nowcol[i];
            memset(f, -1, sizeof(f));
            ans = min(gao(1, 0) + gao2(1), ans);
            ans = min(gao(1, 1) + gao2(1), ans);
            //printf("%d : %d\n", mark, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
